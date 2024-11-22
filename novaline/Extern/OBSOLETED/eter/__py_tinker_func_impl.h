

struct SFunction0v : IFunction
{
	typedef void (*FUNC)();

	SFunction0v(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(m_func();return PyObject_FromNone())}

	FUNC m_func;
};

inline
IFunction* PyCppFuncv(const std::string& name, void (*func)())
{return new SFunction0v(name, func);}


template<typename ARG1>
struct SFunction1v : IFunction
{
	typedef void (*FUNC)(ARG1);

	SFunction1v(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(m_func(arg_<ARG1>(args, 0));return PyObject_FromNone())}

	FUNC m_func;
};

template<typename ARG1>
IFunction* PyCppFuncv(const std::string& name, void (*func)(ARG1))
{return new SFunction1v<ARG1>(name, func);}


template<typename ARG1, typename ARG2>
struct SFunction2v : IFunction
{
	typedef void (*FUNC)(ARG1, ARG2);

	SFunction2v(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1));return PyObject_FromNone())}

	FUNC m_func;
};

template<typename ARG1, typename ARG2>
IFunction* PyCppFuncv(const std::string& name, void (*func)(ARG1, ARG2))
{return new SFunction2v<ARG1, ARG2>(name, func);}


template<typename ARG1, typename ARG2, typename ARG3>
struct SFunction3v : IFunction
{
	typedef void (*FUNC)(ARG1, ARG2, ARG3);

	SFunction3v(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2));return PyObject_FromNone())}

	FUNC m_func;
};

template<typename ARG1, typename ARG2, typename ARG3>
IFunction* PyCppFuncv(const std::string& name, void (*func)(ARG1, ARG2, ARG3))
{return new SFunction3v<ARG1, ARG2, ARG3>(name, func);}


template<typename ARG1, typename ARG2, typename ARG3, typename ARG4>
struct SFunction4v : IFunction
{
	typedef void (*FUNC)(ARG1, ARG2, ARG3, ARG4);

	SFunction4v(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3));return PyObject_FromNone())}

	FUNC m_func;
};

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4>
IFunction* PyCppFuncv(const std::string& name, void (*func)(ARG1, ARG2, ARG3, ARG4))
{return new SFunction4v<ARG1, ARG2, ARG3, ARG4>(name, func);}


template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
struct SFunction5v : IFunction
{
	typedef void (*FUNC)(ARG1, ARG2, ARG3, ARG4, ARG5);

	SFunction5v(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3), arg_<ARG5>(args, 4));return PyObject_FromNone())}

	FUNC m_func;
};

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
IFunction* PyCppFuncv(const std::string& name, void (*func)(ARG1, ARG2, ARG3, ARG4, ARG5))
{return new SFunction5v<ARG1, ARG2, ARG3, ARG4, ARG5>(name, func);}


template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
struct SFunction6v : IFunction
{
	typedef void (*FUNC)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6);

	SFunction6v(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3), arg_<ARG5>(args, 4), arg_<ARG6>(args, 5));return PyObject_FromNone())}

	FUNC m_func;
};

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
IFunction* PyCppFuncv(const std::string& name, void (*func)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6))
{return new SFunction6v<ARG1, ARG2, ARG3, ARG4, ARG5, ARG6>(name, func);}


template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7>
struct SFunction7v : IFunction
{
	typedef void (*FUNC)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7);

	SFunction7v(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3), arg_<ARG5>(args, 4), arg_<ARG6>(args, 5), arg_<ARG7>(args, 6));return PyObject_FromNone())}

	FUNC m_func;
};

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7>
IFunction* PyCppFuncv(const std::string& name, void (*func)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7))
{return new SFunction7v<ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7>(name, func);}


template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7, typename ARG8>
struct SFunction8v : IFunction
{
	typedef void (*FUNC)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8);

	SFunction8v(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3), arg_<ARG5>(args, 4), arg_<ARG6>(args, 5), arg_<ARG7>(args, 6), arg_<ARG8>(args, 7));return PyObject_FromNone())}

	FUNC m_func;
};

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7, typename ARG8>
IFunction* PyCppFuncv(const std::string& name, void (*func)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8))
{return new SFunction8v<ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8>(name, func);}

template<typename RET>
struct SFunction0t : IFunction
{
	typedef RET (*FUNC)();

	SFunction0t(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(return PyObject_From(m_func()))}

	FUNC m_func;
};

template<typename RET>
IFunction* PyCppFunct(const std::string& name, RET (*func)())
{return new SFunction0t<RET>(name, func);}


template<typename RET, typename ARG1>
struct SFunction1t : IFunction
{
	typedef RET (*FUNC)(ARG1);

