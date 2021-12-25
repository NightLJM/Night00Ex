#include <iostream>
#include <pthread.h>
#include "../../include/SharedPtr.h"
#define THREAD_NUM 100

void* threadFun(void* sharedPtr)
{
    night00::shared_ptr<int> localPtr = *(static_cast<night00::shared_ptr<int>*>(sharedPtr));
    ++(*localPtr);
    std::cout << "pthread id: " << pthread_self() << std::endl;
    std::cout << "shared_ptr's count: " << localPtr.getCurCount() << std::endl;
    std::cout << "shared_ptr's value: " << *localPtr<< std::endl;
    return nullptr;
}


int main()
{
    int *pI = new int(1);
    night00::shared_ptr<int> sharedPtr(pI);

    pthread_t threads[THREAD_NUM];
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    for (int i = 0; i < THREAD_NUM; ++i)
    {
        int ret = pthread_create(&threads[i], &attr, threadFun, (void*)&sharedPtr);
    }

    for (int i = 0; i < THREAD_NUM; ++i)
    {
        pthread_join(threads[i], nullptr);
    }
    pthread_attr_destroy(&attr);

    {
        std::cout << "----------main function will exit ---------" << std::endl;
        std::cout << "pthread id: " << pthread_self() << std::endl;
        std::cout << "shared_ptr's count: " << sharedPtr.getCurCount() << std::endl;
        std::cout << "shared_ptr's value: " << *sharedPtr<< std::endl;
    }

    return 0;
}