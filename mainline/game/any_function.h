#ifndef __IPKN_ANY_FUNCTION_VARIATION_OF_BOOST_ANY_INCLUDED
#define __IPKN_ANY_FUNCTION_VARIATION_OF_BOOST_ANY_INCLUDED

// what:  variant type boost::any
// who:   contributed by Kevlin Henney,
//        with features contributed and bugs found by
//        Ed Brey, Mark Rodgers, Peter Dimov, and James Curran
// when:  July 2001
// where: tested with BCC 5.5, MSVC 6.0, and g++ 2.95

#include <algorithm>
#include <typeinfo>

#define boost _boost_func_of_SQLMsg
#define func_arg_type SQLMsg*
#define func_arg pmsg

namespace boost {
    class any
    {
    public: // structors

        any()
          : content(0)
        {
        }

        template<typename ValueType>
        any(const ValueType & value)
          : content(new holder<ValueType>(value))
        {
        }

        any(const any & other)
          : content(other.content ? other.content->clone() : 0)
        {
        }

        ~any()
        {
            delete content;
        }

    public: // modifiers

        any & swap(any & rhs)
        {
            std::swap(content, rhs.content);
            return *this;
        }

        template<typename ValueType>
        any & operator=(const ValueType & rhs)
        {
            any(rhs).swap(*this);
            return *this;
        }

        any & operator=(const any & rhs)
        {
            any(rhs).swap(*this);
            return *this;
        }

	void operator ()(func_arg_type func_arg)
	{
	    (*content)(func_arg);
	}

    public: // queries

        bool empty() const
        {
            return !content;
        }

    private: // types

        class placeholder
        {
        public: // structors
    
            virtual ~placeholder()
            {
            }

        public: // queries

            virtual placeholder * clone() const = 0;

	    virtual void operator()(func_arg_type func_arg) = 0;
    
        };

        template<typename ValueType>
        class holder : public placeholder
        {
        public: // structors

            holder(const ValueType & value)
              : held(value)
            {
            }

        public: // queries

            virtual placeholder * clone() const
            {
                return new holder(held);
            }

	    virtual void operator ()(func_arg_type func_arg)
	    {
		held(func_arg);
	    }

        public: // representation

            ValueType held;

        };

    private: // representation

        template<typename ValueType>
        friend ValueType * any_cast(any *);

        placeholder * content;

    };

}

#undef func_arg
#undef func_arg_type
#undef boost

typedef _boost_func_of_SQLMsg::any any_function;

#define boost2 _boost_func_of_void
#define func_arg_type2
#define func_arg2

namespace boost2 {
    class any
    {
    public: // structors

        any()
          : content(0)
        {
        }

        template<typename ValueType>
        any(const ValueType & value)
          : content(new holder<ValueType>(value))
        {
        }

        any(const any & other)
          : content(other.content ? other.content->clone() : 0)
        {
        }

        ~any()
        {
            delete content;
        }

    public: // modifiers

        any & swap(any & rhs)
        {
            std::swap(content, rhs.content);
            return *this;
        }

        template<typename ValueType>
        any & operator=(const ValueType & rhs)
        {
            any(rhs).swap(*this);
            return *this;
        }

        any & operator=(const any & rhs)
        {
            any(rhs).swap(*this);
            return *this;
        }

	void operator ()(func_arg_type2 func_arg2)
	{
	    (*content)(func_arg2);
	}

    public: // queries

        bool empty() const
        {
            return !content;
        }

    private: // types

        class placeholder
        {
        public: // structors
    
            virtual ~placeholder()
            {
            }

        public: // queries

            virtual placeholder * clone() const = 0;

	    virtual void operator()(func_arg_type2 func_arg2) = 0;
    
        };

        template<typename ValueType>
        class holder : public placeholder
        {
        public: // structors

            holder(const ValueType & value)
              : held(value)
            {
            }

        public: // queries

            virtual placeholder * clone() const
            {
                return new holder(held);
            }

	    virtual void operator ()(func_arg_type2 func_arg2)
	    {
		held(func_arg2);
	    }

        public: // representation

            ValueType held;

        };

    private: // representation

        template<typename ValueType>
        friend ValueType * any_cast(any *);

        placeholder * content;

    };

}

#undef func_arg2
#undef func_arg_type2
#undef boost2

typedef _boost_func_of_void::any any_void_function;

template <class F>
class void_binder
{
	protected:
		F f;
		typename F::argument_type value;
	public:
		void_binder(const F& f, const typename F::argument_type x)
			: f(f), value(x) {}
		void operator()() const {
			return f(value);
		}
};

	template <class F, class Arg> 
inline void_binder<F> void_bind(const F& f, const Arg& arg)
{
	typedef typename F::argument_type arg_type;
	return void_binder<F>(f, arg_type(arg));
}

#endif


