#include <iostream>
#include <stack>
/*
    输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
*/


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};


class Solution {
public:
    int TreeDepth(TreeNode* pRoot) {
        if (pRoot == nullptr)
        {
            return 0;
        }

        std::stack<TreeNode*> nodeStack;
        nodeStack.push(pRoot);
        TreeNode* pCurPopNode = nullptr;
        int nCurDepth = 1;
        int nMaxDepth = 1;

        while(!nodeStack.empty())
        {
            TreeNode* pTopNode = nodeStack.top();

            if((pCurPopNode == nullptr) && (pTopNode->left != nullptr))
            {
                //压左孩子进栈
                nodeStack.push(pTopNode->left);
                ++nCurDepth;
                nMaxDepth = nMaxDepth > nCurDepth? nMaxDepth : nCurDepth;
                pCurPopNode = nullptr;
            }
            else if((pCurPopNode == pTopNode->left) && (pTopNode->right != nullptr))
            {
                //压右孩子进栈
                nodeStack.push(pTopNode->right);
                ++nCurDepth;
                nMaxDepth = nMaxDepth > nCurDepth? nMaxDepth : nCurDepth;
                pCurPopNode = nullptr;

            }
            else if((pCurPopNode == pTopNode->right) || (pTopNode->right == nullptr))
            {
                //栈顶弹出
                pCurPopNode = nodeStack.top();
                nodeStack.pop();
                --nCurDepth;
            }
        }

        return nMaxDepth;
    }
};