#include <iostream>
#include <vector>

using namespace std;

/*
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/comments/
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int nBeginIndex = 0;
        int nEndIndex = nums.size() - 1;
        return binarySearchMin(nums, nBeginIndex, nEndIndex);
    }

protected:
    int binarySearchMin(const vector<int>& nums, int& nBeginIndex, int& nEndIndex)
    {
        if ((nBeginIndex == nEndIndex) || (nums[nEndIndex] > nums[nBeginIndex]))
        {   //或后面是为了防止出现递增的情况
            return nums[nBeginIndex];
        }

        bool bIsBeginSideEqual = false, bIsEndSideEqual = false;
        int nMidIndex = nBeginIndex + (nEndIndex - nBeginIndex) / 2;

        while ((nums[nBeginIndex] == nums[nMidIndex]) && (nBeginIndex != nEndIndex))
        {   //begin可以到当前重复元素的下一个元素
            ++nBeginIndex;
            bIsBeginSideEqual = true;
        }
        while ((nums[nEndIndex] == nums[nMidIndex]) && (nBeginIndex != nEndIndex))
        {   
            --nEndIndex;
            bIsEndSideEqual = true;
        }
        if (bIsBeginSideEqual || bIsEndSideEqual)
        {
            //end不能到当前重复元素的上一个元素，只能到当前重复元素的开始位置
            nEndIndex = bIsEndSideEqual ? nEndIndex + 1 : nEndIndex;
            return binarySearchMin(nums, nBeginIndex, nEndIndex);
        }

        if (nums[nBeginIndex] < nums[nMidIndex])
        {
            //begin可以到mid的下一个元素
            nBeginIndex = nMidIndex + 1;
        }
        else
        {
            //end只能到mid
            nEndIndex = nMidIndex;
        }
        return binarySearchMin(nums, nBeginIndex, nEndIndex);
    }
};




