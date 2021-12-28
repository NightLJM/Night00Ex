#include <iostream>
#include <map>

/*
https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/
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
    int maxPathSum(TreeNode* root) {

        if (root == nullptr)
        {
            return 0;
        }
        getMaxVal(root);
        
        return m_nMaxVal;
    }


    int getMaxVal(TreeNode* pNode)
    {
        int nLv = pNode->left ? std::max(getMaxVal(pNode->left), 0) : 0;
        int nRv = pNode->right ? std::max(getMaxVal(pNode->right), 0) : 0;
        int curMax = std::max(nLv, nRv) + pNode->val;
        m_nMaxVal = m_bInit ? std::max(m_nMaxVal, nLv + nRv + pNode->val) : nLv + nRv + pNode->val;
        m_bInit = true;
        return curMax;
    }
protected:
    int m_nMaxVal;
    bool m_bInit = false;
};