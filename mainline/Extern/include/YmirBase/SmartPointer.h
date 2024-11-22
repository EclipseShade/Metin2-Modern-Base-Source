#pragma once

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/scoped_ptr.hpp>

#define EL_BOOST_PTR(classname) \
	class classname; \
    typedef boost::shared_ptr<classname>    classname##Ptr; \
	typedef boost::weak_ptr<classname>      classname##Weak; \
	typedef boost::scoped_ptr<classname>	classname##Scoped

#define EL_BOOST_STRUCT_PTR(classname) \
	struct classname; \
    typedef boost::shared_ptr<classname>    classname##Ptr; \
	typedef boost::weak_ptr<classname>      classname##Weak; \
	typedef boost::scoped_ptr<classname>	classname##Scoped

#define EL_BOOST_NEW_SHARED_PTR(type)									static type##Ptr new_##type() {return type##Ptr(new type);}
#define EL_BOOST_NEW_SHARED_PTR1(type, arg_type)						static type##Ptr new_##type(arg_type arg) {return type##Ptr(new type(arg));}
#define EL_BOOST_NEW_SHARED_PTR2(type, arg_type, arg_type2)				static type##Ptr new_##type(arg_type arg, arg_type2 arg2) {return type##Ptr(new type(arg, arg2));}
#define EL_BOOST_NEW_SHARED_PTR3(type, arg_type, arg_type2, arg_type3)	static type##Ptr new_##type(arg_type arg, arg_type2 arg2, arg_type3 arg3) {return type##Ptr(new type(arg, arg2, arg3));}

#define EL_BOOST_CLONE(type) type##Ptr Clone() {type##Ptr newInstPtr(new type);newInstPtr->CopyMembers(*this);return newInstPtr;}