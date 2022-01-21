#include <iostream>
#include <vector>

using namespace std;

/*
 * https://leetcode-cn.com/problems/maximum-sum-circular-subarray/
 *
 *  1. 若最大没跨过数组两端：dpMax[i] = std::max(dpMax[i - 1] + A[i], A[i]);
 *  2. 若最大跨过了数组两端：dpMin[i] = std::min(dpMin[i - 1] + A[i], A[i]);
 *      最大：若dpMin一直走左边的分支，则取A数组的max；否则，是 Sum - 最小值
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int nSize = nums.size();
        vector<int> dpMax; dpMax.resize(nSize);
        vector<int> dpMin; dpMin.resize(nSize);
        dpMax[0] = nums[0];
        dpMin[0] = nums[0];
        bool bAlwaysLeftCond = true;
        int nNumMax = nums[0];
        int nNumSum = nums[0];
        int nDpMax = nums[0];
        int nDpMin = nums[0];

        for (int i = 1; i < nSize; ++i)
        {
            dpMax[i] = std::max(dpMax[i - 1] + nums[i], nums[i]);
            if (dpMin[i - 1] < 0)
            {
                dpMin[i] = dpMin[i - 1] + nums[i];
            }
            else
            {
                dpMin[i] = nums[i];
                bAlwaysLeftCond = false;
            }
            nNumMax = std::max(nNumMax, nums[i]);
            nNumSum += nums[i];
            nDpMax = std::max(nDpMax, dpMax[i]);
            nDpMin = std::min(nDpMin, dpMin[i]);
        }
        
        int nRet = bAlwaysLeftCond ? nNumMax : nNumSum - nDpMin;
        nRet = std::max(nRet, nDpMax);
        return nRet;
    }
};


