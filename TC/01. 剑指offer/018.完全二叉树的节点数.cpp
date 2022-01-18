#include <iostream>
#include <cmath>
/*
 * https://leetcode-cn.com/problems/count-complete-tree-nodes/
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        int nLeftDepth = getLeftDepth(root);
        int nRightDepth = getRightDepth(root);
        if (nLeftDepth == nRightDepth)
        {
            return pow(2, nLeftDepth) - 1;
        }
        else
        {
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }

protected:
    int getLeftDepth(TreeNode* pNode)
    {
        int nDepth = 0;
        while(pNode)
        {
            ++nDepth;
            pNode = pNode->left;
        }
        return nDepth;
    }

    int getRightDepth(TreeNode* pNode)
    {
        int nDepth = 0;
        while(pNode)
        {
            ++nDepth;
            pNode = pNode->right;
        }
        return nDepth;
    }
};