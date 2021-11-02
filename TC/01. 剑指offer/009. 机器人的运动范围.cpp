#include <iostream>
#include <vector>
#include "gtest/gtest.h"

using namespace std;

/*
地上有一个 rows 行和 cols 列的方格。坐标从 [0,0] 到 [rows-1,cols-1] 。一个机器人从坐标 [0,0] 的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于 threshold 的格子。 例如，当 threshold 为 18 时，机器人能够进入方格   [35,37] ，因为 3+5+3+7 = 18。但是，它不能进入方格 [35,38] ，因为 3+5+3+8 = 19 。请问该机器人能够达到多少个格子？
1 <= rows,cols <= 100
0 <= threshold <= 15
*/

class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {
        m_nThreshold = threshold;
        m_nRows = rows;
        m_nCols = cols;
        m_nMovingCount = 0;
        m_Matrics.resize(rows);
        for (auto& vec : m_Matrics)
        {
            vec.resize(cols);
        }
        doInitNatrics();
        doMoveTo(0, 0);
        return m_nMovingCount;
    }

protected:
    void doMoveTo(int nXPos, int nYPos)
    {
        ++m_nMovingCount;
        m_Matrics[nXPos][nYPos] = -1;

        if ((nXPos + 1 < m_nRows) && (m_Matrics[nXPos + 1][nYPos] != -1) && (m_Matrics[nXPos + 1][nYPos] <= m_nThreshold))
        {
            doMoveTo(nXPos + 1, nYPos);
        }
        if ((nXPos - 1 >= 0) && (m_Matrics[nXPos - 1][nYPos] != -1) && (m_Matrics[nXPos - 1][nYPos] <= m_nThreshold))
        {
            doMoveTo(nXPos - 1, nYPos);
        }
        if ((nYPos + 1 < m_nCols) && (m_Matrics[nXPos][nYPos + 1] != -1) && (m_Matrics[nXPos][nYPos + 1] <= m_nThreshold))
        {
            doMoveTo(nXPos, nYPos + 1);
        }
        if ((nYPos - 1 >= 0) && (m_Matrics[nXPos][nYPos - 1] != -1) && (m_Matrics[nXPos][nYPos - 1] <= m_nThreshold))
        {
            doMoveTo(nXPos, nYPos - 1);
        }
    }
    void doInitNatrics()
    {
        for (int i = 0; i < m_Matrics.size(); ++i)
        {
            for (int j = 0; j < m_Matrics[i].size(); ++j)
            {
                m_Matrics[i][j] = getDigitalSum(i) + getDigitalSum(j);
            }
        }
    }
    int getDigitalSum(int num)
    {
        int nRet = 0;
        while(num > 0)
        {
            nRet += num%10;
            num /= 10;
        }

        return nRet;
    }
private:
    int m_nMovingCount;
    int m_nThreshold;
    int m_nRows;
    int m_nCols;
    vector<vector<int>> m_Matrics;
};

TEST(SolutionSuit, SolutionCase)
{
    EXPECT_EQ(3, Solution().movingCount(1, 2, 3));
    EXPECT_EQ(1, Solution().movingCount(0, 1, 3));
    EXPECT_EQ(29, Solution().movingCount(10, 1, 100));
    EXPECT_EQ(21, Solution().movingCount(5, 10, 10));
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}







