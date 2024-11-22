#pragma once

#include "TPool.h"

template <class T>
class EL_TPooledObject
{
    public:
        typedef EL_TPool<T> SELF_TYPE;

    public:
        EL_TPooledObject()
        {
        }
        virtual ~EL_TPooledObject()
        {
        }

        void * operator new(unsigned int /*mem_size*/)
        {
            return ms_pool.Alloc();
        }
        
        void operator delete(void* pT)
        {
            ms_pool.Free((T*)pT);
        }
            
        static SELF_TYPE& GetSharedPool()
        {
            return ms_pool;
        }
        
    protected:
        static SELF_TYPE ms_pool;
};

template <class T> 
EL_TPool<T> EL_TPooledObject<T>::ms_pool;
