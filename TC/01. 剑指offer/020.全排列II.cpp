#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * https://leetcode-cn.com/problems/permutations-ii/
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(const vector<int>& nums) {
        vector<int> inputNums = nums;
        std::sort(inputNums.begin(), inputNums.end());
        genRes(vector<int>(), inputNums);
        return m_Res;
    }

    void genRes(const vector<int>& res, const vector<int>& inputNums)
    {
        if (inputNums.size() == 0)
        {
            m_Res.push_back(res);
            return;
        }

        int nPreNum = -11;
        for (int i = 0; i < inputNums.size(); ++i)
        {
            if (inputNums[i] == nPreNum)
            {
                //此处剪枝
                continue;
            }

            nPreNum = inputNums[i];
            vector<int> tmpRes = res;
            tmpRes.push_back(inputNums[i]);
            vector<int> tmpInputNums = inputNums;
            tmpInputNums.erase(tmpInputNums.begin() + i);
            genRes(tmpRes, tmpInputNums);
        }
    }

protected:
    vector<vector<int>> m_Res;
};