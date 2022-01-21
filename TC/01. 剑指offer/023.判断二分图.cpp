#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        m_nodeVec.resize(graph.size(), -1);

        int bRet = true;
        for (int i = 0; i < m_nodeVec.size(); ++i)
        {
            if (m_nodeVec[i] != -1)
            {
                continue;
            }

            m_nodeVec[i] = 0;
            bRet &= dfs(graph, i, 0);
            if (!bRet)
            {
                return false;
            }
        }

        return bRet;
    }

    bool dfs(const vector<vector<int>>& graph, int nNodeNo, int nLastSetNo)
    {
        bool bRet = true;
        int nCurSetNo = nLastSetNo == 0 ? 1 : 0;

        for (int i = 0; i < graph[nNodeNo].size(); ++i)
        {
            int nOtherNodeNo = graph[nNodeNo][i];
            if (m_nodeVec[nOtherNodeNo] == nCurSetNo)
            {
                continue;
            }
            else if (m_nodeVec[nOtherNodeNo] == nLastSetNo)
            {
                return false;
            }

            m_nodeVec[nOtherNodeNo] = nCurSetNo;
            bRet &= dfs(graph, nOtherNodeNo, nCurSetNo);
            if (!bRet)
            {
                return false;
            }
        }

        return bRet;
    }

protected:
    vector<int> m_nodeVec;
};

int main()
{
    vector<vector<int>> inputGraph;
    {
        // vector<int> v1 {1};
        // vector<int> v2 {0, 3};
        // vector<int> v3 {3};
        // vector<int> v4 {1, 2};

        vector<int> v1 {1, 2, 3};
        vector<int> v2 {0, 2};
        vector<int> v3 {0, 1, 3};
        vector<int> v4 {0, 2};

        inputGraph.push_back(v1); inputGraph.push_back(v2);
        inputGraph.push_back(v3); inputGraph.push_back(v4);
    }

    std::cout << Solution().isBipartite(inputGraph) << std::endl;

    return 0;
}



