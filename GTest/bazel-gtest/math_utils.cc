#include "math_utils.h"
#include <stdexcept>
int Add(int a,int b)
{
	return a + b;
}
int Factorial(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * Factorial(n - 1);
}
bool isPrime(int n)
{
	if(n<=1)
		return false;
	for (int i = 2;i * i <= n;i++)
	{ if(n%i==0)
		return false;
	}
	return true;
}
double divide(double a,double b)
{
	if (b == 0)
	{
		throw std::invalid_argument("Division by zero is not allowed.");
	}
	return a / b;
}
int lcm(int a, int b)
{
	if (a == 0 || b == 0)
		return 0;
	int gcd = 1;
	for (int i = 1; i <= a && i <= b; ++i)
	{
		if (a % i == 0 && b % i == 0)
			gcd = i;
	}
	return (a * b) / gcd;
}
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}