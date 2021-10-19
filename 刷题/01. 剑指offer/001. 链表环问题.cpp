#include <iostream>

/*
    给一个长度为n链表，若其中包含环，请找出该链表的环的入口结点，否则，返回null。

    数据范围： n\le1000n≤1000
    要求：空间复杂度 O(1)O(1)，时间复杂度 O(n)O(n)

    输入描述：
    输入分为2段，第一段是入环前的链表部分，第二段是链表环的部分，后台将这2个会组装成一个有环或者无环单链表

    返回值描述：
    返回链表的环的入口结点即可。而我们后台程序会打印这个节点
*/

/*
    解题思路，快慢指针
*/

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode* pFastNode = pHead;
        ListNode* pSlowNode = pHead;
        int nStep = 0;

        while (pFastNode->next != nullptr)
        {
            pFastNode = pFastNode->next;
            if (pFastNode == nullptr)
            {
                return nullptr;
            }
            pFastNode = pFastNode->next;
            if (pFastNode == nullptr)
            {
                return nullptr;
            }
            pSlowNode = pSlowNode->next;
            ++nStep;
            if (pFastNode == pSlowNode)
            {
                break;
            }
        }

        if (nStep == 0)
        {
            return nullptr;
        }

        pFastNode = pHead;
        pSlowNode = pHead;
        for (int i = 0; i < nStep; ++i)
        {
            pFastNode = pFastNode->next;
        }
        
        while(pFastNode != pSlowNode)
        {
            pFastNode = pFastNode->next;
            pSlowNode = pSlowNode->next;
        }

        return pSlowNode;
    }
};