	SFunction1t(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(return PyObject_From(m_func(arg_<ARG1>(args, 0))))}

	FUNC m_func;
};

template<typename RET, typename ARG1>
IFunction* PyCppFunct(const std::string& name, RET (*func)(ARG1))
{return new SFunction1t<RET, ARG1>(name, func);}


template<typename RET, typename ARG1, typename ARG2>
struct SFunction2t : IFunction
{
	typedef RET (*FUNC)(ARG1, ARG2);

	SFunction2t(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(return PyObject_From(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1))))}

	FUNC m_func;
};

template<typename RET, typename ARG1, typename ARG2>
IFunction* PyCppFunct(const std::string& name, RET (*func)(ARG1, ARG2))
{return new SFunction2t<RET, ARG1, ARG2>(name, func);}


template<typename RET, typename ARG1, typename ARG2, typename ARG3>
struct SFunction3t : IFunction
{
	typedef RET (*FUNC)(ARG1, ARG2, ARG3);

	SFunction3t(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(return PyObject_From(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2))))}

	FUNC m_func;
};

template<typename RET, typename ARG1, typename ARG2, typename ARG3>
IFunction* PyCppFunct(const std::string& name, RET (*func)(ARG1, ARG2, ARG3))
{return new SFunction3t<RET, ARG1, ARG2, ARG3>(name, func);}


template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4>
struct SFunction4t : IFunction
{
	typedef RET (*FUNC)(ARG1, ARG2, ARG3, ARG4);

	SFunction4t(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(return PyObject_From(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3))))}

	FUNC m_func;
};

template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4>
IFunction* PyCppFunct(const std::string& name, RET (*func)(ARG1, ARG2, ARG3, ARG4))
{return new SFunction4t<RET, ARG1, ARG2, ARG3, ARG4>(name, func);}


template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
struct SFunction5t : IFunction
{
	typedef RET (*FUNC)(ARG1, ARG2, ARG3, ARG4, ARG5);

	SFunction5t(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(return PyObject_From(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3), arg_<ARG5>(args, 4))))}

	FUNC m_func;
};

template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
IFunction* PyCppFunct(const std::string& name, RET (*func)(ARG1, ARG2, ARG3, ARG4, ARG5))
{return new SFunction5t<RET, ARG1, ARG2, ARG3, ARG4, ARG5>(name, func);}


template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
struct SFunction6t : IFunction
{
	typedef RET (*FUNC)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6);

	SFunction6t(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(return PyObject_From(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3), arg_<ARG5>(args, 4), arg_<ARG6>(args, 5))))}

	FUNC m_func;
};

template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
IFunction* PyCppFunct(const std::string& name, RET (*func)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6))
{return new SFunction6t<RET, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6>(name, func);}


template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7>
struct SFunction7t : IFunction
{
	typedef RET (*FUNC)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7);

	SFunction7t(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(return PyObject_From(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3), arg_<ARG5>(args, 4), arg_<ARG6>(args, 5), arg_<ARG7>(args, 6))))}

	FUNC m_func;
};

template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7>
IFunction* PyCppFunct(const std::string& name, RET (*func)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7))
{return new SFunction7t<RET, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7>(name, func);}


template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7, typename ARG8>
struct SFunction8t : IFunction
{
	typedef RET (*FUNC)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8);

	SFunction8t(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(return PyObject_From(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3), arg_<ARG5>(args, 4), arg_<ARG6>(args, 5), arg_<ARG7>(args, 6), arg_<ARG8>(args, 7))))}

	FUNC m_func;
};

template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7, typename ARG8>
IFunction* PyCppFunct(const std::string& name, RET (*func)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8))
{return new SFunction8t<RET, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8>(name, func);}

#ifdef _WIN32


struct STDCALL_SFunction0v : IFunction
{
	typedef void (__stdcall *FUNC)();

	STDCALL_SFunction0v(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(m_func();return PyObject_FromNone())}

	FUNC m_func;
};

inline
IFunction* STDCALL_PyCppFuncv(const std::string& name, void (__stdcall *func)())
{return new STDCALL_SFunction0v(name, func);}


template<typename ARG1>
struct STDCALL_SFunction1v : IFunction
{
	typedef void (__stdcall *FUNC)(ARG1);

	STDCALL_SFunction1v(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(m_func(arg_<ARG1>(args, 0));return PyObject_FromNone())}

	FUNC m_func;
};

template<typename ARG1>
IFunction* STDCALL_PyCppFuncv(const std::string& name, void (__stdcall *func)(ARG1))
{return new STDCALL_SFunction1v<ARG1>(name, func);}


