#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

template <class T>
void print(const T& vec)
{
    for (auto iter = vec.begin(); iter != vec.end(); ++iter)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

void printSplitLine(string sIndex)
{
    sIndex += ". ";
    string sOutput = "-----------------------------------------";
    copy(sIndex.begin(), sIndex.end(), sOutput.begin());
    std::cout << sOutput << std::endl;
}

int main()
{
    //1.1 输入流分割
    {
        printSplitLine("1.1");
        istringstream input;
        input.str("-1,-2,5,6,7");       //"-1,-2,5,6,7" 或 "-1,-2,5,6,7，" 都是一样的
        vector<string> ret;
        for (string tmpStr; getline(input, tmpStr, ',');)
        {
            ret.push_back(tmpStr);
        }
        cout << "ret.size() = " << ret.size() << endl;
        print(ret);
        /*  输出：
            ret.size() = 5
            -1 -2 5 6 7 
        */
    }

    //1.2 字符串分割
    {
        printSplitLine("1.2");
        string inputStr = "-1,-2,-3,-4,-5,6";
        istringstream input;
        input.str(inputStr);       
        vector<string> ret;
        for (string tmpStr; getline(input, tmpStr, ',');)
        {
            ret.push_back(tmpStr);
        }
        cout << "ret.size() = " << ret.size() << endl;
        print(ret);
        
        /*  输出：
            ret.size() = 6
            -1 -2 -3 -4 -5 6 
        */
    }

    //1.3 字符串输入方式
    {
        // string test1;
        // cout << "cin输入：";
        // cin >> test1;
        // cout << "输入的字符串为：" << test1 << endl;
        // cin.ignore();					//读取并舍弃缓存区的字符
        // cout << "getline输入：";
        // getline(cin,test1);
        // cout << "输入的字符串为：" << test1 << endl;
    }

    //1.4 basic_string模板类
    {
        printSplitLine("1.4");
        typedef basic_string<wchar_t> wstring;
        wstring wStr(L"This is wstring");
        wcout << wStr << endl;
    }
    
    //1.5 其他成员函数
    {
    /*
    1. 比较：
        s.compare (pos,n, s2);//若参与比较的两个串值相同，则函数返回 0；若字符串 s 按字典顺序要先于 s2，则返回负值；反之，则返回正值。

    2. 删除：
        erase()删除元素
	    iterator erase (iterator first, iterator last);//删除[first,end)
	    iterator erase(iterator it);//删除指定it位置的字符
	    basic_string& erase(size_type p0 = 0, size_type n = npos);//删除p0开始，长度为n的字符
    
    3. append：
        basic_string& append(const E * s); //在原始字符串后面追加字符串s
	    basic_string& append(const E * s, size_type n);//在原始字符串后面追加字符串 s 的前 n 个字符
	    basic_string& append(const basic_string& str, size_type pos, size_type n);//在原始字符串后面追加字符串 s 的子串 s [ pos,…,pos +n -1]
	    basic_string& append(const basic_string& str);
	    basic_string& append(size_type n, E c); //追加 n 个重复字符
	    basic_string& append(const_iterator first, const_iterator last); //使用迭代器追加

    4. replace:
    	basic_string& replace(size_type p0, size_type n0, const E * s); //使用字符串 s ，从源串的位置 P0 处开始替换原串额n个字符
	    basic_string& replace(size_type p0, size_type n0, const E *s, size_type n); //使用字符串 s 中的 n 个字符，从源串的位置 P0 处开始替换 1 个字符
	    basic_string& replace(size_type p0, size_type n0, const basic_string& str); //使用字符串 s 中的 n 个字符，从源串的位置 P0 处开始替换
	    basic_string& replace(size_type p0, size_type n0, const basic_string& str, size_type pos, size_type n); //使用串 str 的子串 str [pos, pos + n-1] 替换源串中的内容，从位置 p0 处开始替换，替换字符 n0 个
	    basic_string& replace(size_type p0, size_type n0, size_type n, E c); //使用 n 个字符 'c' 替换源串中位置 p0 处开始的 n0 个字符
	    basic_string& replace(iterator first0, iterator last0, const E * s);//使用迭代器替换，和 1) 用法类似
	    basic_string& replace(iterator first0, iterator last0, const E * s, size_type n);//和 2) 类似
	    basic_string& replace(iterator first0, iterator last0, const basic_string& str); //和 3) 类似
	    basic_string& replace(iterator first0, iterator last0, size_type n, E c); //和 5) 类似
	    basic_string& replace(iterator first0, iterator last0, const_iterator first, const_iterator last); //使用迭代器替换
    */
    }

    return 0;
}
