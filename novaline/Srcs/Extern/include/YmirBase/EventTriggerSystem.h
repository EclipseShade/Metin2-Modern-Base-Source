#pragma once

#pragma warning(disable:4127)  // conditional expression is constant
#include <boost/pool/pool_alloc.hpp>
#pragma warning(default:4127)
#include "EventTypes.h"

class EL_EventTriggerInterface;

struct EL_EventTypeCompare
{
	enum
	{
		bucket_size = 4,
		min_buckets = 32,
	};

	size_t operator()(const EL_EventType& _Key) const
	{
		return (size_t)_Key.key;
	}

	bool operator()(const EL_EventType& _Key1, const EL_EventType& _Key2) const
	{
		return _Key1.key < _Key2.key;
	}
};

typedef boost::fast_pool_allocator<EL_EventType, boost::default_user_allocator_new_delete, boost::details::pool::null_mutex> EL_EventTypeAllocator;
typedef std::multimap<EL_EventType, EL_EventTriggerInterface*, EL_EventTypeCompare, EL_EventTypeAllocator> EL_MapEventTrigger;

///////////////////////////////////////////////////////////////////////////////

class EL_BASE_API EL_EventTriggerInterface
{
public:
	virtual ~EL_EventTriggerInterface();

	virtual EL_VOID RegisterEvent(const EL_EventType& type);
	virtual EL_VOID UnregisterEvent(const EL_EventType& type);

	virtual EL_BOOL OnEvent(const EL_EventType& type, const EL_EventData& data) = 0;

private:
	std::list<EL_MapEventTrigger::iterator> m_registeredEvents;
};

///////////////////////////////////////////////////////////////////////////////

EL_BOOST_PTR(EL_EventTriggerSystem);

class EL_BASE_API EL_EventTriggerSystem
{
private:
	friend class EL_EventTriggerInterface;

	EL_MapEventTrigger m_interfaces;
	EL_MapEventTrigger::iterator __RegisterEvent(const EL_EventType& type, EL_EventTriggerInterface* kInterface);
	EL_VOID __UnregisterAllEvent(EL_EventTriggerInterface* kInterface);
	EL_VOID __UnregisterEvent(const EL_EventType& type, EL_EventTriggerInterface* kInterface);
	inline EL_MapEventTrigger::iterator __UnregisterEvent(EL_MapEventTrigger::iterator& it);

public:
	EL_BOOL TriggerEvent(const EL_EventType& type, const EL_EventData& data);
};

inline EL_MapEventTrigger::iterator EL_EventTriggerSystem::__UnregisterEvent(EL_MapEventTrigger::iterator& it)
{
	return m_interfaces.erase(it);
}

///////////////////////////////////////////////////////////////////////////////

EL_BOOST_PTR(EL_GlobalEventTriggerSystem);

class EL_BASE_API EL_GlobalEventTriggerSystem : public EL_EventTriggerSystem
{
public:
	static EL_VOID Gen();
	static EL_VOID Del();
	static EL_GlobalEventTriggerSystem& GetGlobalEventTriggerSystem();
	static EL_GlobalEventTriggerSystemPtr GetGlobalEventTriggerSystemPtr();
};

#define g_GlobalEventTriggerSystem EL_GlobalEventTriggerSystem::GetGlobalEventTriggerSystem()
///////////////////////////////////////////////////////////////////////////////
