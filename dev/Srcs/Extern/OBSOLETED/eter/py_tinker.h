#ifndef	__PY_TINKER__
#define __PY_TINKER__

#define PYTINKER_STRICT_TYPECHECK

#if defined(_WIN32)
#ifdef _DEBUG
#pragma comment(lib, "py_tinker_d.lib")
#else
#pragma comment(lib, "py_tinker.lib")
#endif
#endif

#include "__py_tinker_common.h"
#include "__py_tinker_func.h"
#include "__py_tinker_method.h"
#include "__py_tinker_property.h"
#include "__py_tinker_construct.h"

namespace py_tinker
{

bool PyEmbed_RunMainFile(const char* c_szFileName);

struct tuple
{
	tuple()
	{m_tpl = PyTuple_New(0);Py_INCREF(m_tpl);}

	template<typename ARG>
	tuple(ARG arg)
	{
		m_tpl = PyTuple_New(1);
		PyTuple_SetItem(m_tpl, 0, PyObject_From(arg));				
	}
	template<typename ARG, typename ARG2>
	tuple(ARG arg, ARG2 arg2)
	{
		m_tpl = PyTuple_New(2);
		PyTuple_SetItem(m_tpl, 0, PyObject_From(arg));
		PyTuple_SetItem(m_tpl, 1, PyObject_From(arg2));			
	}
	template<typename ARG, typename ARG2, typename ARG3>
	tuple(ARG arg, ARG2 arg2, ARG3 arg3)
	{
		m_tpl = PyTuple_New(3);
		PyTuple_SetItem(m_tpl, 0, PyObject_From(arg));
		PyTuple_SetItem(m_tpl, 1, PyObject_From(arg2));
		PyTuple_SetItem(m_tpl, 2, PyObject_From(arg3));			
	}
	template<typename ARG, typename ARG2, typename ARG3, typename ARG4>
	tuple(ARG arg, ARG2 arg2, ARG3 arg3, ARG4 arg4)
	{
		m_tpl = PyTuple_New(4);
		PyTuple_SetItem(m_tpl, 0, PyObject_From(arg));
		PyTuple_SetItem(m_tpl, 1, PyObject_From(arg2));
		PyTuple_SetItem(m_tpl, 2, PyObject_From(arg3));
		PyTuple_SetItem(m_tpl, 3, PyObject_From(arg4));			
	}
	~tuple()	
	{
		Py_DECREF(m_tpl);
	}

	operator PyObject* ()
	{return m_tpl;}
	
	PyObject* m_tpl;
};

struct object
{
	static object none()						{return Py_None;}
	inline object() : m_obj(Py_None)			{Py_INCREF(m_obj);}
	inline object(PyObject* obj) : m_obj(obj)	{Py_INCREF(m_obj);}
	inline ~object()							{Py_DECREF(m_obj);}

	inline void operator=(PyObject* obj)		{m_obj = obj;Py_INCREF(m_obj);}
	
	inline bool operator==(PyObject* test)		{return m_obj == test;}
	inline bool operator!=(PyObject* test)		{return m_obj != test;}
	
	inline operator bool()						{return m_obj != Py_None;}
	inline operator int()						{return PyLong_AsLong(m_obj);}
	inline operator float()						{return (float)PyFloat_AsDouble(m_obj);}
	inline operator double()					{return PyFloat_AsDouble(m_obj);}
	inline operator const char*()				{return PyString_AsString(m_obj);}
	
	inline operator PyObject*()					{return m_obj;}
	inline PyObject* operator->()				{return m_obj;}	

	// operator()
	inline object operator() ()
	{static object s_args= Py_BuildValue("()");return __call(s_args);}
	
	template<typename ARG>
	inline object operator() (ARG arg) 
	{return __call(tuple(arg));}

	template<typename ARG, typename ARG2>
	inline object operator() (ARG arg, ARG2 arg2) 
	{return __call(tuple(arg, arg2));}

	template<typename ARG, typename ARG2, typename ARG3>
	inline object operator() (ARG arg, ARG2 arg2, ARG3 arg3) 
	{return __call(tuple(arg, arg2, arg3));}

	template<typename ARG, typename ARG2, typename ARG3, typename ARG4>
	inline object operator() (ARG arg, ARG2 arg2, ARG3 arg3, ARG4 arg4) 
	{return __call(tuple(arg, arg2, arg3, arg4));}

