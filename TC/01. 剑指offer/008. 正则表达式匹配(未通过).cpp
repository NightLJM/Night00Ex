#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

/*
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配

数据范围:
1.str 可能为空，且只包含从 a-z 的小写字母。
2.pattern 可能为空，且只包含从 a-z 的小写字母以及字符 . 和 *，无连续的 '*'。
3.1 <= str.length <= 20
4.1 <= pattern.length <= 30
5. '.'后面可以接'*'
要求：空间复杂度 O(1)O(1)，时间复杂度 O(n)O(n)
*/

/*
使用动态规划处理：对于str的第i个字符和pattern的第j个字符，有以下几种情况：

1. str[i] == pattern[j]：
    1. pattern[j + 1] != '*' :         dp[i][j] = dp[i + 1][j + 1];
    2. pattern[j + 1] == '*' : 一次：   dp[i][j] = isCrossBoder(i, j + 2) || dp[i + 1][j + 2];
                             : 多次：   dp[i][j] = (str[i + 1] == str[i]) && dp[i + 1][j];      
                             : 零次：   dp[i][j] = dp[i][j + 2];    

2. pattern[j] == '.' :
    1. pattern[j + 1] != '*' :         dp[i][j] = dp[i + 1][j + 1];
    2. pattern[j + 1] == '*' : 一次：   dp[i][j] = dp[i + 1][j + 2];
                             : 多次：   dp[i][j] = (str[i + 1] == str[i]) && dp[i + 1][j];      
                             : 零次：   dp[i][j] = dp[i][j + 2];   

3. str[i] != pattern[j]:
    1. pattern[j + 1] != '*' :         dp[i][j] = pattern[j] == '*' ?  dp[i][j + 1] : false
    2. pattern[j + 1] == '*' : 零次：   dp[i][j] = dp[i][j + 2];   
*/

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @param pattern string字符串 
     * @return bool布尔型
     */
    bool match(const string& str, const string& pattern) {
        int i_max = str.size();
        int j_max = pattern.size();

        if (j_max == 0)
        {
            return i_max == 0;
        }
        if (pattern[0] == '*')
        {
            return false;
        }
        auto isMatchWhenStrIsEmpty = [](const string& str, const string& pattern) -> bool
        {
            int i_max = str.size();
            int j_max = pattern.size();
            for (int j = 0; j < j_max; ++j)
            {
                if (pattern[j] == '*')
                {
                    continue;
                }
                if ((j + 1 >= j_max) || pattern[j + 1] != '*')
                {
                    return false;
                }
                j += 2;
            }
            return true;
        };
        if (i_max == 0)
        {
            return isMatchWhenStrIsEmpty(str, pattern);
        }

        //0. 检查是否越界
        auto isCrossBoder = [&](int i, int j) -> bool
        {
            return !((i < i_max) && (j < j_max));
        };

        //1. 初始化数组大小
        dp.resize(i_max);
        for (vector<bool>& tmpVec : dp)
        {
            tmpVec.resize(j_max);
        }

        //2. 动态规划
        for (int i = i_max - 1; i >= 0; --i)
        {
            for (int j = j_max - 1; j >=0; --j)
            {
                if ((str[i] == pattern[j]) || (pattern[j] == '.'))
                {
                    if (isCrossBoder(i + 1, j))
                    {
                        dp[i][j] = isCrossBoder(i, j + 1) || isMatchWhenStrIsEmpty("", pattern.substr(j + 1, j_max - j));
                    }
                    else if (isCrossBoder(i, j + 1) || pattern[j + 1] != '*')
                    {
                        dp[i][j] =(isCrossBoder(i, j + 1) && isCrossBoder(i + 1, j)) || (!isCrossBoder(i + 1, j + 1) && dp[i + 1][j + 1]);
                    }
                    else
                    {
                        dp[i][j] = isCrossBoder(i, j + 2) || (!isCrossBoder(i + 1, j + 2) && dp[i + 1][j + 2])
                                || (!isCrossBoder(i + 1, j) && (str[i + 1] == str[i]) && dp[i + 1][j])
                                || (!isCrossBoder(i, j + 2) && dp[i][j + 2]);
                    }
                }
                else
                {
                    if (isCrossBoder(i, j + 1) || pattern[j + 1] != '*')
                    {
                        dp[i][j] = pattern[j] == '*' ?  !isCrossBoder(i, j + 1) && dp[i][j + 1] : false;
                    }
                    else
                    {
                        dp[i][j] = !isCrossBoder(i, j + 2) && dp[i][j + 2]; 
                    }
                }
            }
        }


        return dp[0][0];
    }

private:
    vector<vector<bool>> dp;
};



TEST(SolutionSuit, SolutionCase)
{
    struct TestParm
    {
        vector<string> strVec;
        vector<string> patternVec;
        vector<bool>   expectRes;
        int getSize() { return strVec.size(); }
        string getStr(int i) { return strVec[i]; }
        string getPattern(int i) { return patternVec[i]; }
        bool getExpectRes(int i) { return expectRes[i]; }
    };
    TestParm testParm;
    {
        testParm.strVec.push_back("aaa");testParm.patternVec.push_back("a*a");testParm.expectRes.push_back(true);
        testParm.strVec.push_back("aad");testParm.patternVec.push_back("c*a*d");testParm.expectRes.push_back(true);
        testParm.strVec.push_back("");testParm.patternVec.push_back(".*");testParm.expectRes.push_back(true);
        testParm.strVec.push_back("aaab");testParm.patternVec.push_back("a*a*a*c");testParm.expectRes.push_back(false);
        testParm.strVec.push_back("a");testParm.patternVec.push_back("ab*");testParm.expectRes.push_back(true);
        testParm.strVec.push_back("a");testParm.patternVec.push_back(".*");testParm.expectRes.push_back(true);
    }

    for (int i = 0; i < testParm.getSize(); ++i)
    {
        bool res = Solution().match(testParm.getStr(i), testParm.getPattern(i));
        EXPECT_TRUE(res == testParm.getExpectRes(i)) << "i == " << i << "\n";
    }
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



