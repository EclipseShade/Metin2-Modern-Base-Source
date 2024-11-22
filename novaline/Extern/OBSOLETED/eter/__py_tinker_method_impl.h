
template<typename CLS>
struct SMethod0v : IMethod
{
	typedef void (CLS::*FUNC)();

	SMethod0v(const std::string& name, FUNC func) : IMethod(name), m_func(func)	{}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{
		CLS* cpp_inst = static_cast<CLS*>(PyCppInstance_GetCppInstPtr(self));
		assert(NULL != cpp_inst);
		PYTINKER_CALL((cpp_inst->*m_func)();return PyObject_FromNone())
	}

	FUNC m_func;
};

template<typename CLS>
IMethod* PyCppMethodv(const std::string& name, void (CLS::*func)())
{return new SMethod0v<CLS>(name, func);}


template<typename CLS, typename ARG1>
struct SMethod1v : IMethod
{
	typedef void (CLS::*FUNC)(ARG1);

	SMethod1v(const std::string& name, FUNC func) : IMethod(name), m_func(func)	{}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{
		CLS* cpp_inst = static_cast<CLS*>(PyCppInstance_GetCppInstPtr(self));
		assert(NULL != cpp_inst);
		PYTINKER_CALL((cpp_inst->*m_func)(arg_<ARG1>(args, 0));return PyObject_FromNone())
	}

	FUNC m_func;
};

template<typename CLS, typename ARG1>
IMethod* PyCppMethodv(const std::string& name, void (CLS::*func)(ARG1))
{return new SMethod1v<CLS, ARG1>(name, func);}


template<typename CLS, typename ARG1, typename ARG2>
struct SMethod2v : IMethod
{
	typedef void (CLS::*FUNC)(ARG1, ARG2);

	SMethod2v(const std::string& name, FUNC func) : IMethod(name), m_func(func)	{}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{
		CLS* cpp_inst = static_cast<CLS*>(PyCppInstance_GetCppInstPtr(self));
		assert(NULL != cpp_inst);
		PYTINKER_CALL((cpp_inst->*m_func)(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1));return PyObject_FromNone())
	}

	FUNC m_func;
};

template<typename CLS, typename ARG1, typename ARG2>
IMethod* PyCppMethodv(const std::string& name, void (CLS::*func)(ARG1, ARG2))
{return new SMethod2v<CLS, ARG1, ARG2>(name, func);}


template<typename CLS, typename ARG1, typename ARG2, typename ARG3>
struct SMethod3v : IMethod
{
	typedef void (CLS::*FUNC)(ARG1, ARG2, ARG3);

	SMethod3v(const std::string& name, FUNC func) : IMethod(name), m_func(func)	{}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{
		CLS* cpp_inst = static_cast<CLS*>(PyCppInstance_GetCppInstPtr(self));
		assert(NULL != cpp_inst);
		PYTINKER_CALL((cpp_inst->*m_func)(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2));return PyObject_FromNone())
	}

	FUNC m_func;
};

template<typename CLS, typename ARG1, typename ARG2, typename ARG3>
IMethod* PyCppMethodv(const std::string& name, void (CLS::*func)(ARG1, ARG2, ARG3))
{return new SMethod3v<CLS, ARG1, ARG2, ARG3>(name, func);}


template<typename CLS, typename ARG1, typename ARG2, typename ARG3, typename ARG4>
struct SMethod4v : IMethod
{
	typedef void (CLS::*FUNC)(ARG1, ARG2, ARG3, ARG4);

	SMethod4v(const std::string& name, FUNC func) : IMethod(name), m_func(func)	{}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{
		CLS* cpp_inst = static_cast<CLS*>(PyCppInstance_GetCppInstPtr(self));
		assert(NULL != cpp_inst);
		PYTINKER_CALL((cpp_inst->*m_func)(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3));return PyObject_FromNone())
	}

	FUNC m_func;
};

template<typename CLS, typename ARG1, typename ARG2, typename ARG3, typename ARG4>
IMethod* PyCppMethodv(const std::string& name, void (CLS::*func)(ARG1, ARG2, ARG3, ARG4))
{return new SMethod4v<CLS, ARG1, ARG2, ARG3, ARG4>(name, func);}


template<typename CLS, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
struct SMethod5v : IMethod
{
	typedef void (CLS::*FUNC)(ARG1, ARG2, ARG3, ARG4, ARG5);

	SMethod5v(const std::string& name, FUNC func) : IMethod(name), m_func(func)	{}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{
		CLS* cpp_inst = static_cast<CLS*>(PyCppInstance_GetCppInstPtr(self));
		assert(NULL != cpp_inst);
		PYTINKER_CALL((cpp_inst->*m_func)(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3), arg_<ARG5>(args, 4));return PyObject_FromNone())
	}

	FUNC m_func;
};

template<typename CLS, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
IMethod* PyCppMethodv(const std::string& name, void (CLS::*func)(ARG1, ARG2, ARG3, ARG4, ARG5))
{return new SMethod5v<CLS, ARG1, ARG2, ARG3, ARG4, ARG5>(name, func);}


