#include <iostream>
#include <vector>

using namespace std;

/*
 * https://leetcode-cn.com/problems/ones-and-zeroes/submissions/
 * 
 * 1. 思路类似背包问题
 * 2. 假设dp[i][j][k]表示轮到第i个数，且最多能有j个0，k个1时，能放的最大的字符串数量，则有：
 *      dp[i][j][k] = std::max(dp[i - 1][j][k], dp[i - 1][j - 第i个串的0的数目][k - 第i个串的1的数目] + 1)
*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        doInit(strs, m, n);
        genDp();
        return m_dp.back().back().back();
    }

protected:
    void doInit(const vector<string>& strs, int m, int n)
    {
        m_dp.resize(strs.size());
        for (auto& vec1 : m_dp)
        {
            vec1.resize(m + 1);
            for (auto& vec2 : vec1)
            {
                vec2.resize(n + 1);
            }
        }

        m_strsInfo.resize(strs.size());
        for (int i = 0; i < strs.size(); ++i)
        {
            auto strInfo = getStrInfo(strs[i]);
            m_strsInfo[i] = strInfo;
        }
    }

    void genDp()
    {
        for (int i = 0; i < m_dp.size(); ++i)
        {
            int nZeroCount = m_strsInfo[i].first;
            int nOneCount = m_strsInfo[i].second;
            for (int j = 0; j < m_dp[0].size(); ++j)
            {
                for (int k = 0; k < m_dp[0][0].size(); ++k)
                {
                    if ((j < nZeroCount) || (k < nOneCount))
                    {
                        m_dp[i][j][k] = (i ==0) ?  0 : m_dp[i - 1][j][k];
                    }
                    else
                    {
                        m_dp[i][j][k] = std::max(i == 0 ? 0 : m_dp[i - 1][j][k], (i == 0 ? 0 : m_dp[i - 1][j - nZeroCount][k - nOneCount]) + 1);
                
                    }
                }
            }
        }
    }

    std::pair<int, int> getStrInfo(const string& str)
    {
        int nZeroCount = 0;
        int nOneCount = 0;
        for (auto c : str)
        {
            nZeroCount += (c == '0' ? 1 : 0);
            nOneCount += (c == '1' ? 1 : 0);
        }
        return std::make_pair(nZeroCount, nOneCount);
    }

protected:
    vector<vector<vector<int>>> m_dp;
    vector<std::pair<int, int>> m_strsInfo;
};

int main()
{
    vector<string> strs { "10", "0001", "111001", "1", "0" };
    std::cout << Solution().findMaxForm(strs, 5, 3) << std::endl;

    // vector<string> strs { "10", "0", "1" };
    // std::cout << Solution().findMaxForm(strs, 1, 1) << std::endl;

    return 0;
}