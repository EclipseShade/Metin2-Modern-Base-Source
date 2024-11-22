#ifndef __PY_TINKER_FUNC__
#define	__PY_TINKER_FUNC__ 

#include <string>

#include "__py_tinker_common.h"

namespace py_tinker
{

struct IFunction
{
			 IFunction() {}
			 IFunction(const std::string& name) : m_name(name) {}
	virtual	~IFunction() {}
	virtual PyObject*	operator() (PyObject* self, PyObject* args) = 0;

	const std::string& GetName() {return m_name;}

	std::string m_name;
};

PyObject* PyCppFunc_FromFunction(IFunction* Function);

#include "__py_tinker_func_impl.h"

} // end of py_tinker

#endif
