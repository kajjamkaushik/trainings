#include <gtest/gtest.h>
#include"math_utils.h"
// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
	EXPECT_STRNE("hello", "world");  // Should pass
	EXPECT_EQ(7 * 6, 42);            // Should pass
}

// Test for addition function
TEST(AddTest, HandlesPositiveNumbers)
{
	EXPECT_EQ(Add(3, 4), 7);
}
//Test-2:
// Test for Factorial function 
TEST(FactorialTest, HandlesBasesCases)
{
	EXPECT_EQ(Factorial(0), 1);
	EXPECT_EQ(Factorial(1), 1);
}
TEST(FactorialTest, HandlesPositiveInput)
{
	EXPECT_EQ(Factorial(5), 120);
	EXPECT_EQ(Factorial(7), 5040);
}
TEST(FactorialTest, HandlesNegativeInput)
{
	EXPECT_EQ(Factorial(-5),1);
}
//test-3
TEST(PrimeNumberTest, DetectsPrimeOrNot)
{
	EXPECT_TRUE(isPrime(7));
	EXPECT_TRUE(isPrime(13));
	EXPECT_FALSE(isPrime(9));
}
//TEST-4 Divide
TEST(divideTest, ReturnCrctQuotient)
{
	EXPECT_DOUBLE_EQ(divide(10.0, 2.0), 5.0);
}
TEST(divideTest, ThrowsOnZeroDivision)
{
	EXPECT_THROW(divide(5.0,0.0), std::invalid_argument);
}
TEST(DivideTest, HandlesFloatingPointPrecision) {
	EXPECT_NEAR(divide(10.0, 3.0), 3.3333, 0.0001);
}


// Test GCD - normal values
TEST(GCDTest, HandlesPositiveInput) {
	EXPECT_EQ(gcd(48, 18), 6);
	EXPECT_EQ(gcd(100, 25), 25);
}

// Test GCD - one value zero
TEST(GCDTest, HandlesZeroInput) {
	EXPECT_EQ(gcd(0, 7), 7);
	EXPECT_EQ(gcd(9, 0), 9);
}

// Test GCD - both zero (undefined behavior, define result or skip)
TEST(GCDTest, BothZeroReturnsZero) {
	EXPECT_EQ(gcd(0, 0), 0);  // Optional: depends on your design
}

// Test LCM - normal values
TEST(LCMTest, HandlesPositiveInput) {
	EXPECT_EQ(lcm(4, 5), 20);
	EXPECT_EQ(lcm(6, 8), 24);
}

// Test LCM - zero input
TEST(LCMTest, HandlesZeroInput) {
	EXPECT_EQ(lcm(0, 7), 0);
	EXPECT_EQ(lcm(9, 0), 0);
}

// Test LCM - lcm of same numbers
TEST(LCMTest, HandlesSameInput) {
	EXPECT_EQ(lcm(7, 7), 7);
}


