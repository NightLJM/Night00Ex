#include "001.gflags_test.h"
#include <iostream>
//using namespace std;

//g++ 001.gflags_test.cpp -o a.out -lgflags

void printParm()
{
    std::cout << FLAGS_bool_parm << std::endl;
    std::cout << FLAGS_string_parm << std::endl;
    std::cout << FLAGS_int_parm << std::endl;
}

static bool bool_check(const char* flag_name, bool value)
{
    if (value == true)
    {
        std::cout << "pthread(" << pthread_self() << "):" << flag_name << "should be false!" << std::endl;
        return false;
    }
    else 
    {
        return true;
    }
}

static bool string_check(const char* flag_name, const std::string& value)
{
    if (value.size() == 0)
    {
        std::cout << "pthread(" << pthread_self() << "):" << flag_name << "should not be empty!" << std::endl;
        return false;
    }
    else
    {
        return true;
    }
    
}

static bool int_check(const char* flag_name, google::int64 value)
{
    if (value == -1)
    {
        std::cout << "pthread(" << pthread_self() << "):" << flag_name << "should not be -1!" << std::endl;
        return false;
    }
    else
    {
        return true;
    }
    
}


void doRegisterValidCheck()
{
    google::RegisterFlagValidator(&FLAGS_bool_parm, &bool_check);
    google::RegisterFlagValidator(&FLAGS_string_parm, &string_check);
    google::RegisterFlagValidator(&FLAGS_int_parm, &int_check);
}

int main(int argc, char** argv)
{
    doRegisterValidCheck(); //先检查，后注册
    std::cout << "---1---" << std::endl;
    google::ParseCommandLineFlags(&argc, &argv, true);      //这句注掉的话命令行参数无效，也不会进行错误检查
    std::cout << "---2---" << std::endl;
    printParm();
    std::cout << "---3---" << std::endl;
    google::ShutDownCommandLineFlags();
    std::cout << "---4---" << std::endl;
    return 0;
}