#include <iostream>
//#include <type_traits>

template<typename T>
class iterator_traits
{
    typedef typename T::value_type value_type;
    typedef typename T::difference_type difference_type;
    typedef typename T::pointer pointer;
    typedef typename T::reference reference;
    //typedef typename T::iterator_category iterator_category;
};

template<typename T>
class iterator_traits <T*>
{
    typedef typename T value_type;
    typedef typename ptrdiff_t difference_type;
    typedef typename T* pointer;
    typedef typename T& reference;
    //typedef typename T::iterator_category iterator_category;
};

template<typename T>
class iterator_traits <const T*>
{
    typedef typename T value_type;
    typedef typename ptrdiff_t difference_type;
    typedef typename T* pointer;
    typedef typename T& reference;
    //typedef typename T::iterator_category iterator_category;
};


template<typename T>
class shared_ptr_obj
{
public:
    typedef typename iterator_traits<T>::value_type value_type; 
    typedef typename iterator_traits<T>::pointer pointer; 

    pointer m_pointer;
    unsigned int m_nCount;
};

template<typename T>
class shared_ptr
{
    shared_ptr()
    {

    }
    shared_ptr(const shared_ptr& sh_ptr)
    {
        
    }
    ~shared_ptr()
    {

    }

    shared_ptr& operator=(const shared_ptr& sh_ptr)
    {
        
    }

    T& operator*()
    {

    }

    T* operator->()
    {

    }

protected:
    shared_ptr_obj<T>* m_pSharedObj;
};