	// call_method
	template<typename ARG>
	inline object call_method(const char* method_name, ARG arg) 
	{return __call_method(method_name, tuple(arg));}

	template<typename ARG, typename ARG2>
	inline object call_method(const char* method_name, ARG arg, ARG2 arg2) 
	{return __call_method(method_name, tuple(arg, arg2));}

	template<typename ARG, typename ARG2, typename ARG3>
	inline object call_method(const char* method_name, ARG arg, ARG2 arg2, ARG3 arg3) 
	{return __call_method(method_name, tuple(arg, arg2, arg3));}

	template<typename ARG, typename ARG2, typename ARG3, typename ARG4>
	inline object call_method(const char* method_name, ARG arg, ARG2 arg2, ARG3 arg3, ARG4 arg4) 
	{return __call_method(method_name, tuple(arg, arg2, arg3, arg4));}

private:
	inline PyObject* __call(PyObject* args)
	{
		return __object_call(m_obj, args);
	}
	inline PyObject* __call_method(const char* method_name, PyObject* args)
	{
		PyObject* method = PyObject_GetAttrString(m_obj, (char*)method_name);
		if (!method)
		{
			PyErr_SetString(PyExc_AttributeError, method_name);
			throw PyTinkerException(NULL, "InPythonException");
			Py_INCREF(Py_None);return Py_None;
		}

		return __object_call(method, args);
	}
	inline static PyObject* __object_call(PyObject* func, PyObject* args)
	{
		if (!PyCallable_Check(func))
		{Py_INCREF(Py_None);return Py_None;}
		
		PyObject* ret = PyObject_Call(func, args, NULL);
		if (!ret) 
		{	
			throw PyTinkerException(NULL, "InPythonException");
			Py_INCREF(Py_None);
			return Py_None;
		}

		return ret;		
	}
	
	PyObject* m_obj;
};

struct dict
{
	dict()		{m_dct = PyDict_New();Py_INCREF(m_dct);}	
	~dict()		{Py_DECREF(m_dct);}

	void clear()	
	{PyDict_Clear(m_dct);}

	void set_item(PyObject* key, PyObject* value)
	{PyDict_SetItem(m_dct, key, value);}

	PyObject* get_item(PyObject* key)
	{return PyDict_GetItem(m_dct, key);}

	PyObject* m_dct;
};



template<typename CLS>
inline IFunction* construct0()
{return new SConstruct0<CLS>();}

template<typename CLS>
inline IFunction* construct0(CLS* (*new_inst)())
{return new SConstruct0<CLS>(new_inst);}


template<typename CLS, typename ARG>
inline IFunction* construct1()
{return new SConstruct1<CLS, ARG>();}

template<typename CLS, typename ARG, typename ARG2>
inline IFunction* construct2()
{return new SConstruct2<CLS, ARG, ARG2>();}

template<typename CLS, typename ARG, typename ARG2, typename ARG3>
inline IFunction* construct3()
{return new SConstruct3<CLS, ARG, ARG2, ARG3>();}

template<typename CLS, typename ARG, typename ARG2, typename ARG3, typename ARG4>
inline IFunction* construct4()
{return new SConstruct4<CLS, ARG, ARG2, ARG3, ARG4>();}

template<typename SELF>
struct class_
{	
	class_(const char* name)
	{
		m_name = name;
		m_cls = PyCppClass_New(name, __new_inst_default(), __delete_inst_default);
	}
	class_(const char* name, IFunction* construct, void (*del_inst)(void*)=__delete_inst_default)
	{
		m_name = name;
		m_cls = PyCppClass_New(name, construct, del_inst);
	}
	template<typename CLS, typename ARG>
	class_& def(const char* name, ARG CLS::* addr)
	{
		PyCppClass_SetAttrString(m_cls, name, PyCppProperty_FromProperty(new SProperty<CLS, ARG>(name, addr)));
		return *this;
	}
	
	template<typename FUNC>
	class_& deft(const char* name, FUNC func)
	{
		PyCppClass_SetAttrString(m_cls, name, PyCppMethod_FromMethod(PyCppMethodt(name, func)));
		return *this;
	}
	template<typename FUNC>
	class_& defv(const char* name, FUNC func)
	{
		PyCppClass_SetAttrString(m_cls, name, PyCppMethod_FromMethod(PyCppMethodv(name, func)));
		return *this;
	}

