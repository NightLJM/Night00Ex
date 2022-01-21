#include <iostream>
#include <vector>

using namespace std;

/*
 * https://leetcode-cn.com/problems/check-if-array-pairs-are-divisible-by-k/
*/

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        genVec(arr, k);
        return check();
    }

protected:
    void genVec(const vector<int>& arr, int k)
    {
        m_vec.resize(k, 0);
        for (auto val : arr)
        {
            int index = val % k;
            index += (index < 0 ? k : 0);
            m_vec[index] += 1;
        }
    }

    bool check()
    {
        int k = m_vec.size();
        //是否中间的不满足条件；当k是偶数时，中间的那个一定要是偶数
        bool bMidInvalid = (k % 2 == 0 ? (m_vec[k / 2] % 2 == 1) : false);

        if (bMidInvalid || (m_vec[0] % 2 == 1))
        {
            return false;
        }

        for (int i = 1; i <= k / 2; ++i)
        {
            if (m_vec[i] != m_vec[k - i])
            {
                return false;
            }
        }
        return true;

    }

protected:
    vector<int> m_vec;
};

int main()
{
    vector<int> arr {-1, -1, -1, -1, 2, 2, -2, -2};
    std::cout << Solution().canArrange(arr, 3) << std::endl;

    return 0;
}



