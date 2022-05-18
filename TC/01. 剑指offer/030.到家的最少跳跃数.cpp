#include <iostream>
#include <vector>
#include <deque>
#include <set>
using namespace std;

/*
 * https://leetcode-cn.com/problems/minimum-jumps-to-reach-home/
 *
 * 法1：(深度优先)
 * 0. 数组A，A[i]表示从0跳到i，且从i不能再往后跳的最小步数；数组B，B[i]表示从0跳到i，且从i可以往后跳的最小步数
 * 1. 假设当前位置是i：
 *      1. 若A[i] != -1;则说明只能往前跳，Jump(i, a, forward)
 *      2. 若B[i] != -1;则既能往前，又能往后：Jump(i, a, forward)  Jump(i, b , backward)
 * 2. 对于Jump：
 *      1. 若是向前跳，则修改B数组，若是向后跳，则修改A数组
 *      2. 若发现待修改的数组上，值比当前步数小，则截止，不能跳了，返回false
 *      3. 若发现待修改的数组上，值比当前步数大，则更新值，继续跳(这里有重复运算啊)
 * 3. 结束条件：
 *      1. 无法再跳。
 * 
 * 法2：(广度优先)
 * 0. 数组A，A[i]表示从0跳到i，且从i不能再往后跳的最小步数；数组B，B[i]表示从0跳到i，且从i可以往后跳的最小步数
 * 2. 定义一个Node {int curPos, enum enableDir， int curStep},和一个Node队列
 * 3. 初始时，队列里只有 Node { 0, bothDir , 0};然后模拟跳
 * 4. 结束条件，队列为空或已跳到终点
 * 
 * 
 * 还是看题解把，，，，
*/

enum Dir
{
    Both_Dir = 0, 
    Forward_Dir = 1
};

struct Node
{
    int m_nPos;
    Dir m_canDir;
    int m_nCurStep;
    Node(int nPos, Dir dir, int nCurStep) : m_nPos(nPos), m_canDir(dir), m_nCurStep(nCurStep) {}
};

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        if (x == 0)
        {
            return 0;
        }

        init(forbidden, a, b, x);
        int nStep = doJump();
        return nStep;
    }

    void init(const vector<int>& forbidden, int a, int b, int x)
    {
        m_forwadStep = a;
        m_backwardStep = b;
        m_targetPos = x;
        m_A.insert(0);
        m_B.insert(0);
        for (auto i : forbidden)
        {
            m_forbidden.insert(i);
        }
    }

    int doJump()
    {
        m_deque.push_back(new Node(0, Both_Dir, 0));

        while (!m_deque.empty())
        {
            Node* pCurNode = m_deque.front();
            m_deque.pop_front();
            int nCurStep = pCurNode->m_nCurStep;
            Dir canDir = pCurNode->m_canDir;
            int nCurPos = pCurNode->m_nPos;
            if (pCurNode)
            {
                delete pCurNode;
                pCurNode = nullptr;
            }

            if (canDir == Both_Dir)
            {
                int nForwardPos = nCurPos + m_forwadStep;
                auto iter1_1 = m_B.find(nForwardPos);
                auto iter1_2 = m_forbidden.find(nForwardPos);
                if (nForwardPos < 8000 && iter1_1 == m_B.end() && iter1_2 == m_forbidden.end())
                {
                    m_B.insert(nForwardPos);
                    m_deque.push_back(new Node(nForwardPos, Both_Dir, nCurStep + 1));
                    if (nForwardPos == m_targetPos)
                    {
                        return nCurStep + 1;
                    }
                }

                int nBackwardPos = nCurPos - m_backwardStep;
                auto iter2_1 = m_A.find(nBackwardPos);
                auto iter2_2 = m_forbidden.find(nBackwardPos);
                if (nBackwardPos > 0 && iter2_1 == m_A.end() && iter2_2 == m_forbidden.end())
                {
                    m_A.insert(nBackwardPos);
                    m_deque.push_back(new Node(nBackwardPos, Forward_Dir, nCurStep + 1));
                    if (nBackwardPos == m_targetPos)
                    {
                        return nCurStep + 1;
                    }
                }
            }
            else
            {
                int nForwardPos = nCurPos + m_forwadStep;
                auto iter1_1 = m_B.find(nForwardPos);
                auto iter1_2 = m_forbidden.find(nForwardPos);
                if (nForwardPos < 8000 && iter1_1 == m_B.end() && iter1_2 == m_forbidden.end())
                {
                    m_B.insert(nForwardPos);
                    m_deque.push_back(new Node(nForwardPos, Both_Dir, nCurStep + 1));
                    if (nForwardPos == m_targetPos)
                    {
                        return nCurStep + 1;
                    }
                }
            }
        }
        return -1;
    }

protected:
    deque<Node*> m_deque;
    set<int> m_A;
    set<int> m_B;
    set<int> m_forbidden;
    int m_forwadStep;
    int m_backwardStep;
    int m_targetPos;
};

int main()
{
    vector<int> forbidden = { 14, 4, 18, 1, 15 };
    std::cout << Solution().minimumJumps(forbidden, 3, 15, 9) << std::endl;

    return 0;
}