	template<typename FUNC>
	class_& STATIC_deft(const char* name, FUNC func)
	{
		PyCppClass_SetAttrString(m_cls, (char*)name, PyCppFunc_FromFunction(PyCppFunct(name, func)));
		return *this;
	}
	template<typename FUNC>
	class_& STATIC_defv(const char* name, FUNC func)
	{
		PyCppClass_SetAttrString(m_cls, (char*)name, PyCppFunc_FromFunction(PyCppFuncv(name, func)));
		return *this;
	}


	static IFunction* __new_inst_default()
	{
		return construct0<SELF>();
	}
	static void __delete_inst_default(void* ptr)
	{
		delete static_cast<SELF*>(ptr);
	}

	operator char* () const
	{return (char*)m_name;}

	operator PyObject* () const
	{return m_cls;}

	PyObject* operator -> () const
	{return m_cls;}

	static const char* m_name;
	static PyObject* m_cls;
};

template<typename CLS>
const char* class_<CLS>::m_name = NULL;

template<typename CLS>
PyObject* class_<CLS>::m_cls = NULL;

#define impl_arg_class_(TYPE) \
namespace py_tinker {\
struct type_<const TYPE&> {\
	typedef TYPE* base_type;\
	static const TYPE& cast(const base_type& r)\
	{return *r;}\
};\
struct type_<const TYPE*> {\
	typedef TYPE* base_type;\
	static const TYPE* cast(const base_type& r)\
	{return r;}\
};\
inline bool PyObject_As(PyObject* obj, TYPE** ret) {\
	if (!PyCppInstance_Check(obj))\
		return false;\
	*ret = (TYPE*)PyCppInstance_GetCppInstPtr(obj);\
	return true;\
}\
inline PyObject* PyObject_From(TYPE* src) {\
	if (!src) {Py_INCREF(Py_None);return Py_None;}\
	return PyCppInstance_FromCppInstance(class_<TYPE>::m_cls, src);\
}\
}


struct module_
{
	module_(const char* name)
	{		
		m_name = name;
		m_mod = Py_InitModule4((char*)name, NULL, NULL, NULL, PYTHON_API_VERSION);
	}
	module_& def(const char* name, PyObject* obj)
	{
		PyModule_AddObject(m_mod, (char*)name, obj);
		return *this;
	}
	module_& def(const module_& mod)
	{
		Py_INCREF(mod);
		PyModule_AddObject(m_mod, mod, mod);
		return *this;
	}
	template<typename TYPE>
	module_& def(const class_<TYPE>& cls)
	{
		PyModule_AddObject(m_mod, cls, cls);
		return *this;
	}

	template<typename FUNC>
	module_& deft(const char* name, FUNC func)
	{
		PyModule_AddObject(m_mod, (char*)name, PyCppFunc_FromFunction(PyCppFunct(name, func)));
		return *this;
	}
	template<typename FUNC>
	module_& defv(const char* name, FUNC func)
	{
		PyModule_AddObject(m_mod, (char*)name, PyCppFunc_FromFunction(PyCppFuncv(name, func)));
		return *this;
	}

#ifdef _WIN32
	template<typename FUNC>
	module_& STDCALL_deft(const char* name, FUNC func)
	{
		PyModule_AddObject(m_mod, (char*)name, PyCppFunc_FromFunction(STDCALL_PyCppFunct(name, func)));
		return *this;
	}
	template<typename FUNC>
	module_& STDCALL_defv(const char* name, FUNC func)
	{
		PyModule_AddObject(m_mod, (char*)name, PyCppFunc_FromFunction(STDCALL_PyCppFuncv(name, func)));
		return *this;
	}
#endif

	module_& defe(const char* name, const int value)
	{
		PyModule_AddIntConstant(m_mod, (char*)name, value);
		return *this;
	}

	operator char* () const
	{return (char*)m_name;}

	operator PyObject* () const
	{return m_mod;}

	PyObject* operator -> () const
	{return m_mod;}

	const char* m_name;
	PyObject* m_mod;
};

#define DEFT(t) deft(#t, t)
#define DEFV(v) defv(#v, v)
#define DEFE(e) defe(#e, e)

#ifdef _WIN32

#define STDCALL_DEFT(t) STDCALL_deft(#t, t)
#define STDCALL_DEFV(v) STDCALL_defv(#v, v)
#define STDCALL_DEFE(e) STDCALL_defe(#e, e)

#endif

} // end of py_tinker
#endif
