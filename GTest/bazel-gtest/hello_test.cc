#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
	EXPECT_STRNE("hello", "world");  // Should pass
	EXPECT_EQ(7 * 6, 42);            // Should pass
}
