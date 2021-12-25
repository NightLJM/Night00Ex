#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param matrix char字符型vector<vector<>> 
     * @param word string字符串 请设计一个函数，用来判断在一个n乘m的矩阵中是否存在一条包含某长度为len的字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 例如 \begin{bmatrix} a & b & c &e \\ s & f & c & s \\ a & d & e& e\\ \end{bmatrix}\quad 
  矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
数据范围：,
进阶：时间复杂度，空间复杂度

     * @return bool布尔型
     */
    bool hasPath(vector<vector<char> >& matrix, string word) {
        m_matrix = matrix;
        m_word = word;
        if (m_matrix.size() == 0 || m_matrix[0].size() == 0 || word.size() == 0)
        {
            return false;
        }
        vector<vector<bool>> bMatric;
        bMatric.resize(matrix.size());
        for(int i = 0; i < bMatric.size(); ++i)
        {
            bMatric[i].resize(matrix[0].size(), true);
        }

        bool ret = false;

        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == word[0])
                {
                    ret = ret || hasPathFrom(std::make_pair(i, j), bMatric, 0);
                }
                if (ret)
                {
                    return ret;
                }
            }
        }

        return false;
    }




    bool hasPathFrom(std::pair<int, int> pos, vector<vector<bool> > bMatric, int beginIndex)
    {
        if (beginIndex >= m_word.size())
        {
            return true;
        }
        int xPos = pos.first;
        int yPos = pos.second;
        if (xPos >= m_matrix.size() || yPos >= m_matrix[0].size()
            || xPos < 0 || yPos < 0)
        {
            return false;
        }
        
        if (!bMatric[xPos][yPos] || m_matrix[xPos][yPos] != m_word[beginIndex])
        {
            return false;
        }
        
        bMatric[xPos][yPos] = false;
        bool ret = hasPathFrom(std::make_pair(xPos + 1, yPos), bMatric, beginIndex + 1)
                || hasPathFrom(std::make_pair(xPos - 1, yPos), bMatric, beginIndex + 1)
                || hasPathFrom(std::make_pair(xPos, yPos + 1), bMatric, beginIndex + 1)
                || hasPathFrom(std::make_pair(xPos, yPos - 1), bMatric, beginIndex + 1);

        return ret;
    }

    vector<vector<char> > m_matrix;
    string m_word;
};

int main()
{
    vector<vector<char> > matrix;
    matrix.resize(2);
    vector<char> v1 {'A', 'B'};
    vector<char> v2 {'C', 'D'};
    matrix[0] = v1;
    matrix[1] = v2;
    string word = "ABCD";
    bool b = Solution().hasPath(matrix, word);

    return 0;
}