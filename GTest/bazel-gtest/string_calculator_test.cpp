// string_calculator_test.cpp
#include <gtest/gtest.h>
#include "string_calculator.h"

// Tests will go here
//test for 2 numbers
TEST(StringCalculatorTest, TwoNumbersReturnSum) {
    EXPECT_EQ(3, add("1,2"));
    EXPECT_EQ(10, add("7,3"));
}

///test for multiple numbers
TEST(StringCalculatorTest, MultipleNumbersReturnSum) {
    EXPECT_EQ(6, add("1,2,3"));
    EXPECT_EQ(15, add("1,2,3,4,5"));
}

// Test for empty string
TEST(StringCalculatorTest, EmptyStringReturnsZero) {
    EXPECT_EQ(0, add(""));
}

// Test for single number
TEST(StringCalculatorTest, SingleNumberReturnsValue) {
    EXPECT_EQ(1, add("1"));
    EXPECT_EQ(5, add("5"));
}

// Test for handling invalid input
TEST(StringCalculatorTest, InvalidInputHandling) {
    EXPECT_EQ(3, add("1,2,"));
    EXPECT_EQ(3, add("1,2,x"));
}