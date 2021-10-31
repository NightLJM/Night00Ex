#include <vector>

/*
描述
有一个长度为 n 的非降序数组，比如[1,2,3,4,5]，将它进行旋转，即把一个数组最开始的若干个元素搬到数组的末尾，变成一个旋转数组，比如变成了[3,4,5,1,2]，或者[4,5,1,2,3]这样的。请问，给定这样一个旋转数组，求数组中的最小值。

数据范围：1 \le n \le 100001≤n≤10000，数组中任意元素的值: 0 \le val \le 100000≤val≤10000
要求：空间复杂度：O(1)O(1) ，时间复杂度：O(logn)O(logn)

https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=13&tqId=23269&ru=/practice/abc3fe2ce8e146608e868a70efebf62e&qru=/ta/coding-interviews/question-ranking
*/


class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() == 0)
        {
            return -1;
        }

        int nBeginIndex = 0;
        int nEndIndex = rotateArray.size() - 1;
        int nMidIndex;


        while (nBeginIndex < nEndIndex)
        {
            nMidIndex = nBeginIndex + (nEndIndex - nBeginIndex) / 2;
            int nBeginValue = rotateArray[nBeginIndex];
            int nMidValue = rotateArray[nMidIndex];
            int nEndValue = rotateArray[nEndIndex];
            if (nMidValue > nBeginValue && nMidValue > nEndValue)
            {
                nBeginIndex = nMidIndex + 1;
            }
            else if (nMidValue < nEndValue)
            {
                nEndIndex = nMidIndex;
            }
            else if (nMidValue == nBeginValue)    //这个else和上面一个else不能换位置
            {
                ++nBeginIndex;
            }
            else if (nMidValue == nEndValue)
            {
                --nEndIndex;
            }
        }

        return rotateArray[nEndIndex];
    }
};