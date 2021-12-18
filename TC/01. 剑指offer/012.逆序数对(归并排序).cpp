#include <iostream>
#include <vector>
using namespace std;

/*
https://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5?tpId=13&tqId=23260&ru=/practice/72a5a919508a4251859fb2cfb987a0e6&qru=/ta/coding-interviews/question-ranking
*/

/*
归并排序

*/

class Solution {
public:
    int InversePairs(vector<int> data) {
        m_cacheVec.resize(data.size());
        mergeSort(data, 0, data.size());
        return m_inversePairsCount;
    }

protected:
    void mergeSort(vector<int>& data, int begin, int end)
    {
        if (end - begin < 2)
        {
            return ;
        }

        int mid = begin + (end - begin)/2;
        mergeSort(data, begin, mid);
        mergeSort(data, mid, end);
        merge(data, begin, mid, end);
    }

    void merge(vector<int>& data, int begin, int mid, int end)
    {
        int nLeftIndex = begin;
        int nRightIndex = mid;
        int nTmpPairCount = 0;
        int i = begin;
        for (; i < end && nLeftIndex < mid && nRightIndex < end; ++i)
        {
            bool sign = data[nLeftIndex] <= data[nRightIndex];
            switch(sign)
            {
            case true:  //左边小于等于右边
                m_cacheVec[i] = data[nLeftIndex];
                ++nLeftIndex;
                m_inversePairsCount += nTmpPairCount;
                m_inversePairsCount %= m_mod;
                break;
            case false: //左边大于右边
                m_cacheVec[i] = data[nRightIndex];
                ++nRightIndex;
                ++nTmpPairCount;
                break;
            default:
                break;
            }
        }
        if (nLeftIndex == mid)
        {   //左边没了，右边剩余的都是比左边大或等的
            copy(m_cacheVec, i, data, nRightIndex, end);
        }
        else
        {   //右边没了，左边剩余的都是比左边大的
            copy(m_cacheVec, i, data, nLeftIndex, mid);
            m_inversePairsCount += nTmpPairCount*(mid - nLeftIndex);
            m_inversePairsCount %= m_mod;
        }

        copy(data, begin, m_cacheVec, begin, end);
    }

    void copy(vector<int>& des, int desBegin, const vector<int>& src, int srcBegin, int srcEnd)
    {
        int length = srcEnd - srcBegin;
        //assert(desBegin + length <= des.size());
        int desIndex = desBegin;
        for (int i = srcBegin; i < srcEnd; ++i)
        {
            des[desIndex] = src[i];
            ++desIndex;
        }
    }

private:
    vector<int> m_cacheVec;
    int m_inversePairsCount = 0;
    int m_mod = 1000000007;
};



int main()
{
    vector<int> t {1, 2, 0};
    int ret = Solution().InversePairs(t);
    int ss = ret;
    return 0;
}
