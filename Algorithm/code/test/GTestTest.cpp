#include <iostream>
#include "gtest/gtest.h"

TEST(Test1, Test1_1)
{
    EXPECT_EQ(1, 1);
    ASSERT_EQ(1, 0);
}

// int main(int argc, char **argv)
// {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }