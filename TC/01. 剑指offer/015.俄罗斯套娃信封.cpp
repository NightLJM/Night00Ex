#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*
 * https://leetcode-cn.com/problems/russian-doll-envelopes/
*/

struct Node{
    Node(int nWidth, int nHigh)
    : m_nWidth(nWidth), m_nHigh(nHigh) {}
    int m_nWidth;
    int m_nHigh;
};

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        doInitEnveVec(envelopes);

        vector<int> minHighVec;
        minHighVec.push_back(m_highVec[0].front());
        for (int i = 1; i < m_highVec.size(); ++i)
        {
            auto iter1 = upper_bound(m_highVec[i].begin(), m_highVec[i].end(), minHighVec.back());
            if (iter1 == m_highVec[i].end())
            {   //m_highVec[i] 里的信封高度都比minHighVec.back() 小或等
                for (int j = m_highVec[i].size() - 1; j >= 0; --j)  
                {   //从后往前遍历，从小往大遍历的话会出问题
                    //例如 minHighVec： 100 200            m_highVec[i]: 150 180 
                    //从小到大遍历的话，minHighVec就会变成 100 150 180，而180是装不下150的，它俩的宽度相同
                    //从大向小遍历就能使得对于遍历m_highVec[i][j]的时候， minHighVec里比 m_highVec[i][j] 小的信封其宽度也一定比 m_highVec[i][j] 小
                    auto iter2 = lower_bound(minHighVec.begin(), minHighVec.end(), m_highVec[i][j]);    //一定能在minHighVec找到比m_highVec[i][j]大或等的
                    *iter2 = m_highVec[i][j];
                }
            }
            else
            {   // *iter1 刚好比minHighVec.back()大，则将 *iter1 放在minHighVec末尾，之后对 iter1 前面的信封执行上面分支一样的操作
                minHighVec.push_back(*iter1);
                while(iter1 != m_highVec[i].begin())
                {
                    --iter1;
                    auto iter2 = lower_bound(minHighVec.begin(), minHighVec.end(), *iter1);    //一定能在minHighVec找到比*iter1大或等的
                    *iter2 = *iter1;
                }
            }
        }
        
        return minHighVec.size();
    }

protected:
    void doInitEnveVec(const vector<vector<int>>& envelopes)
    {
        int nSize = envelopes.size();
        m_enveVec.resize(nSize);
        for (int i = 0; i < nSize; ++i)
        {
            int nWidth = envelopes[i][0];
            int nHigh = envelopes[i][1];
            Node* pNode = new Node(nWidth, nHigh);
            m_enveVec[i] = pNode;
        }

        //现将信封按照width从小到达排序， width相同的按照high从小到大排序
        std::sort(m_enveVec.begin(), m_enveVec.end(), [](Node* p1, Node* p2) -> bool
        {
            if (p1 == nullptr || p2 == nullptr)
            {
                return true;
            }
            if (p1->m_nWidth < p2->m_nWidth)
            {
                return true;
            }
            else if(p1->m_nWidth > p2->m_nWidth)
            {
                return false;
            }
            else if (p1->m_nHigh < p2->m_nHigh)
            {
                return true;
            }
            return false;
        });

        //m_highVec 里面保存各个不同宽度的信封的长度
        int nCurWidth = -1;
        for(auto iter = m_enveVec.begin(); iter != m_enveVec.end(); ++iter)
        {
            if ((*iter)->m_nWidth != nCurWidth)
            {
                m_highVec.push_back(vector<int>());
                nCurWidth = (*iter)->m_nWidth;
            }
            m_highVec.back().push_back((*iter)->m_nHigh);
        }
    }

protected:
    vector<Node*> m_enveVec;
    vector<vector<int>> m_highVec;
};

int main()
{
    vector<vector<int>> input = {{16, 1}, {6, 9}, {16, 12}, {8, 7}, {18, 16}, {8, 10}, {13, 19}, {16, 7},
        {7, 20}, {13, 6}, {9, 11}, {10, 13}, {15, 19}, {8, 11}};

    int nRet = Solution().maxEnvelopes(input);

    return 0;
}