template<typename ARG1, typename ARG2>
struct STDCALL_SFunction2v : IFunction
{
	typedef void (__stdcall *FUNC)(ARG1, ARG2);

	STDCALL_SFunction2v(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1));return PyObject_FromNone())}

	FUNC m_func;
};

template<typename ARG1, typename ARG2>
IFunction* STDCALL_PyCppFuncv(const std::string& name, void (__stdcall *func)(ARG1, ARG2))
{return new STDCALL_SFunction2v<ARG1, ARG2>(name, func);}


template<typename ARG1, typename ARG2, typename ARG3>
struct STDCALL_SFunction3v : IFunction
{
	typedef void (__stdcall *FUNC)(ARG1, ARG2, ARG3);

	STDCALL_SFunction3v(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2));return PyObject_FromNone())}

	FUNC m_func;
};

template<typename ARG1, typename ARG2, typename ARG3>
IFunction* STDCALL_PyCppFuncv(const std::string& name, void (__stdcall *func)(ARG1, ARG2, ARG3))
{return new STDCALL_SFunction3v<ARG1, ARG2, ARG3>(name, func);}


template<typename ARG1, typename ARG2, typename ARG3, typename ARG4>
struct STDCALL_SFunction4v : IFunction
{
	typedef void (__stdcall *FUNC)(ARG1, ARG2, ARG3, ARG4);

	STDCALL_SFunction4v(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3));return PyObject_FromNone())}

	FUNC m_func;
};

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4>
IFunction* STDCALL_PyCppFuncv(const std::string& name, void (__stdcall *func)(ARG1, ARG2, ARG3, ARG4))
{return new STDCALL_SFunction4v<ARG1, ARG2, ARG3, ARG4>(name, func);}


template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
struct STDCALL_SFunction5v : IFunction
{
	typedef void (__stdcall *FUNC)(ARG1, ARG2, ARG3, ARG4, ARG5);

	STDCALL_SFunction5v(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3), arg_<ARG5>(args, 4));return PyObject_FromNone())}

	FUNC m_func;
};

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
IFunction* STDCALL_PyCppFuncv(const std::string& name, void (__stdcall *func)(ARG1, ARG2, ARG3, ARG4, ARG5))
{return new STDCALL_SFunction5v<ARG1, ARG2, ARG3, ARG4, ARG5>(name, func);}


template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
struct STDCALL_SFunction6v : IFunction
{
	typedef void (__stdcall *FUNC)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6);

	STDCALL_SFunction6v(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3), arg_<ARG5>(args, 4), arg_<ARG6>(args, 5));return PyObject_FromNone())}

	FUNC m_func;
};

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
IFunction* STDCALL_PyCppFuncv(const std::string& name, void (__stdcall *func)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6))
{return new STDCALL_SFunction6v<ARG1, ARG2, ARG3, ARG4, ARG5, ARG6>(name, func);}


template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7>
struct STDCALL_SFunction7v : IFunction
{
	typedef void (__stdcall *FUNC)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7);

	STDCALL_SFunction7v(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3), arg_<ARG5>(args, 4), arg_<ARG6>(args, 5), arg_<ARG7>(args, 6));return PyObject_FromNone())}

	FUNC m_func;
};

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7>
IFunction* STDCALL_PyCppFuncv(const std::string& name, void (__stdcall *func)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7))
{return new STDCALL_SFunction7v<ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7>(name, func);}


template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7, typename ARG8>
struct STDCALL_SFunction8v : IFunction
{
	typedef void (__stdcall *FUNC)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8);

	STDCALL_SFunction8v(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3), arg_<ARG5>(args, 4), arg_<ARG6>(args, 5), arg_<ARG7>(args, 6), arg_<ARG8>(args, 7));return PyObject_FromNone())}

	FUNC m_func;
};

template<typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7, typename ARG8>
IFunction* STDCALL_PyCppFuncv(const std::string& name, void (__stdcall *func)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8))
{return new STDCALL_SFunction8v<ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8>(name, func);}

template<typename RET>
struct STDCALL_SFunction0t : IFunction
{
	typedef RET (__stdcall *FUNC)();

	STDCALL_SFunction0t(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(return PyObject_From(m_func()))}

	FUNC m_func;
};

template<typename RET>
IFunction* STDCALL_PyCppFunct(const std::string& name, RET (__stdcall *func)())
{return new STDCALL_SFunction0t<RET>(name, func);}


template<typename RET, typename ARG1>
struct STDCALL_SFunction1t : IFunction
{
	typedef RET (__stdcall *FUNC)(ARG1);

	STDCALL_SFunction1t(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(return PyObject_From(m_func(arg_<ARG1>(args, 0))))}

