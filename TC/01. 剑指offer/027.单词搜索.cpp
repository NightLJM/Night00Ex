#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0)
        {
            return true;
        }

        vector<vector<char>> scanVec;
        scanVec.resize(board.size());
        for (auto& vec : scanVec)
        {
            vec.resize(board[0].size(), 0);
        }

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] != word[0])
                {
                    continue;
                }       
                scanVec[i][j] = 1;
                bool bRet = dfsFind(board, word, scanVec, 1, i, j);
                scanVec[i][j] = 0;
                if (bRet)
                {
                    return true;
                }
            }
        }

        return false;
    }


protected:
    bool dfsFind(const vector<vector<char>>& board, const string& word, vector<vector<char>>& scanVec, int nBeginIndex, int x, int y)
    {
        if (nBeginIndex == word.size())
        {
            return true;
        }

        if ((x + 1 < board.size()) && (board[x + 1][y] == word[nBeginIndex]) && (scanVec[x + 1][y] == 0))
        {
            scanVec[x + 1][y] = 1;
            bool bRet = dfsFind(board, word, scanVec, nBeginIndex + 1, x + 1, y);
            scanVec[x + 1][y] = 0;
            if (bRet)
            {
                return true;
            }
        }
        
        if ((y + 1 < board[0].size()) && (board[x][y + 1] == word[nBeginIndex]) && (scanVec[x][y + 1] == 0))
        {
            scanVec[x][y + 1] = 1;
            bool bRet = dfsFind(board, word, scanVec, nBeginIndex + 1, x, y + 1);
            scanVec[x][y + 1] = 0;
            if (bRet)
            {
                return true;
            }
        }

        if ((x - 1 >= 0) && (board[x - 1][y] == word[nBeginIndex]) && (scanVec[x - 1][y] == 0))
        {
            scanVec[x - 1][y] = 1;
            bool bRet = dfsFind(board, word, scanVec, nBeginIndex + 1, x - 1, y);
            scanVec[x - 1][y] = 0;
            if (bRet)
            {
                return true;
            }
        }

        if ((y - 1 >= 0) && (board[x][y - 1] == word[nBeginIndex]) && (scanVec[x][y - 1] == 0))
        {
            scanVec[x][y - 1] = 1;
            bool bRet = dfsFind(board, word, scanVec, nBeginIndex + 1, x, y - 1);
            scanVec[x][y - 1] = 0;
            if (bRet)
            {
                return true;
            }
        }

        return false;
    }
};