template<typename CLS, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
struct SMethod6v : IMethod
{
	typedef void (CLS::*FUNC)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6);

	SMethod6v(const std::string& name, FUNC func) : IMethod(name), m_func(func)	{}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{
		CLS* cpp_inst = static_cast<CLS*>(PyCppInstance_GetCppInstPtr(self));
		assert(NULL != cpp_inst);
		PYTINKER_CALL((cpp_inst->*m_func)(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3), arg_<ARG5>(args, 4), arg_<ARG6>(args, 5));return PyObject_FromNone())
	}

	FUNC m_func;
};

template<typename CLS, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
IMethod* PyCppMethodv(const std::string& name, void (CLS::*func)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6))
{return new SMethod6v<CLS, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6>(name, func);}


template<typename CLS, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7>
struct SMethod7v : IMethod
{
	typedef void (CLS::*FUNC)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7);

	SMethod7v(const std::string& name, FUNC func) : IMethod(name), m_func(func)	{}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{
		CLS* cpp_inst = static_cast<CLS*>(PyCppInstance_GetCppInstPtr(self));
		assert(NULL != cpp_inst);
		PYTINKER_CALL((cpp_inst->*m_func)(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3), arg_<ARG5>(args, 4), arg_<ARG6>(args, 5), arg_<ARG7>(args, 6));return PyObject_FromNone())
	}

	FUNC m_func;
};

template<typename CLS, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7>
IMethod* PyCppMethodv(const std::string& name, void (CLS::*func)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7))
{return new SMethod7v<CLS, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7>(name, func);}


template<typename CLS, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7, typename ARG8>
struct SMethod8v : IMethod
{
	typedef void (CLS::*FUNC)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8);

	SMethod8v(const std::string& name, FUNC func) : IMethod(name), m_func(func)	{}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{
		CLS* cpp_inst = static_cast<CLS*>(PyCppInstance_GetCppInstPtr(self));
		assert(NULL != cpp_inst);
		PYTINKER_CALL((cpp_inst->*m_func)(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3), arg_<ARG5>(args, 4), arg_<ARG6>(args, 5), arg_<ARG7>(args, 6), arg_<ARG8>(args, 7));return PyObject_FromNone())
	}

	FUNC m_func;
};

template<typename CLS, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7, typename ARG8>
IMethod* PyCppMethodv(const std::string& name, void (CLS::*func)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8))
{return new SMethod8v<CLS, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8>(name, func);}

template<typename CLS, typename RET>
struct SMethod0t : IMethod
{
	typedef RET (CLS::*FUNC)();

	SMethod0t(const std::string& name, FUNC func) : IMethod(name), m_func(func)	{}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{
		CLS* cpp_inst = static_cast<CLS*>(PyCppInstance_GetCppInstPtr(self));
		assert(NULL != cpp_inst);
		PYTINKER_CALL(return PyObject_From((cpp_inst->*m_func)()))
	}

	FUNC m_func;
};

template<typename CLS, typename RET>
IMethod* PyCppMethodt(const std::string& name, RET (CLS::*func)())
{return new SMethod0t<CLS, RET>(name, func);}


template<typename CLS, typename RET, typename ARG1>
struct SMethod1t : IMethod
{
	typedef RET (CLS::*FUNC)(ARG1);

	SMethod1t(const std::string& name, FUNC func) : IMethod(name), m_func(func)	{}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{
		CLS* cpp_inst = static_cast<CLS*>(PyCppInstance_GetCppInstPtr(self));
		assert(NULL != cpp_inst);
		PYTINKER_CALL(return PyObject_From((cpp_inst->*m_func)(arg_<ARG1>(args, 0))))
	}

	FUNC m_func;
};

template<typename CLS, typename RET, typename ARG1>
IMethod* PyCppMethodt(const std::string& name, RET (CLS::*func)(ARG1))
{return new SMethod1t<CLS, RET, ARG1>(name, func);}


template<typename CLS, typename RET, typename ARG1, typename ARG2>
struct SMethod2t : IMethod
{
	typedef RET (CLS::*FUNC)(ARG1, ARG2);

	SMethod2t(const std::string& name, FUNC func) : IMethod(name), m_func(func)	{}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{
		CLS* cpp_inst = static_cast<CLS*>(PyCppInstance_GetCppInstPtr(self));
		assert(NULL != cpp_inst);
		PYTINKER_CALL(return PyObject_From((cpp_inst->*m_func)(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1))))
	}

	FUNC m_func;
};

template<typename CLS, typename RET, typename ARG1, typename ARG2>
IMethod* PyCppMethodt(const std::string& name, RET (CLS::*func)(ARG1, ARG2))
{return new SMethod2t<CLS, RET, ARG1, ARG2>(name, func);}


template<typename CLS, typename RET, typename ARG1, typename ARG2, typename ARG3>
struct SMethod3t : IMethod
{
	typedef RET (CLS::*FUNC)(ARG1, ARG2, ARG3);

