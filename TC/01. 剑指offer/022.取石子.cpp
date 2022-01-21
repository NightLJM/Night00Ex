#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        init(piles);

        int nSumVal = 0;
        for(const auto& val : piles)
        {
           nSumVal+= val; 
        }

        int nAliceScore = m_dpVec[0][m_nPileSize - 1];
        int nBobScore = nSumVal - nAliceScore;
        return nAliceScore > nBobScore;
    }

    void init(const vector<int>& piles)
    {
        m_nPileSize = piles.size();
        m_pilesVec = piles;
        m_dpVec.resize(m_nPileSize);
        m_dpSignVec.resize(m_nPileSize);
        for (int i = 0; i < m_nPileSize; ++i)
        {
            m_dpVec[i].resize(m_nPileSize, 0);
            m_dpSignVec[i].resize(m_nPileSize, 0);
        }

        for (int nCol = 0; nCol < m_nPileSize; ++nCol)
        {
            for (int nRow = nCol; nRow >= 0; --nRow)
            {
                int nV1 = 0;
                int nV2 = 0;

                if (isInBorder(nRow + 1, nCol))
                {
                    if (m_dpSignVec[nRow + 1][nCol] && isInBorder(nRow + 1, nCol - 1))
                    {
                        nV1 = m_dpVec[nRow + 1][nCol - 1];
                    }
                    else if (!m_dpSignVec[nRow + 1][nCol] && isInBorder(nRow + 2, nCol))
                    {
                        nV1 = m_dpVec[nRow + 2][nCol];
                    }
                }

                if (isInBorder(nRow, nCol - 1))
                {
                    if (m_dpSignVec[nRow][nCol - 1] && isInBorder(nRow + 1, nCol - 1))
                    {
                        nV2 = m_dpVec[nRow + 1][nCol - 1];
                    }
                    else if (!m_dpSignVec[nRow][nCol - 1] && isInBorder(nRow, nCol - 2))
                    {
                        nV2 = m_dpVec[nRow][nCol - 2];
                    }
                }

                nV1 += m_pilesVec[nRow];
                nV2 += m_pilesVec[nCol];
                if (nV1 > nV2)
                {
                    m_dpVec[nRow][nCol] = nV1;
                    m_dpSignVec[nRow][nCol] = 0;
                }
                else
                {
                    m_dpVec[nRow][nCol] = nV2;
                    m_dpSignVec[nRow][nCol] = 1;
                }  
            }
        }
    }

protected:
    bool isInBorder(int x, int y)
    {
        return (x <= y) && (x >= 0) && (x < m_nPileSize) 
            && (y >= 0) && (y < m_nPileSize);
    }

protected:
    vector<int> m_pilesVec;
    vector<vector<int>> m_dpVec;
    vector<vector<int>> m_dpSignVec;
    int m_nPileSize;
};