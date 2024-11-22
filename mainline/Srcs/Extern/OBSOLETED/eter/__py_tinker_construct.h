#ifndef	__PY_TINKER_CONSTRUCT__
#define	__PY_TINKER_CONSTRUCT__

#include "__py_tinker_common.h"
#include "__py_tinker_func.h"

namespace py_tinker {

template<typename CLS>
struct SConstruct0 : IFunction
{
	typedef CLS* (*NEW_INST)();

	SConstruct0(NEW_INST new_inst=__new_default) : m_new_inst(new_inst) 
	{}

	virtual ~SConstruct0() {}
	PyObject* operator()(PyObject* self, PyObject* args)
	{return PyObject_From((void*)m_new_inst());}

	static CLS* __new_default()
	{return new CLS;}

	NEW_INST m_new_inst;
};

template<typename CLS, typename ARG>
struct SConstruct1 : IFunction
{
	virtual ~SConstruct1() {}
	PyObject* operator()(PyObject* self, PyObject* args)
	{return PyObject_From((void*)new CLS(arg_<ARG>(args, 0)));}
};

template<typename CLS, typename ARG, typename ARG2>
struct SConstruct2 : IFunction
{
	virtual ~SConstruct2() {}
	PyObject* operator()(PyObject* self, PyObject* args)
	{return PyObject_From((void*)new CLS(arg_<ARG>(args, 0), arg_<ARG2>(args, 1)));}
};

template<typename CLS, typename ARG, typename ARG2, typename ARG3>
struct SConstruct3 : IFunction
{
	virtual ~SConstruct3() {}
	PyObject* operator()(PyObject* self, PyObject* args)
	{return PyObject_From((void*)new CLS(arg_<ARG>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2)));}
};

template<typename CLS, typename ARG, typename ARG2, typename ARG3, typename ARG4>
struct SConstruct4 : IFunction
{
	virtual ~SConstruct4() {}
	PyObject* operator()(PyObject* self, PyObject* args)
	{return PyObject_From((void*)new CLS(arg_<ARG>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3)));}
}; 

} // py_tinker
#endif
