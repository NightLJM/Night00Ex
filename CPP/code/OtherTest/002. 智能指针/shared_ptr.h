#include <iostream>
//#include <type_traits>

template<typename T>       //T是指针或迭代器类型
class iterator_traits
{
public:
    typedef typename T::value_type value_type;
    typedef typename T::difference_type difference_type;
    typedef typename T::pointer pointer;
    typedef typename T::reference reference;
    //typedef typename T::iterator_category iterator_category;
};

template<typename T>            //T是指针或迭代器类型
class iterator_traits<T*>
{
public:
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T* pointer;
    typedef T& reference;
    //typedef typename T::iterator_category iterator_category;
};

template<typename T>            //T是指针或迭代器类型
class iterator_traits<const T*>
{
public:
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T* pointer;
    typedef T& reference;
    //typedef typename T::iterator_category iterator_category;
};


template<typename T>            //T是指针或迭代器类型
class shared_ptr_obj
{
public:
    typedef typename iterator_traits<T>::value_type value_type; 
    typedef typename iterator_traits<T>::pointer pointer; 

    shared_ptr_obj(pointer pPointer) : m_pointer(pPointer), m_nCount(1)
    {
    }
    ~shared_ptr_obj()
    {
        if (m_pointer)
        {
            delete m_pointer;
            m_pointer = 0;
        }
    }
    shared_ptr_obj& operator++()
    {
        ++m_nCount;
        return *this;
    }
    shared_ptr_obj& operator--()
    {
        --m_nCount;
        return *this;
    }

    pointer m_pointer;
    unsigned int m_nCount;
};

template<typename T>    //T是智能指针指向的对象类型
class shared_ptr
{
protected:
    shared_ptr_obj<T*>* m_pSharedObj;

public:
    shared_ptr(T* pT) : m_pSharedObj(new shared_ptr_obj<T*>(pT))
    {
        
    }
    shared_ptr(const shared_ptr& sh_ptr)
    {
        (*this) = sh_ptr;
    }
    ~shared_ptr()
    {
        if (m_pSharedObj)
        {
            --(*m_pSharedObj);
        }
        if (m_pSharedObj->m_nCount == 0)
        {
            delete m_pSharedObj;
        }
    }

    shared_ptr& operator=(const shared_ptr& sh_ptr)
    {
        if (this == (&sh_ptr))
        {
            return *this;
        }
        if (m_pSharedObj)
        {
            --(*m_pSharedObj);
        }
        m_pSharedObj = sh_ptr.m_pSharedObj;
        if (m_pSharedObj)
        {
            ++(*m_pSharedObj);
        }

        return *this;
    }

    T& operator*()
    {
        return *(m_pSharedObj->m_pointer);
    }

    T* operator->()
    {
        return m_pSharedObj->m_pointer;
    }
};
