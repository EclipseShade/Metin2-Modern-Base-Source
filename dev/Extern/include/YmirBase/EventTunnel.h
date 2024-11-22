#pragma once

#include <list>
#pragma warning(disable:4127)  // conditional expression is constant
#include <boost/pool/pool_alloc.hpp>
#pragma warning(default:4127)

#include "EventListener.h"

enum
{
	EL_EVENT_LISTENER_ALL = (EL_EVENT_LISTENER_ID)-1,
};



EL_BOOST_PTR(EL_EventTunnel);

class EL_BASE_API EL_EventTunnel
{
public:
	EL_VOID AddEventListener(EL_EventListener* listener);
	EL_VOID DelEventListener(EL_EventListener* listener);

	EL_BOOL SendEvent(EL_EVENT_LISTENER_ID targets, const EL_EventType& type, const EL_EventData& data);

private:
	struct HashCompare
	{
		enum
		{
			bucket_size = 4,
			min_buckets = 32,
		};

		size_t operator()(const int _Key) const
		{return (size_t)_Key;}

		bool operator()(const int _Key1, const int _Key2) const
		{return _Key1 < _Key2;}

	};

private:
	typedef boost::fast_pool_allocator<int, boost::default_user_allocator_new_delete, boost::details::pool::null_mutex> Allocator;
	typedef stdext::hash_map<EL_EVENT_LISTENER_ID, EL_EventListener*, HashCompare, Allocator> EventListenerd;
	typedef std::list<EL_EventListener*, Allocator> EventListeners;

private:
	EventListeners m_listeners;
	EventListenerd m_listenerd;
};

