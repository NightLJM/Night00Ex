#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
    struct Node
    {
        int val;
        int index;
        Node(int v, int i)
        {
            val = v;
            index = i;
        }

        bool operator<(const Node& node) const
        {
            if (val < node.val)
            {
                return true;
            }
            if (val == node.val)
            {
                return index < node.index;
            }
            return false;
        }
        bool operator==(const Node& node) const
        {
            return (val == node.val) && (index == node.index);
        }
    };
    
    
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        
        vector<int> ret;
        if (size == 0 || size > num.size())
        {
            return ret;
        }
         
        for (int i = 0; i < size; ++i)
        {
            
            m_Set.insert(Node(num[i], i));
        }
        auto endIter = m_Set.end();
        --endIter;
        ret.push_back(endIter->val);
        
        for (int i = size; i < num.size(); ++i)
        {
            auto iter = m_Set.find(Node(num[i - size], i - size));
            m_Set.erase(iter);
            m_Set.insert(Node(num[i], i));
            auto endIter = m_Set.end();
            --endIter;
            ret.push_back(endIter->val);
        }
        
        return ret;
    }
    
protected:
    std::set<Node> m_Set;
};

int main()
{
    std::vector<int> input = {10, 14, 12, 11};

    std::vector<int> res = Solution().maxInWindows(input, 1);

    for (auto n : res)
    {
        std::cout << n << " ";
    }
    std::cout << endl;

    return 0;
}