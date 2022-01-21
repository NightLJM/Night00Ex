#include <iostream>
#include <string>
#include <map>
#define freeAndNil(p)   \
if (p)                  \
{                       \
    delete p;           \
    p = nullptr;        \
}                   

/*
 * https://leetcode-cn.com/problems/implement-trie-prefix-tree/solution/shi-xian-trie-qian-zhui-shu-by-leetcode-ti500/
*/

using namespace std;

class Trie;

class TrieNode
{
    friend class Trie;
protected:
    TrieNode(char v) : m_val(v), m_count(0) { }
    TrieNode(char v, int nCount) : m_val(v), m_count(nCount) { }
    ~TrieNode()
    {
        for (auto pair : m_nextNodes)
        {
            TrieNode* pNextNode = pair.second;
            freeAndNil(pNextNode);
        }
    }
    bool operator<(const TrieNode& node)
    {
        return m_val < node.m_val;
    }
    bool operator==(const TrieNode& node)
    {
        return m_val == node.m_val;
    }
    bool operator<(char val)
    {
        return m_val < val;
    }
    bool operator==(char val)
    {
        return m_val == val;
    }
protected:
    char m_val;
    int m_count;
    map<char, TrieNode*> m_nextNodes;
};


class Trie {
public:
    Trie() : m_pRoot(new TrieNode('0')) { }
    ~Trie()
    {
        freeAndNil(m_pRoot);
    }

    void insert(string word) 
    {
        doInsert(m_pRoot, word);
    }
    
    bool search(string word) 
    {
        TrieNode* pRet = doFind(m_pRoot, word, false);
        return pRet != nullptr;
    }
    
    bool startsWith(string prefix) 
    {
        TrieNode* pRet = doFind(m_pRoot, prefix, true);
        return pRet != nullptr; 
    }

protected:
    void doInsert(TrieNode* pNode, string& word)
    {
        if (word.size() == 0)
        {
            return;
        }

        //pNode不能为空
        bool bFinalChar = (word.size() == 1);
        auto& nextNodes = pNode->m_nextNodes;
        auto iter = nextNodes.find(word[0]);
        if (iter == nextNodes.end())
        {   //没有当前的字符节点，需要新建
            TrieNode* pNode = new TrieNode(word[0]);
            pNode->m_count = bFinalChar? 1 : 0;
            nextNodes.insert(std::make_pair(word[0], pNode));
            word.erase(word.begin());
            doInsert(pNode, word);
        }
        else
        {   //有当前的字符节点
            TrieNode* pNode = iter->second;
            pNode->m_count += bFinalChar? 1 : 0;
            word.erase(word.begin());
            doInsert(pNode, word);
        }
    }

    TrieNode* doFind(TrieNode* pNode, string& word, bool bPrefix)
    {
        if (word.size() == 0)
        {
            if (bPrefix)
            {
                return pNode;
            }
            else
            {
                return pNode->m_count > 0 ? pNode : nullptr;
            }
        }

        const auto& nextNodes = pNode->m_nextNodes;
        auto iter = nextNodes.find(word[0]);
        if (iter == nextNodes.end())
        {
            return nullptr;
        }
        word.erase(word.begin());
        pNode = iter->second;
        return doFind(pNode, word, bPrefix);
    }

protected:
    TrieNode* m_pRoot;
};