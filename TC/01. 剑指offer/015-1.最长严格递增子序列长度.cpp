#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode-soluti/
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> vec;

        for (const auto& num : nums)
        {
            auto iter = lower_bound(vec.begin(), vec.end(), num);
            if (iter == vec.end())
            {
                vec.push_back(num);
            }
            else if(*iter != num)
            {
                *iter = num;
            }
        }
        
        return vec.size();
    }
};