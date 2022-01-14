#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        m_inputVec = candidates;
        generateRet(m_inputVec, target, vector<int>());

        return m_retVec;
    }

    void generateRet(vector<int> candidates, int target, vector<int> coefficientVec)
    {
        if (target == 0)
        {
            generateSingleRet(coefficientVec);
            return;
        }
        if (target < 0 || candidates.size() == 0)
        {
            return;
        }

        int nCurNumber = candidates[0];
        candidates.erase(candidates.begin());
        int nMaxCoefficient = target/nCurNumber;
        for (int nCoefficient = 0; nCoefficient <= nMaxCoefficient; ++nCoefficient)
        {
            int nextTarge = target - nCurNumber * nCoefficient;
            vector<int> tmpCoefficientVec = coefficientVec;
            tmpCoefficientVec.push_back(nCoefficient);
            generateRet(candidates, nextTarge, tmpCoefficientVec);
        }
    }
    void generateSingleRet(const vector<int>& coefficientVec)
    {
        vector<int> singleRet;
        for (int i = 0; i < coefficientVec.size(); ++i)
        {
            for (int j = 0; j < coefficientVec[i]; ++j)
            {
                singleRet.push_back(m_inputVec[i]);
            }
        }
        if (!singleRet.empty())
        {
            m_retVec.push_back(singleRet);
        }
    }

protected:
    vector<vector<int>> m_retVec;
    vector<int> m_inputVec;
};


int main()
{
    vector<int> input = {2,3,6,7};
    auto ret = Solution().combinationSum(input, 7);

    return 0;
}