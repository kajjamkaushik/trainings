#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <vector>
#include <string>
#include <atomic>

// Buffer size for reading/writing chunks
constexpr size_t BUFFER_SIZE = 64 * 1024; // 64KB chunks

// Thread-safe queue for passing data between threads
class ThreadSafeQueue {
private:
    std::queue<std::vector<char>> queue;
    std::mutex mutex;
    std::condition_variable not_empty;
    std::condition_variable not_full;
    size_t max_size;
    std::atomic<bool> done{ false };

public:
    explicit ThreadSafeQueue(size_t max_size = 10) : max_size(max_size) {}

    void push(std::vector<char>&& data) {
        std::unique_lock<std::mutex> lock(mutex);
        // Wait until queue has space or we're done
        not_full.wait(lock, [this] { return queue.size() < max_size || done; });
        if (done) return;

        queue.push(std::move(data));
        lock.unlock();
        not_empty.notify_one();
    }

    bool pop(std::vector<char>& data) {
        std::unique_lock<std::mutex> lock(mutex);
        // Wait until queue has data or we're done and queue is empty
        not_empty.wait(lock, [this] { return !queue.empty() || (done && queue.empty()); });

        if (queue.empty()) return false;

        data = std::move(queue.front());
        queue.pop();
        lock.unlock();
        not_full.notify_one();
        return true;
    }

    void set_done() {
        std::unique_lock<std::mutex> lock(mutex);
        done = true;
        lock.unlock();
        not_empty.notify_all();
        not_full.notify_all();
    }

    bool is_done() const {
        return done;
    }
};

// Function for the reader thread - now static
static void reader_thread(const std::string& source_file, ThreadSafeQueue& queue) {
    try {
        std::ifstream input(source_file, std::ios::binary);
        if (!input) {
            std::cerr << "Error: Could not open source file: " << source_file << std::endl;
            queue.set_done();
            return;
        }

        while (input) {
            std::vector<char> buffer(BUFFER_SIZE);
            input.read(buffer.data(), BUFFER_SIZE);
            std::streamsize bytes_read = input.gcount();

            if (bytes_read > 0) {
                // Resize buffer to actual bytes read
                buffer.resize(static_cast<size_t>(bytes_read));
                queue.push(std::move(buffer));
            }
        }

        // Signal that we're done reading
        queue.set_done();
        std::cout << "Reader thread finished" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error in reader thread: " << e.what() << std::endl;
        queue.set_done();
    }
}

// Function for the writer thread - now static
static void writer_thread(const std::string& target_file, ThreadSafeQueue& queue) {
    try {
        std::ofstream output(target_file, std::ios::binary);
        if (!output) {
            std::cerr << "Error: Could not open target file: " << target_file << std::endl;
            queue.set_done();
            return;
        }

        std::vector<char> buffer;
        while (queue.pop(buffer)) {
            output.write(buffer.data(), buffer.size());
            if (!output) {
                std::cerr << "Error: Failed to write to target file" << std::endl;
                break;
            }
        }

        output.close();
        std::cout << "Writer thread finished" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error in writer thread: " << e.what() << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <source_file> <target_file>" << std::endl;
        return 1;
    }

    std::string source_file = argv[1];
    std::string target_file = argv[2];

    // Create a thread-safe queue for passing data between threads
    ThreadSafeQueue queue;

    // Create reader and writer threads
    std::thread reader(reader_thread, source_file, std::ref(queue));
    std::thread writer(writer_thread, target_file, std::ref(queue));

    // Wait for both threads to finish
    reader.join();
    writer.join();

    std::cout << "File copy completed successfully!" << std::endl;
    return 0;
}