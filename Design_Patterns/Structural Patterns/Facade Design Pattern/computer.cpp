#include<iostream>
using namespace std;
// Subsytem :1 Cpu
class CPU
{
public:
	void powerOn()
	{
		cout << "Cpu is Powered on" << endl;
	}
	void executeInstructions()
	{
		cout << "Cpu excutes the instrcutions" << endl;
	}
};
// Subsystem 2 :Memory
class Memory
{
public:
	void initialise()
	{
		cout << "Memory is beign initialised" << endl;
	}
};
// Subsystem 3 :Gpu
class Gpu
{
public:
	void enableGraphics()
	{
		cout << "Enabling Graphics using the GPu" << endl;
	}
};
/// Subsytem 4 :DiskDrive
class DiskDrive
{
public:
	void bootFromDisk()
	{
		cout << " Booting from the disk Drive" << endl;
	}
};
//Subsytem 5:
class NetworkInterface
{
public:
	void connectToNetwork()
	{
		cout << "Connected to the Network" << endl;
	}
};
class ComputerSystemFacade
{
private:
	CPU cpu;
	Memory memory;
	Gpu gpu;
	DiskDrive diskDrive;
	NetworkInterface networkInterface;
public:
	void startComputer()
	{
		cout << "Starting the computer" << endl;
		cpu.powerOn();
		memory.initialise();
		gpu.enableGraphics();
		diskDrive.bootFromDisk();
		networkInterface.connectToNetwork();
		cpu.executeInstructions();
		cout << "Computer is Ready to use" << endl;
	}
};
int main()
{
	ComputerSystemFacade computer; 
	// User initates the computer start 
	computer.startComputer();

}

//output:
//Starting the computer
//Cpu is Powered on
//Memory is beign initialised
//Enabling Graphics using the GPu
//Booting from the disk Drive
//Connected to the Network
//Cpu excutes the instrcutions
//Computer is Ready to use
// The Facade pattern provides a simplified interface to a complex system of classes