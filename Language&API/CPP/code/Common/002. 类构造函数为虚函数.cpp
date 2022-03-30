#include <iostream>
#define freeAndNil(pObj) \
{                        \
    if (pObj != nullptr) \
    {                    \
        delete pObj;     \
        pObj = nullptr;  \
    }                    \
}                             

using namespace std;

class BaseA
{
public:
    //virtual BaseA() { cout << "BaseA Construction" << endl; }     //编译不通过
    BaseA() { cout << "BaseA Construction" << endl; }
    virtual ~BaseA() { cout << "BaseA DisConstruction" << endl; }
};

class BaseB
{
public:
    BaseB() { cout << "BaseB Construction" << endl; }
    virtual ~BaseB() { cout << "BaseB DisConstruction" << endl; }
};

class MemberA
{
public:
    MemberA() { cout << "MemberA Construction" << endl; }
    virtual ~MemberA() { cout << "MemberA DisConstruction" << endl; }
};

class MemberB
{
public:
    MemberB() { cout << "MemberB Construction" << endl; }
    virtual ~MemberB() { cout << "MemberB DisConstruction" << endl; }
};

class C : public BaseA, public BaseB
{
public:
    C() : BaseB(), m_memberB(), m_memberA(), BaseA()
    { 
        cout << "C Construction" << endl; 
    }
    virtual ~C() 
    { 
        cout << "C DisConstruction" << endl; 
    }

private:
    MemberA m_memberA;
    MemberB m_memberB;
};

int main()
{
    C c;
    return 0;
}