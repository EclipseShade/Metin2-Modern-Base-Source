#ifndef	__PY_TINKER_PROPERTY__
#define	__PY_TINKER_PROPERTY__

#include "__py_tinker_common.h"

#include <string>

namespace py_tinker {

struct IProperty
{
			 IProperty(const std::string& name) : m_name(name) {}
	virtual ~IProperty() {}
	virtual void set_value(PyObject* inst, PyObject* value) = 0;
	virtual PyObject* get_value(PyObject* inst) = 0;

	const std::string& GetName() {return m_name;}

	std::string m_name;
};

PyObject* PyCppProperty_FromProperty(IProperty* cpp_property);


template<typename CLS, typename ARG>
struct SProperty : public IProperty
{
	SProperty(const std::string& name, ARG CLS::* addr) : IProperty(name), m_addr(addr) {}
	virtual ~SProperty() {}

	virtual void set_value(PyObject* inst, PyObject* value)
	{
		CLS* cpp_inst = static_cast<CLS*>(PyCppInstance_GetCppInstPtr(inst));
		assert(NULL != cpp_inst);
		PyObject_As(value, &(cpp_inst->*m_addr));			
	}
	virtual PyObject* get_value(PyObject* inst)
	{
		CLS* cpp_inst = static_cast<CLS*>(PyCppInstance_GetCppInstPtr(inst));
		assert(NULL != cpp_inst);
		return PyObject_From(cpp_inst->*m_addr);
	}

	ARG CLS::* m_addr;
};



} // py_tinker 

#endif