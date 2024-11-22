#pragma once

#include "Log.h"

template<typename T>
class EL_TPool
{   
    public:
        EL_TPool()
        {
            m_initCapacity = 0;
            m_usedCapacity = 0;
            m_usedPreserve = 0;
            m_maxPreserve = 0;
            m_restAllocCount = 0;

            m_preserve = NULL;            
        }
        ~EL_TPool()
        {
			/*
			EL_C_ACHAR_P namez = typeid(T).name();
			EL_LOG_SPECIAL(EL_TEXT("%s: cap(init=%d, used=%d), pre(used=%d, max=%d), rest(%d)"),
				namez,
				m_initCapacity, m_usedCapacity,
				m_usedPreserve, m_maxPreserve,
				m_restAllocCount);
			free((EL_VOID_P)namez);
			*/
            Clear();
        }

        void SetStrictFreeCheck(bool isEnable)
        {
            m_isEnableStrictFreeCheck = isEnable
        }

        void Clear()
        {
			EL_SAFE_DELETE_ARRAY(m_preserve);
			m_usedPreserve = 0;
            
            std::for_each(m_datas.begin(), m_datas.end(), __DeleteData);
            m_datas.clear();
            m_frees.clear();
        }

        EL_TPool<T>& InitCapacity(EL_SIZE capacity)
        {
            m_initCapacity = capacity;

            m_datas.reserve(m_initCapacity);
            m_frees.reserve(m_initCapacity);

			return *this;
        }
        EL_TPool<T>& InitPreserve(EL_SIZE preserveSize)
        {
            m_maxPreserve = preserveSize;

            m_usedPreserve = 0;
            
            if (m_maxPreserve > 0)
            {
                if (NULL != m_preserve)
                    delete [] m_preserve;
                    
                m_preserve = new EL_UINT8[sizeof(T)*m_maxPreserve];
            }           

			return *this;
        }

        T* Alloc()
        {
#ifdef _DEBUG
            ++m_restAllocCount;
#endif
            if (m_frees.empty())
            {
                T* pkNewData = NULL;
                
                if (m_usedPreserve < m_maxPreserve)
                {
                    pkNewData = ((T*)m_preserve) + (m_usedPreserve++);                   
                }
                else
                {
                    pkNewData = __NewData();                
                    m_datas.push_back(pkNewData);
                }
                ++m_usedCapacity;
                return pkNewData;
            }

            T* pkFreeData = m_frees.back();
            m_frees.pop_back();
            return pkFreeData;
        }
        void Free(T* data)
        {           
#ifdef _DEBUG
            --m_restAllocCount;

            if (m_isEnableStrictFreeCheck)
            {
                assert(__IsValidData(data));
                assert(!__IsFreeData(data));
            }
#endif
            m_frees.push_back(data);
        }

        void FreeAll()
        {
            m_frees = m_datas;
            m_usedPreserve = 0;
            m_restAllocCount = 0;
        }
        
        EL_SIZE GetAllocCount()
        {
            return m_datas.size() + m_usedPreserve;
        }

    protected:
        bool __IsValidData(T* data)
        {
            if (data >= ((T*)m_preserve) && data < ((T*)m_preserve) + m_maxPreserve)
                return true;

            if (m_datas.end() == std::find(m_datas.begin(), m_datas.end(), data))
                return false;
            return true;
        }
        bool __IsFreeData(T* data)
        {
            if (m_frees.end() == std::find(m_frees.begin(), m_frees.end(), data))
                return false;

            return true;
        }

        static T* __NewData()
        {
            return (T*)::operator new(sizeof(T));
        }

        static void __DeleteData(T* data)
        {
            ::operator delete(data);          
        }

    private:
		typedef std::vector<T*> Items;

	private:
        Items m_datas;
        Items m_frees;

        EL_UINT8* m_preserve;

        EL_SIZE m_usedPreserve;
        EL_SIZE m_maxPreserve;
        EL_SIZE m_initCapacity;
        EL_SIZE m_usedCapacity;
        EL_SIZE m_restAllocCount;

        EL_BOOL m_isEnableStrictFreeCheck;
};