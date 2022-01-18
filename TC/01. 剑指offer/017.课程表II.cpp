#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

/*
 * https://leetcode-cn.com/problems/course-schedule-ii/
*/

struct Course
{
    int m_nInDegree;
    vector<int> m_NextCourseVec;
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        doInitCourse(numCourses, prerequisites);
        doLearning();
        return m_resOrder;
    }

    void doInitCourse(int numCourses, const vector<vector<int>>& prerequisites)
    {  
        m_allCourse.resize(numCourses, nullptr);

        for (const auto& courseRelation : prerequisites)
        {
            int nCourseID = courseRelation[0];
            int nPreCourseID = courseRelation[1];
            
            if (m_allCourse[nCourseID] == nullptr)
            {
                m_allCourse[nCourseID] = new Course();
                m_allCourse[nCourseID]->m_nInDegree = 1;
            }
            else
            {
                if (m_allCourse[nCourseID]->m_nInDegree == 0)
                {
                    m_canLearnCourse.erase(nCourseID);
                }
                m_allCourse[nCourseID]->m_nInDegree += 1;
            }
            
            if (m_allCourse[nPreCourseID] == nullptr)
            {
                m_allCourse[nPreCourseID] = new Course();
                m_allCourse[nPreCourseID]->m_nInDegree = 0;
                m_allCourse[nPreCourseID]->m_NextCourseVec.push_back(nCourseID);
                m_canLearnCourse.insert(nPreCourseID);
            }
            else
            {
                m_allCourse[nPreCourseID]->m_NextCourseVec.push_back(nCourseID);
            }
        }
    }

    void doLearning()
    {
        for (int nID = 0; nID < m_allCourse.size(); ++nID)
        {
            if (m_allCourse[nID] == nullptr)
            {
                m_resOrder.push_back(nID);
            }
        }

        while(!m_canLearnCourse.empty())
        {
            auto iter = m_canLearnCourse.begin();
            int nID = *iter;
            m_canLearnCourse.erase(iter);
            m_resOrder.push_back(nID);
            Course* pCourse = m_allCourse[nID];
            for (const auto& nNextID : pCourse->m_NextCourseVec)
            {
                Course* pNextCourse = m_allCourse[nNextID];
                pNextCourse->m_nInDegree -= 1;
                if (pNextCourse->m_nInDegree == 0)
                {
                    m_canLearnCourse.insert(nNextID);
                }
            }
        }

        if (m_resOrder.size() != m_allCourse.size())
        {
            m_resOrder.clear();
        }
    }

~Solution()
{
    for (auto& pCourse : m_allCourse)
    {
        if (pCourse)
        {
            delete pCourse;
            pCourse = nullptr;
        }
    }
}

protected:
    set<int> m_canLearnCourse;
    vector<Course*> m_allCourse;
    vector<int> m_resOrder;
};
