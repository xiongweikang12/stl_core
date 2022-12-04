#ifndef Class_Function
#define Class_Function

template <typename arg1,typename arg2,typename result_arg>
struct binary_funtion
{
	typedef arg1 first_argument_type;
	typedef arg2 seconed_argument_type;
	typedef result_arg result_argument_type;
	//表示三个类型
};

template<typename T>
struct less_test :public binary_funtion<T, T, bool>
{
	result_argument_type operator()
		(const seconed_argument_type& x,
			const seconed_argument_type& y)const
	{
		return x < y;
	}
	
	//用于表示key之间的关系,
	//前提是T有<操作符的重载，
	//所以自定的数据结构作为T时需要有自身的操作符重载
};

template <typename arg1,typename result>
struct unary_funtion
{
	typedef arg1 argment;
	typedef result result_type;
};

template <typename T>
struct  idenitiy:public unary_funtion<T,T>
{
	const& argment operator()(const& argment x)
	{
		return x;
	}
	//表示key的输出形式为自身
};

template <class Pair>
struct select1st:public unary_funtion< Pair,typename Pair::first_type>
{
	const typename Pair::first_type&
		operator()(const Pair& x)const
	{
		return x.first;
	}
};












#endif // !Class_Function
