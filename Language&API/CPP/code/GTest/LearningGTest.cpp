#include <iostream>
#include "gtest/gtest.h"

TEST(Test_A, Test_A_1)
{
    EXPECT_TRUE(false) << "TEST_A_1 Error 1" << std::endl;
    std::cout << 111 << std::endl;
    ASSERT_FALSE(false) << "TEST_A_1 Error 2" << std::endl;
}

TEST(Test_A, Test_A_2)
{
    ASSERT_TRUE(false) << "ERR1" << std::endl;
    std::cout << 111 << std::endl;
    ASSERT_FALSE(false) << "ERR2" << std::endl;
}
