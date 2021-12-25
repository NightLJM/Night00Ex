#include <iostream>
#include "gmock/gmock.h"
#include "gtest/gtest.h"
using namespace std;
using namespace testing;

class AClass
{
public:
    virtual ~AClass() { }
    virtual void fun1() { std::cout << "fun1" << endl;}
    virtual void fun2(int x) { std::cout << "fun2: " << x << std::endl;}
};

class B
{
public:
    void fun(AClass* pA)
    {
        if (pA)
        {
            pA->fun1();
            pA->fun2(123);
        }
    }
};

class MockMyClass : public AClass
{
public:
    MOCK_METHOD(void, fun1, (), (override));
    MOCK_METHOD(void, fun2, (int x), (override));
};

using ::testing::AtLeast;

TEST(MockTest, Test_Fun1_Fun2)
{
    MockMyClass mockObj;
    //EXPECT_CALL(mockObj, fun1()).Times(AtLeast(1));

    B b;
    b.fun(&mockObj);
}

// int main(int argc, char** argv)
// {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }