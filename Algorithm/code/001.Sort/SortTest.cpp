#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "gtest/gtest.h"


template<typename SortFun, typename CompFun>
class SortTestHelper
{
public:

    SortTestHelper(SortFun sortFun);
    SortTestHelper(SortFun sortFun, CompFun compFun);

    void setEqualFun(CompFun equalFun);
    
    virtual void autotest();
protected:
    template<typename ItemIter>
    void assertTest(ItemIter inputBeginIter, ItemIter inputEndIter, 
        ItemIter expectBeginIter, ItemIter expectEndIter);

    template<typename ItemIter>
    void expectTest(ItemIter inputBeginIter, ItemIter inputEndIter, 
        ItemIter expectBeginIter, ItemIter expectEndIter);

    template<typename ItemIter>
    bool check(ItemIter actualBeginIter, ItemIter actualEndIter, 
        ItemIter expectBeginIter, ItemIter expectEndIter);
private:
    SortFun m_pSortFun;
    CompFun m_pCompFun;
    CompFun m_pEqualFun;

    std::string m_sErrMsg;
};

template<typename SortFun, typename CompFun>
SortTestHelper<SortFun, CompFun>::SortTestHelper(SortFun sortFun)
    : m_pSortFun(sortFun)
    , m_pCompFun(nullptr)
    , m_pEqualFun(nullptr)
{

}

template<typename SortFun, typename CompFun>
SortTestHelper<SortFun, CompFun>::SortTestHelper(SortFun sortFun, CompFun compFun)
    : m_pSortFun(sortFun)
    , m_pCompFun(compFun)
    , m_pEqualFun(nullptr)
{

}

template<typename SortFun, typename CompFun>
void SortTestHelper<SortFun, CompFun>::setEqualFun(CompFun equalFun)
{
    m_pEqualFun = equalFun;
}

template<typename SortFun, typename CompFun>
void SortTestHelper<SortFun, CompFun>::autotest()
{
    int[] inputIntArray1 = {0, 1, 4, 5, 9, 8, 0};
    int[] expectIntArray1 = {0, 0, 1, 4, 5, 8, 9};

    int[] inputIntArray2 = {};
    int[] expectIntArray2 = {};

    std::string inputString1 = "7ha81nbg"
    std::string expectString1 = "178abghn"

    std::vector<std::string> inputVec1= {"123", "456", "876", "867", "abce", "abcd"};
    std::vector<std::string> expectVec1= {"123", "456", "867", "876", "abcd", "abce"};

    std::cout << "---Array1----" << endl;
    expectTest(inputIntArray1, inputIntArray1 + 7, expectIntArray1, expectIntArray1 +7);
    std::cout << "---Array2----" << endl;
    expectTest(inputIntArray2, inputIntArray2 + 7, expectIntArray2, expectIntArray2 +7);
    std::cout << "---String1----" << endl;
    expectTest(inputString1.begin(), inputString1.end(), expectString1.begin(), expectString1.end());
    std::cout << "---Vector1----" << endl;
    expectTest(inputVec1.begin(), inputVec1.end(), expectVec1.begin(), expectVec1.end());
}

template<typename SortFun, typename CompFun>
template<typename ItemIter>
void SortTestHelper<SortFun, CompFun>::assertTest(ItemIter inputBeginIter, ItemIter inputEndIter, 
        ItemIter expectBeginIter, ItemIter expectEndIter)
{
    m_pSortFun(inputBeginIter, inputEndIter);

    bool bCheckRet = check(inputBeginIter, inputEndIter, expectBeginIter, expectEndIter);
    ASSERT_TRUE(bChekRet) << m_sErrMsg;
}

template<typename SortFun, typename CompFun>
template<typename ItemIter>
void SortTestHelper<SortFun, CompFun>::expectTest(ItemIter inputBeginIter, ItemIter inputEndIter, 
        ItemIter expectBeginIter, ItemIter expectEndIter)
{
    m_pSortFun(inputBeginIter, inputEndIter);

    bool bCheckRet = check(inputBeginIter, inputEndIter, expectBeginIter, expectEndIter);
    EXPECT_TRUE(bChekRet) << m_sErrMsg;
}

template<typename SortFun, typename CompFun>
template<typename ItemIter>
bool SortTestHelper<SortFun, CompFun>::check(ItemIter actualBeginIter, ItemIter actualEndIter, 
    ItemIter expectBeginIter, ItemIter expectEndIter)
{
    bool ret = true;

    auto actualIter = actualBeginIter;
    auto expectIter = expectBeginIter;
    int nErrIndex = 0;

    while(actualIter != actualEndIter && expectIter != expectEndIter)
    {
        if (m_pEqualFun == nullptr)
        {
            ret = ((*actualIter) == (*expectIter)) ?  true : false;
        }
        else
        {
            ret = (m_pEqualFun(*actualIter, *expectIter) == true) ?  true ：false;
        }
        
        if (ret == false)
        {
            break;
        }

        ++actualIter;
        ++expectIter;
        ++nErrIndex;
    }

    ret = (actualIter != actualEndIter || expectIter != expectEndIter) ?  false : ret;

    if (ret == false)
    {
        m_sErrMsg.clear();
        m_sErrMsg = "Data is error in index" + std::to_string(nErrIndex);
    }

    return ret;
}












