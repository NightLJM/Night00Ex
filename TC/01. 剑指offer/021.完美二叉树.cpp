#include <iostream>
using namespace std;

/*
*  https://leetcode-cn.com/problems/stone-game/
*/

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
        {
            return root;
        }

        connect(root->left, root->right);
        return root;
    }

protected:
    void connect(Node* pNode1, Node* pNode2)
    {
        if (pNode1 == nullptr || pNode2 == nullptr)
        {
            return ;
        }

        pNode1->next = pNode2;
        pNode2->next = nullptr;

        connect(pNode1->left, pNode1->right);
        connect(pNode2->left, pNode2->right);
        connect(pNode1->right, pNode2->left);
    }
};