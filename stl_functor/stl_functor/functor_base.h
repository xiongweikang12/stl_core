#ifndef FUNCTOR_BASE
#define FUNCTOR_BASE

template <typename arg1, typename result>
struct unary_funtion_test
{
	typedef arg1 argment;
	typedef result result_type;
};

template <typename arg1, typename arg2, typename result_arg>
struct binary_funtion_test
{
	typedef arg1 first_argument_type;
	typedef arg2 seconed_argument_type;
	typedef result_arg result_argument_type;
	//表示三个类型
};


//对于 functor的适配器接口



#endif // !FUNCTOR_BASE
