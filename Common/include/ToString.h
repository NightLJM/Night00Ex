#ifndef NIGHT00_TOSTRING_H
#define NIGHT00_TOSTRING_H

#include <string>
#include <sstream>
#include <list>
#include <set>
/*
 *  任意类型转string
 */

namespace night00
{
template<typename T>
class night_stringstream : public std::stringstream { };

template<typename T>
std::string toString(const T& data)
{
    std::string sRet;
    {
        night_stringstream<T> sstream;
        sstream << data;
        sstream >> sRet;
    }
    return sRet;
}

template<typename T>
std::string parseToString(const T& datas)
{
    std::string sRet = "[";
    auto iter = datas.begin();
    auto endIter = datas.end();
    auto endSecIter = endIter; --endSecIter;
    for (; (iter != endIter) && (iter != endSecIter); ++iter)
    {
        sRet += toString(*iter) + ",";
    }
    sRet += (iter == endSecIter)? (toString(*iter) + "]") : ("]");
    return sRet;        
}

template<typename T>
std::string toString(const std::list<T>& data)
{
    return parseToString(data);
}

template<typename T>
std::string toString(const std::set<T>& data)
{
    return parseToString(data);
}
};
#endif
