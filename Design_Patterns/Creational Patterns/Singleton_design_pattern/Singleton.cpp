#include<iostream>
#include<string>
#include<mutex>
using namespace std;
class Database
{
private:
	static Database* instance;
	static std::mutex mutex;
	Database() {
		std::cout << "Database initialized: Connection established" << std::endl;
	} // Private constructor to prevent instantiation
	Database(const Database&) = delete; // Prevent copy constructor
	Database& operator=(const Database&) = delete; // Prevent assignment operator
public:
	// Static method to get the singleton instance
	static Database* getInstance() {
		if (instance == nullptr) {
			// Double-checked locking pattern
			std::lock_guard<std::mutex> lock(mutex);
			if (instance == nullptr) {
				instance = new Database();
			}
		}
		return instance;
	}
	void query(string sql)
	{
		cout<<"Query result for: "<<sql<<std::endl;
	}
	~Database() {
		std::cout << "Database destroyed: Connection closed" << std::endl;
	}
};
Database* Database::instance = nullptr;
std::mutex Database::mutex;
class Application
{
public:
	static void main()
	{
		// Get the database instance
		Database* foo = Database::getInstance();
		foo->query("SELECT * FROM users");

		// Get the database instance again (will be the same instance)
		Database* bar = Database::getInstance();
		bar->query("SELECT * FROM products");

		// Demonstrate that foo and bar point to the same object
		std::cout << "Are foo and bar the same instance? "
			<< (foo == bar ? "Yes" : "No") << std::endl;
	}
};
int main()
{
	Application::main();
	return 0;
}
//output:
//Database initialized : Connection established
//Query result for : SELECT * FROM users
// Query result for : SELECT * FROM products
// Are foo and bar the same instance ? Yes