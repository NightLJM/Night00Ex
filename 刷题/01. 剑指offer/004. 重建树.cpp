#include <iostream>
#include <vector>

using namespace std;

/*
    给定节点数为 n 二叉树的前序遍历和中序遍历结果，请重建出该二叉树并返回它的头结点。
*/

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(const vector<int>& pre, const vector<int>& vin) 
    {
        return rebuildTree(pre, 0, pre.size(), vin, 0, vin.size());
    }

protected:
    TreeNode* rebuildTree(const vector<int>& pre, int preFirstIndex, int preLastIndex,
        const vector<int>& vin, int vinFirstIndex, int vinLastIndex)
    {
        if ((preFirstIndex >= preLastIndex) || (vinFirstIndex >= vinLastIndex))
        {
            return nullptr;
        }

        int nRootValue = pre[preFirstIndex];
        int vinRootIndex = vin.find(nRootValue);
        if (vinRootIndex >= vinLastIndex || vinRootIndex < vinFirstIndex)
        {
            return nullptr;
        }

        int nPreLeftChildLength = vinRootIndex - vinFirstIndex;
        int nPreRightChildLength = vinLastIndex - vinRootIndex - 1;

        int preLeftFirstIndex = preFirstIndex + 1;
        int preLeftLastIndex = preLeftFirstIndex + nPreLeftChildLength;
        int preRightFirstIndex = preLeftLastIndex;
        int preRightLastIndex = preLastIndex;

        int vinLeftFirstIndex = vinFirstIndex;
        int vinLeftLastIndex = vinRootIndex;
        int vinRightFirstIndex = vinLeftLastIndex + 1;
        int vinRightLastIndex = vinLastIndex;

        TreeNode* pRoot = new TreeNode(nRootValue);
        pRoot->left = rebuildTree(pre, preLeftFirstIndex, preLeftLastIndex, vin, preRightFirstIndex, preRightLastIndex);
        pRoot->right = rebuildTree(pre, vinLeftFirstIndex, vinLeftLastIndex, vin, vinRightFirstIndex, vinRightLastIndex);

        return pRoot;
    }
};