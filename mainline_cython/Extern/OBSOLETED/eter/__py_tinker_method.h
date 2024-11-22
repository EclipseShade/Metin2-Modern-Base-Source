#ifndef	__PY_TINKER_METHOD__
#define	__PY_TINKER_METHOD__

#include "__py_tinker_common.h"

#include <string>

namespace py_tinker {

extern "C" {

struct IFunction;

PyObject*	PyCppClass_New(const char* name, IFunction* new_cpp_inst, void (*del_cpp_inst)(void*));
int			PyCppClass_SetAttrString(PyObject* cls, const char* name, PyObject* value);

PyObject*	PyCppInstance_FromCppInstance(PyObject* cls, void* cpp_inst);
void*		PyCppInstance_GetCppInstPtr(PyObject* inst);
bool		PyCppInstance_Check(PyObject* inst);

}

struct IMethod
{
			 IMethod(const std::string& name) : m_name(name) {}
	virtual ~IMethod() {}
	virtual PyObject* operator() (PyObject* self, PyObject* args) = 0;

	const std::string& GetName() {return m_name;}

	std::string m_name;

};

PyObject* PyCppMethod_FromMethod(IMethod* cpp_method);

#include "__py_tinker_method_impl.h"

} // py_tinker

#endif