	SMethod3t(const std::string& name, FUNC func) : IMethod(name), m_func(func)	{}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{
		CLS* cpp_inst = static_cast<CLS*>(PyCppInstance_GetCppInstPtr(self));
		assert(NULL != cpp_inst);
		PYTINKER_CALL(return PyObject_From((cpp_inst->*m_func)(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2))))
	}

	FUNC m_func;
};

template<typename CLS, typename RET, typename ARG1, typename ARG2, typename ARG3>
IMethod* PyCppMethodt(const std::string& name, RET (CLS::*func)(ARG1, ARG2, ARG3))
{return new SMethod3t<CLS, RET, ARG1, ARG2, ARG3>(name, func);}


template<typename CLS, typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4>
struct SMethod4t : IMethod
{
	typedef RET (CLS::*FUNC)(ARG1, ARG2, ARG3, ARG4);

	SMethod4t(const std::string& name, FUNC func) : IMethod(name), m_func(func)	{}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{
		CLS* cpp_inst = static_cast<CLS*>(PyCppInstance_GetCppInstPtr(self));
		assert(NULL != cpp_inst);
		PYTINKER_CALL(return PyObject_From((cpp_inst->*m_func)(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3))))
	}

	FUNC m_func;
};

template<typename CLS, typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4>
IMethod* PyCppMethodt(const std::string& name, RET (CLS::*func)(ARG1, ARG2, ARG3, ARG4))
{return new SMethod4t<CLS, RET, ARG1, ARG2, ARG3, ARG4>(name, func);}


template<typename CLS, typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
struct SMethod5t : IMethod
{
	typedef RET (CLS::*FUNC)(ARG1, ARG2, ARG3, ARG4, ARG5);

	SMethod5t(const std::string& name, FUNC func) : IMethod(name), m_func(func)	{}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{
		CLS* cpp_inst = static_cast<CLS*>(PyCppInstance_GetCppInstPtr(self));
		assert(NULL != cpp_inst);
		PYTINKER_CALL(return PyObject_From((cpp_inst->*m_func)(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3), arg_<ARG5>(args, 4))))
	}

	FUNC m_func;
};

template<typename CLS, typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
IMethod* PyCppMethodt(const std::string& name, RET (CLS::*func)(ARG1, ARG2, ARG3, ARG4, ARG5))
{return new SMethod5t<CLS, RET, ARG1, ARG2, ARG3, ARG4, ARG5>(name, func);}


template<typename CLS, typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
struct SMethod6t : IMethod
{
	typedef RET (CLS::*FUNC)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6);

	SMethod6t(const std::string& name, FUNC func) : IMethod(name), m_func(func)	{}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{
		CLS* cpp_inst = static_cast<CLS*>(PyCppInstance_GetCppInstPtr(self));
		assert(NULL != cpp_inst);
		PYTINKER_CALL(return PyObject_From((cpp_inst->*m_func)(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3), arg_<ARG5>(args, 4), arg_<ARG6>(args, 5))))
	}

	FUNC m_func;
};

template<typename CLS, typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
IMethod* PyCppMethodt(const std::string& name, RET (CLS::*func)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6))
{return new SMethod6t<CLS, RET, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6>(name, func);}


template<typename CLS, typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7>
struct SMethod7t : IMethod
{
	typedef RET (CLS::*FUNC)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7);

	SMethod7t(const std::string& name, FUNC func) : IMethod(name), m_func(func)	{}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{
		CLS* cpp_inst = static_cast<CLS*>(PyCppInstance_GetCppInstPtr(self));
		assert(NULL != cpp_inst);
		PYTINKER_CALL(return PyObject_From((cpp_inst->*m_func)(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3), arg_<ARG5>(args, 4), arg_<ARG6>(args, 5), arg_<ARG7>(args, 6))))
	}

	FUNC m_func;
};

template<typename CLS, typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7>
IMethod* PyCppMethodt(const std::string& name, RET (CLS::*func)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7))
{return new SMethod7t<CLS, RET, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7>(name, func);}


template<typename CLS, typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7, typename ARG8>
struct SMethod8t : IMethod
{
	typedef RET (CLS::*FUNC)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8);

	SMethod8t(const std::string& name, FUNC func) : IMethod(name), m_func(func)	{}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{
		CLS* cpp_inst = static_cast<CLS*>(PyCppInstance_GetCppInstPtr(self));
		assert(NULL != cpp_inst);
		PYTINKER_CALL(return PyObject_From((cpp_inst->*m_func)(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3), arg_<ARG5>(args, 4), arg_<ARG6>(args, 5), arg_<ARG7>(args, 6), arg_<ARG8>(args, 7))))
	}

	FUNC m_func;
};

template<typename CLS, typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7, typename ARG8>
IMethod* PyCppMethodt(const std::string& name, RET (CLS::*func)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8))
{return new SMethod8t<CLS, RET, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8>(name, func);}
