#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "gtest/gtest.h"
#include "001.MySort.h"

TEST(BubbleSortSuit, BubbleSortCase)
{
    std::vector<int> inputVec {5, 3, 2, 6, 7, 8, 10};
    std::vector<int> expectVec {2, 3, 5, 6, 7, 8, 10};

    std::string inputStr = "afa";
    std::string expectStr = "aaf";

    float inputArr[5] = {3.1, 6.2, 4.1, 2, 1};
    float expectArr[5] = {1, 2, 3.1, 4.1, 6.2};

    Night00::bubbleSort(inputVec.begin(), inputVec.end(), [](int a, int b) -> bool { return a < b; });
    Night00::bubbleSort(inputStr.begin(), inputStr.end(), [](char a, char b) -> bool { return a < b; });
    Night00::bubbleSort(inputArr, inputArr + 5, [](float a, float b) -> bool { return a < b; });

    EXPECT_TRUE(Night00::isEqual(inputVec.begin(), inputVec.end(), expectVec.begin(), expectVec.end()));
    EXPECT_TRUE(Night00::isEqual(inputStr.begin(), inputStr.end(), expectStr.begin(), expectStr.end()));
    EXPECT_TRUE(Night00::isEqual(inputArr, inputArr + 5, expectArr, expectArr + 5));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}








