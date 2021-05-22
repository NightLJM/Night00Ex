#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(nullptr), right(nullptr) {}
};

enum sig
{
    NOT_PUSHED,
    LEFT_PUSHED,
    RIGHT_PUSHED
};

int maxDepth2(TreeNode *pTreeNode)
{
    if (pTreeNode == nullptr)
    {
        return 0;
    }

    int nMaxDepth = 1;
    int nCurDepth = 1;
    stack<TreeNode*> treeStack;
    stack<sig> sigStack;

    treeStack.push(pTreeNode);
    sigStack.push(NOT_PUSHED);

    while(treeStack.size() != 0)
    {
        TreeNode* pTop = treeStack.top();
        sig eTop = sigStack.top();
        switch(eTop)
        {
            case NOT_PUSHED:
                {
                    sigStack.pop();
                    sigStack.push(LEFT_PUSHED);

                    TreeNode *pLChild = pTop->left;
                    if (pLChild != nullptr)
                    {
                        treeStack.push(pLChild);
                        sigStack.push(NOT_PUSHED);
                        ++nCurDepth;
                        nMaxDepth = max(nMaxDepth, nCurDepth);
                    }
                    break;
                }
            case LEFT_PUSHED:
                {
                    sigStack.pop();
                    sigStack.push(RIGHT_PUSHED);

                    TreeNode *pRChild = pTop->right;
                    if (pRChild != nullptr)
                    {
                        treeStack.push(pRChild);
                        sigStack.push(NOT_PUSHED);
                        ++nCurDepth;
                        nMaxDepth = max(nMaxDepth, nCurDepth);
                    }
                    break;
                }
            case RIGHT_PUSHED:
                {
                    treeStack.pop();
                    sigStack.pop();
                    --nCurDepth;
                }
        }

    }
    return nMaxDepth;
}


TEST(maxDepth, case1)
{
    // [3,9,20,null,null,15,7]
    TreeNode tree[] = {3,9,20,-1,-1,15,7};
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];
    tree[2].left = &tree[5];
    tree[2].right = &tree[6];

    EXPECT_EQ(maxDepth2(&tree[0]), 3);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}