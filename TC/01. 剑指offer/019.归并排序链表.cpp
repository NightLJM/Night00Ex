#include <iostream>

/*
 * https://leetcode-cn.com/problems/sort-list/
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* tail = nullptr;
        int nLength = 0;
        genLengthAndTail(head, tail, nLength);
        std::pair<ListNode*, ListNode*> list = mergeSortList(head, tail, nLength);
        return list.first;
    }

protected:
    std::pair<ListNode*, ListNode*> mergeSortList(ListNode* head, ListNode* tail, int nLength)
    {
        if (nLength <= 1 || head == nullptr || tail == nullptr)
        {
            return std::make_pair(head, tail);
        }

        ListNode* pHead1 = head;
        int nLength1 = (nLength + 1) / 2;
        ListNode* pTail1 = pHead1;  advance(pTail1, nLength1 - 1);
        ListNode* pHead2 = pTail1->next; pTail1->next = nullptr;
        int nLength2 = nLength - nLength1;
        ListNode* pTail2 = tail;

        std::pair<ListNode*, ListNode*> list1 = mergeSortList(pHead1, pTail1, nLength1);
        std::pair<ListNode*, ListNode*> list2 = mergeSortList(pHead2, pTail2, nLength2);
        return merge(list1, list2);
    }

    void advance(ListNode*& pNode, int distance)
    {
        if (pNode == nullptr)
        {
            return;
        }

        for (int i = 0; i < distance; ++i)
        {
            pNode = pNode->next;
            if (pNode == nullptr)
            {
                break;
            }
        }
    }

    void genLengthAndTail(ListNode* head, ListNode*& tail, int& nLength)
    {
        tail = head;
        nLength = 1;
        if (tail == nullptr)
        {
            nLength = 0;
            return;
        }

        while(tail->next != nullptr)
        {
            tail = tail->next;
            ++nLength;
        }
    }
    
    std::pair<ListNode*, ListNode*> merge(const std::pair<ListNode*, ListNode*>& list1, const std::pair<ListNode*, ListNode*>& list2)
    {
        ListNode* pHead = nullptr;
        ListNode* pTail = nullptr;
        ListNode* pNode = nullptr;

        ListNode* pHead1 = list1.first;
        ListNode* pHead2 = list2.first;

        while(pNode = getMinNode(pHead1, pHead2))
        {
            if(pHead == nullptr)
            {
                pHead = pNode;
                pTail = pNode;
                continue;
            }
            
            pTail->next = pNode;
            pTail = pNode;
        }

        return std::make_pair(pHead, pTail);
    }

    ListNode* getMinNode(ListNode*& pHead1, ListNode*& pHead2)
    {
        ListNode* pRet = nullptr;

        if (pHead1 == nullptr && pHead2 != nullptr)
        {
            pRet = pHead2;
            pHead2 = pHead2->next;
            return pRet;
        }
        else if (pHead2 == nullptr && pHead1 != nullptr)
        {
            pRet = pHead1;
            pHead1 = pHead1->next;
            return pRet;
        }
        else if (pHead1 == nullptr && pHead2 == nullptr)
        {
            return pRet;
        }

        if (pHead1->val < pHead2->val)
        {
            pRet = pHead1;
            pHead1 = pHead1->next;
            return pRet;
        }
        else
        {
            pRet = pHead2;
            pHead2 = pHead2->next;
            return pRet;
        }
        
    }
};