	FUNC m_func;
};

template<typename RET, typename ARG1>
IFunction* STDCALL_PyCppFunct(const std::string& name, RET (__stdcall *func)(ARG1))
{return new STDCALL_SFunction1t<RET, ARG1>(name, func);}


template<typename RET, typename ARG1, typename ARG2>
struct STDCALL_SFunction2t : IFunction
{
	typedef RET (__stdcall *FUNC)(ARG1, ARG2);

	STDCALL_SFunction2t(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(return PyObject_From(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1))))}

	FUNC m_func;
};

template<typename RET, typename ARG1, typename ARG2>
IFunction* STDCALL_PyCppFunct(const std::string& name, RET (__stdcall *func)(ARG1, ARG2))
{return new STDCALL_SFunction2t<RET, ARG1, ARG2>(name, func);}


template<typename RET, typename ARG1, typename ARG2, typename ARG3>
struct STDCALL_SFunction3t : IFunction
{
	typedef RET (__stdcall *FUNC)(ARG1, ARG2, ARG3);

	STDCALL_SFunction3t(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(return PyObject_From(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2))))}

	FUNC m_func;
};

template<typename RET, typename ARG1, typename ARG2, typename ARG3>
IFunction* STDCALL_PyCppFunct(const std::string& name, RET (__stdcall *func)(ARG1, ARG2, ARG3))
{return new STDCALL_SFunction3t<RET, ARG1, ARG2, ARG3>(name, func);}


template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4>
struct STDCALL_SFunction4t : IFunction
{
	typedef RET (__stdcall *FUNC)(ARG1, ARG2, ARG3, ARG4);

	STDCALL_SFunction4t(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(return PyObject_From(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3))))}

	FUNC m_func;
};

template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4>
IFunction* STDCALL_PyCppFunct(const std::string& name, RET (__stdcall *func)(ARG1, ARG2, ARG3, ARG4))
{return new STDCALL_SFunction4t<RET, ARG1, ARG2, ARG3, ARG4>(name, func);}


template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
struct STDCALL_SFunction5t : IFunction
{
	typedef RET (__stdcall *FUNC)(ARG1, ARG2, ARG3, ARG4, ARG5);

	STDCALL_SFunction5t(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(return PyObject_From(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3), arg_<ARG5>(args, 4))))}

	FUNC m_func;
};

template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5>
IFunction* STDCALL_PyCppFunct(const std::string& name, RET (__stdcall *func)(ARG1, ARG2, ARG3, ARG4, ARG5))
{return new STDCALL_SFunction5t<RET, ARG1, ARG2, ARG3, ARG4, ARG5>(name, func);}


template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
struct STDCALL_SFunction6t : IFunction
{
	typedef RET (__stdcall *FUNC)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6);

	STDCALL_SFunction6t(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(return PyObject_From(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3), arg_<ARG5>(args, 4), arg_<ARG6>(args, 5))))}

	FUNC m_func;
};

template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6>
IFunction* STDCALL_PyCppFunct(const std::string& name, RET (__stdcall *func)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6))
{return new STDCALL_SFunction6t<RET, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6>(name, func);}


template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7>
struct STDCALL_SFunction7t : IFunction
{
	typedef RET (__stdcall *FUNC)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7);

	STDCALL_SFunction7t(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(return PyObject_From(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3), arg_<ARG5>(args, 4), arg_<ARG6>(args, 5), arg_<ARG7>(args, 6))))}

	FUNC m_func;
};

template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7>
IFunction* STDCALL_PyCppFunct(const std::string& name, RET (__stdcall *func)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7))
{return new STDCALL_SFunction7t<RET, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7>(name, func);}


template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7, typename ARG8>
struct STDCALL_SFunction8t : IFunction
{
	typedef RET (__stdcall *FUNC)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8);

	STDCALL_SFunction8t(const std::string& name, FUNC func) : IFunction(name), m_func(func) {}

	virtual PyObject*	operator() (PyObject* self, PyObject* args)
	{PYTINKER_CALL(return PyObject_From(m_func(arg_<ARG1>(args, 0), arg_<ARG2>(args, 1), arg_<ARG3>(args, 2), arg_<ARG4>(args, 3), arg_<ARG5>(args, 4), arg_<ARG6>(args, 5), arg_<ARG7>(args, 6), arg_<ARG8>(args, 7))))}

	FUNC m_func;
};

template<typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, typename ARG6, typename ARG7, typename ARG8>
IFunction* STDCALL_PyCppFunct(const std::string& name, RET (__stdcall *func)(ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8))
{return new STDCALL_SFunction8t<RET, ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7, ARG8>(name, func);}
#endif
