#ifndef	__PY_TINKER_COMMON__
#define __PY_TINKER_COMMON__

// #define USE_PYTHON_DEBUG_LIB

#define PY_TINKER_TP_DESCR_GET(t) \
    (PyType_HasFeature(t, Py_TPFLAGS_HAVE_CLASS) ? (t)->tp_descr_get : NULL)

#define PY_TINKER_TP_DESCR_SET(t) \
    (PyType_HasFeature(t, Py_TPFLAGS_HAVE_CLASS) ? (t)->tp_descr_set : NULL)


#ifdef USE_PYTHON_DEBUG_LIB
	#include <python.h>
#else
	#ifdef	_DEBUG	
		#undef	_DEBUG 
		#include <python.h>
		#define _DEBUG
	#else
		#include <python.h>
	#endif
#endif

struct PyTinkerException
{
	PyTinkerException(PyObject* exc, const char* msg) : m_exc(exc), m_msg(msg) {}
	PyObject*	m_exc;
	const char* m_msg;
};

#ifdef PYTINKER_STRICT_TYPECHECK
#include <typeinfo.h>
#define PYTINKER_CALL(s) try {s;} catch (PyTinkerException e) {if (e.m_exc) PyErr_SetString(e.m_exc, e.m_msg);return NULL;} 
#else
	#define PYTINKER_CALL(s) s;
#endif


namespace py_tinker {

inline PyObject* PyObject_FromNone()
{Py_INCREF(Py_None);return Py_None;}

inline PyObject* PyObject_From(bool value)
{return PyLong_FromLong((long)value);}

inline PyObject* PyObject_From(int value)
{return PyLong_FromLong(value);}

inline PyObject* PyObject_From(long value)
{return PyLong_FromLong(value);}

inline PyObject* PyObject_From(unsigned int value)
{return PyLong_FromUnsignedLong(value);}

inline PyObject* PyObject_From(unsigned long value)
{return PyLong_FromUnsignedLong(value);}

inline PyObject* PyObject_From(float value)
{return PyFloat_FromDouble(value);}

inline PyObject* PyObject_From(double value)
{return PyFloat_FromDouble(value);}

inline PyObject* PyObject_From(const void* value)
{return PyCObject_FromVoidPtr((void*)value, NULL);}

inline PyObject* PyObject_From(char* value)
{return PyString_FromString(value);}

inline PyObject* PyObject_From(const char* value)
{return PyString_FromString(value);}

#ifdef _XSTRING_
inline PyObject* PyObject_From(const std::string& value)
{return PyString_FromStringAndSize(value.c_str(), value.length());}
#endif

inline PyObject* PyObject_From(PyObject* value)
{Py_INCREF(value);return value;}

inline PyObject* PyObject_From(void* value)
{return PyCObject_FromVoidPtr(value, NULL);}

//////////////////////////////////////////////////////


inline bool PyObject_As(PyObject* obj, bool* ret)
{
#ifdef PYTINKER_STRICT_TYPECHECK
	if (!PyLong_Check(obj)) if (!PyInt_Check(obj)) return false;
#endif
	*ret = PyInt_AsLong(obj)!=0;
	return true;
}

inline bool PyObject_As(PyObject* obj, long* ret)
{
#ifdef PYTINKER_STRICT_TYPECHECK
	if (!PyLong_Check(obj)) if (!PyInt_Check(obj)) return false;
#endif
	*ret = PyInt_AsLong(obj);
	return true;
}

inline bool PyObject_As(PyObject* obj, float* ret)
{
#ifdef PYTINKER_STRICT_TYPECHECK
	if (!PyFloat_Check(obj)) 
		if (!PyLong_Check(obj)) 
			if (!PyInt_Check(obj)) 
				return false;
#endif
	*ret = (float)PyFloat_AsDouble(obj);
	return true;
}

inline bool PyObject_As(PyObject* obj, double* ret)
{
#ifdef PYTINKER_STRICT_TYPECHECK
	if (!PyFloat_Check(obj)) 
		if (!PyLong_Check(obj)) 
			if (!PyInt_Check(obj)) 
				return false;
#endif
	*ret = PyFloat_AsDouble(obj);
	return true;
}

inline bool PyObject_As(PyObject* obj, void** ret)
{
	if (PyString_Check(obj)) 		
	{
		*ret = PyString_AsString(obj);
		return true;
	}
	if (PyCObject_Check(obj))
	{
		*ret = PyCObject_AsVoidPtr(obj);
		return true;
	}	
	if (PyLong_Check(obj)) 
	{
		*ret = (void*)PyLong_AsLong(obj);
		return true;
	}
	if (!PyInt_Check(obj))
	{
		*ret = (void*)PyInt_AsLong(obj);
		return true;
	}
	return false;
}

inline bool PyObject_As(PyObject* obj, char** ret)
{return PyObject_As(obj, (void**)ret);}

inline bool PyObject_As(PyObject* obj, float** ret)
{return PyObject_As(obj, (void**)ret);}

inline bool PyObject_As(PyObject* obj, int* ret)
{return PyObject_As(obj, (long*)ret);}

inline bool PyObject_As(PyObject* obj, unsigned int* ret)
{return PyObject_As(obj, (long*)ret);}

inline bool PyObject_As(PyObject* obj, unsigned long* ret)
{return PyObject_As(obj, (long*)ret);}

inline bool PyObject_As(PyObject* obj, const void** ret)
{return PyObject_As(obj, (void**)ret);}

inline bool PyObject_As(PyObject* obj, const char** ret)
{return PyObject_As(obj, (void**)ret);}

inline bool PyObject_As(PyObject* obj, const float** ret)
{return PyObject_As(obj, (void**)ret);}


inline bool PyObject_As(PyObject* obj, PyObject** ret)
{
#ifdef PYTINKER_STRICT_TYPECHECK
	if (!obj)
		return false;
#endif
	*ret = obj;
	return true;
}

//////////////////////////////////////////////////////////////

template<typename T>	
struct type_init_
{static T value() {static T s_init=T();return s_init;}};

template<typename T>
struct type_ {
	typedef T base_type;

	static T cast(const base_type& src)
	{return src;}
};

struct type_init_<char*> {static char* value()			{return "empty";}};
struct type_init_<const char*> {static char* value()	{return "empty";}};

template<typename T>
inline T arg_(PyObject* args, unsigned int pos)
{
#ifdef _WIN32
	type_<T>::base_type ret = type_init_<type_<T>::base_type>::value();	
#else
	typename type_<T>::base_type ret = type_init_<typename type_<T>::base_type>::value();	
#endif
	PyObject* arg = PyTuple_GetItem(args, pos);
	if (!arg)
	{
#ifdef PYTINKER_STRICT_TYPECHECK
		char log[64];
		snprintf(log, sizeof(log)-1, "arg[%d] is empty(need %s)", pos+1, typeid(T).name());
		throw PyTinkerException(PyExc_TypeError, log);
#endif
		return type_<T>::cast(ret);
	}
	if (!PyObject_As(arg, &ret))
	{
#ifdef PYTINKER_STRICT_TYPECHECK
		char log[64];
		snprintf(log, sizeof(log)-1, "arg[%d] is not %s", pos+1, typeid(T).name());
		throw PyTinkerException(PyExc_TypeError, log);
#endif
		return type_<T>::cast(ret);
	}
	
	return type_<T>::cast(ret);
}



} // py_tinker

#endif
