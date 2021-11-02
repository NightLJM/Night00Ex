#include <iostream>
#include <iterator>
#include <algorithm>
#include <type_traits>

namespace Night00
{
    template<typename Iterator>
    bool isEqual(Iterator beginIter1, Iterator endIter1, Iterator beginIter2, Iterator endIter2)
    {
        Iterator iter1 = beginIter1;
        Iterator iter2 = beginIter2;
        while ((iter1 != endIter1) && (iter2 != endIter2))
        {
            if ((*iter1) != (*iter2))
            {
                return false;
            }
            ++iter1;
            ++iter2;
        }
        if ((iter1 == endIter1) && (iter2 == endIter2))
        {
            return true;
        }
        else
        {
            return false;
        }

    }


    template<typename ForwardIterator, typename CompFun>
    void bubbleSort(ForwardIterator beginIter, ForwardIterator endIter, CompFun comFun)
    {
        //typedef typename std::iterator_traits<ForwardIterator>::value_type value_type;
        auto tmpEndIter = endIter;
        for (auto iter = beginIter; iter != tmpEndIter; ++iter)
        {
            //value_type ___v1 = *iter;
            if ((iter + 1) == tmpEndIter)
            {
                tmpEndIter = iter;
                iter = beginIter - 1;
                continue;
            }
            if (!comFun(*iter, *(iter + 1)))
            {
                std::swap(*iter, *(iter + 1));
            }
        }
    }
}
