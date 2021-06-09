#include <iostream>
#include <stack>
#include <string>
#include <gtest/gtest.h>
#include <memory>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* pLeft;
    TreeNode* pRight;
    TreeNode(int v, TreeNode* pL = nullptr, TreeNode* pR = nullptr)
        : val(v)
        , pLeft(pL)
        , pRight(pR)
    {
        
    }
};


int getDiameter(TreeNode* pNode)
{
    if (pNode == nullptr)
    {
        return 0;
    }

    int nMaxDepth = 1;
    int nSMaxDepth = 1;
    int nCurDepth = 1;

    string sMaxPath = "0";
    string sSMaxPath = "0";

    stack<TreeNode*> st;
    st.push(pNode);
    TreeNode* pCurNode = nullptr;
    TreeNode* pLastPopNode = nullptr;

    int nSig = 0;       

    while(!st.empty())
    {
        pCurNode = st.top();
        if (pLastPopNode == pCurNode->pLeft)    //如果已经遍历了栈顶的左孩子
        {
            if (pCurNode->pRight != nullptr)
            {
                st.push(pCurNode->pRight);
                ++nCurDepth;
                nSig = 1;
            }
            else
            {
                pLastPopNode = pCurNode;
                st.pop();
                --nCurDepth;
                nSig = 0;
            }
            
        }
        else if(pLastPopNode == pCurNode->pRight)
        {
            pLastPopNode = pCurNode;
            st.pop();
            --nCurDepth;
            nSig = 0;
        }
        else
        {
            if ()
        }
        




    }








}





