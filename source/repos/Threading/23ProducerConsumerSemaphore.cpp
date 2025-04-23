//#include <iostream>
//#include <thread>
//#include <semaphore>
//#include <chrono>
//
//#define buff_size 5
//int buff[buff_size];
//
//std::binary_semaphore signal_to_producer(1); // Initially available for producer
//std::binary_semaphore signal_to_consumer(0); // Initially unavailable for consumer
//
//void producer() {
//    while (true) {
//        signal_to_producer.acquire();
//        std::cout << "Produced = ";
//        for (int i = 0; i < buff_size; ++i) {
//            buff[i] = i * i; // Producer fills buffer
//            std::cout << buff[i] << " " << std::flush;
//            std::this_thread::sleep_for(std::chrono::milliseconds(200));
//        }
//        std::cout << std::endl;
//        signal_to_consumer.release();
//    }
//}
//
//void consumer() {
//    while (true) {
//        signal_to_consumer.acquire();
//        std::cout << "Consumed = ";
//        for (int i = buff_size - 1; i >= 0; --i) {
//            std::cout << buff[i] << " " << std::flush;
//            buff[i] = 0; // Consumer empties buffer
//            std::this_thread::sleep_for(std::chrono::milliseconds(200));
//        }
//        std::cout << std::endl;
//        signal_to_producer.release();
//    }
//}
//
//int main() {  // Ensure this function is present
//    std::thread prod(producer);
//    std::thread cons(consumer);
//    prod.join();
//    cons.join();
//    return 0;
//}
//
//
///// output :
///*Produced = 0 1 4 9 16
//Consumed = 16 9 4 1 0
//Produced = 0 1 4 9 16
//Consumed = 16 9 4 1 0
//Produced = 0 1 4 9 16
//Consumed = 16 9 4 1 0
//Produced = 0 1 4 9 16
//Consumed = 16 9 4 1 0
//Produced = 0 1 4 9 16
//Consumed = 16 9 4 1 0
//Produced = 0 1 4 9 16
//Consumed = 16 9 4
//*/