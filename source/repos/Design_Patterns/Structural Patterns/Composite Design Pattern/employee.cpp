#include<iostream>
#include<string>
#include<vector>
using namespace std;
class EmployeeComponent
{
public:
	virtual void displayInfo() = 0;
	virtual double calculateSalary() = 0;
	virtual ~EmployeeComponent() {}
};
class Employee :public EmployeeComponent{
private:
	string name;
	double salary;
public:
	Employee(string name, double salary) : name(name), salary(salary) {}
	void displayInfo() override {
		cout << "Employee Name: " << name << endl;
		cout << "Salary: " << salary << endl;
	}
	double calculateSalary() override{
		return salary;
	}
};
class Department :public EmployeeComponent
{
private :
	string name;
	vector<EmployeeComponent*> members;
public:
	Department(string Deptname):name(Deptname){}
	void addMember(EmployeeComponent* member)
	{
		members.push_back(member);
	}
	void displayInfo() override
	{
		cout << "Department: " << name << endl;
		for (auto& member : members)
		{
			member->displayInfo();
		}
	}
	double calculateSalary() override
	{
		double total_salary = 0;
		for (auto& member : members)
		{
			total_salary += member->calculateSalary();
		}
		return total_salary;
	}
	~Department()
	{

	}
};
class Team :public EmployeeComponent
{
private:
	string name;
	vector<EmployeeComponent*> members;
public:
	Team(string teamName) : name(teamName) {}

	void addMember(EmployeeComponent* member) {
		members.push_back(member);
	}
	void displayInfo() override{
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "Team: " << name << endl;
		for (auto& member : members) {
			member->displayInfo();
		}
	}
	double calculateSalary()override {
		double totalSalary = 0;
		for (auto& member : members) {
			totalSalary += member->calculateSalary();
		}
		return totalSalary;
	}
	~Team()
	{

	}
};
int main()
{

	Employee* keerti = new Employee("Keerti", 50000);
	Employee* shivani = new Employee("Shivani", 60000);
	Team* sales = new Team("Sales");
	sales->addMember(keerti);
	sales->addMember(shivani);
	Employee* bob = new Employee("Bob", 7000);
	Team* marketing = new Team("Marketing");
	marketing->addMember(bob);

	Department* headOffice = new Department("Head Office");
	headOffice->addMember(sales);
	headOffice->addMember(marketing);

	//display and calculate the total salary for the organization hierarchy
	headOffice->displayInfo();
	double totalsalary = headOffice->calculateSalary();
	cout << "Total Salary for the organization is : Rs" << totalsalary << endl;

	// Clean up memory (consider using smart pointers in a real application)
	delete keerti;
	delete shivani;
	delete sales;
	delete bob;
	delete marketing;
	delete headOffice;
	return 0;
}

//output:
//Department: Head Office
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ +
//Team : Sales
//Employee Name : Keerti
//Salary : 50000
//Employee Name : Shivani
//Salary : 60000
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ +
//Team : Marketing
//Employee Name : Bob
//Salary : 7000
//Total Salary for the organization is : Rs117000
