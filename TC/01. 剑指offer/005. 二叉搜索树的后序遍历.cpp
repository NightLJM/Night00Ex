#include <iostream>
#include <vector>
using namespace std;

/*
    输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则返回true,否则返回false。假设输入的数组的任意两个数字都互不相同。（ps：我们约定空树不是二叉搜索树）
*/

class Solution {
public:
    bool VerifySquenceOfBST(const vector<int>& sequence) {
        if (sequence.size() == 0)
        {
            return false;
        }
        
        return VerifySquenceOfBST(sequence, 0, sequence.size());
    }


protected:

    bool VerifySquenceOfBST(const vector<int>& sequence, int beginIndex, int endIndex)
    {
        if (endIndex >= beginIndex + 1)
        {
            return true;
        }

        int rootIndex = binaryFind(sequence, beginIndex, endIndex - 1, sequence[endIndex - 1]);
        if (rootIndex == -1)
        {
            return false;
        }

        return checkVectorLessThanValue(sequence, beginIndex, rootIndex, sequence[endIndex - 1])
            && checkVectorGreaterThanValue(sequence, rootIndex, endIndex - 1, sequence[endIndex - 1])
            && VerifySquenceOfBST(sequence, beginIndex, rootIndex)
            && VerifySquenceOfBST(sequence, rootIndex, endIndex - 1);
    }

    int binaryFind(const vector<int>& sequence, int beginIndex, int endIndex, int value)
    {
        int nLeftIndex = beginIndex;
        int nRightIndex = endIndex;
        while(nLeftIndex <= nRightIndex)
        {
            int retIndex = nLeftIndex + (nRightIndex - nLeftIndex)/2;
            if (retIndex == nLeftIndex)
            {
                return sequence[retIndex] < value ? retIndex + 1 : retIndex;
            }
            else if (nRightIndex == nLeftIndex + 1)
            {
                return nRightIndex;
            }
            
            if(sequence[retIndex] < value)
            {
                nLeftIndex = retIndex;
            }
            else
            {
                nRightIndex = retIndex;
            }
        }

        return -1;
    }

    bool checkVectorLessThanValue(const vector<int>& sequence, int beginIndex, int endIndex, int value)
    {
        if (beginIndex >= endIndex)
        {
            return true;
        }
        for (int i = beginIndex; i < endIndex; ++i)
        {
            if (sequence[i] >= value)
            {
                return false;
            }
        }
        return true;
    }
    bool checkVectorGreaterThanValue(const vector<int>& sequence, int beginIndex, int endIndex, int value)
    {
        if (beginIndex >= endIndex)
        {
            return true;
        }
        for (int i = beginIndex; i < endIndex; ++i)
        {
            if (sequence[i] <= value)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<int> t {7, 4, 6, 5};
    bool b = Solution().VerifySquenceOfBST(t);

    return 0;
}
