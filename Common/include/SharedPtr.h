#ifndef NIGHT00_SHAREDPTR_H
#define NIGHT00_SHAREDPTR_H

#include <atomic>

/*
 *  线程安全的shared_ptr
 *  1. 在增加引用计数和减少引用计数前，需要拿到引用对象的锁
 *  2. 析构需要减少引用计数
 *  3. 赋值运算需要减少当前对象的引用计数，增加待引用对象的引用计数
 *  4. 引用计数减到0时需要析构引用对象
 */

namespace night00
{
#define freeAndNil(p)   \
{                       \
    if (p)              \
    {                   \
        delete p;       \
        p = nullptr;    \
    }                   \
}                       

template<typename T>
class shared_ptr
{
private:
    class shared_obj
    {
        friend class night00::shared_ptr<T>;
    private:
        shared_obj(T* p)
        {
            m_p = p;
            m_count = 1;
            m_lock.store(false, std::memory_order_acquire);
        }
        ~shared_obj()
        {
            freeAndNil(m_p);
        }

        int getCount()
        {
            return m_count;
        }

        void addCount()
        {
            ++m_count;
        }

        void subCount()
        {
            --m_count;
        }
    private:
        T* m_p;                         //原生指针
        unsigned int m_count;           //引用技术
        std::atomic<bool> m_lock;       //是否已被锁住，要对shared_obj进行操作的话，必须要拿到m_lock
    };

public:
    shared_ptr(T* p)
    : m_pSharedObj(new shared_obj(p)) { }

    shared_ptr(shared_ptr<T>& sharedPtr)
    : m_pSharedObj(nullptr)
    {
        *this = sharedPtr;
    }

    ~shared_ptr()
    {
        //析构的时候，减少一个引用计数
        unRefCurObj();
    }

    shared_ptr<T>& operator=(shared_ptr<T>& sharedPtr)
    {
        //如果右值是当前智能指针，直接返回
        if(this == &sharedPtr)
        {
            return *this;
        }
        
        //先释放对当前对象的引用
        unRefCurObj();
        //添加对sharedPtr对象的引用
        refOtherObj(sharedPtr.m_pSharedObj);

        return *this;
    }

    bool operator==(shared_ptr<T>& sharedPtr)
    {
        return m_pSharedObj == sharedPtr.m_pSharedObj;
    }

    T& operator*()
    {
        return *(m_pSharedObj->m_p);
    }

    T* operator->()
    {
        return m_pSharedObj->m_p;
    }

    int getCurCount()
    {
        return m_pSharedObj->getCount();
    }
protected:
    void unRefCurObj()
    {
        if (m_pSharedObj == nullptr)
        {   //拷贝构造函数进来的话，m_pSharedObj会是空；赋值运算进来不会
            return;
        }

        //对当前智能指针管理的对象进行操作，先拿到锁
        bool bLock = false;
        while(!(m_pSharedObj->m_lock.compare_exchange_strong(bLock, true, std::memory_order_acquire)))
        {
            bLock = false;
        }

        m_pSharedObj->subCount();
        int nCount = m_pSharedObj->getCount();
        if (nCount == 0)
        {   //当前是最后一个智能指针，直接了对象
            freeAndNil(m_pSharedObj);
        } 
        else
        {   //不是最后一个智能指针，释放锁
            m_pSharedObj->m_lock.store(false, std::memory_order_release);
        }
    }

    void refOtherObj(shared_obj* pSharedObj)
    {
        if (pSharedObj == nullptr)
        {   //一般而言不会是空
            return;
        }

        bool bLock = false;
        while(!(pSharedObj->m_lock.compare_exchange_strong(bLock, true, std::memory_order_acquire)))
        {
            bLock = false;
        }
        
        pSharedObj->addCount();
        m_pSharedObj = pSharedObj;
        m_pSharedObj->m_lock.store(false, std::memory_order_release);
    }

protected:
    shared_obj* m_pSharedObj;
};

};




#endif
