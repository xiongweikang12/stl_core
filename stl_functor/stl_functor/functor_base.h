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
	//��ʾ��������
};


//���� functor���������ӿ�



#endif // !FUNCTOR_BASE
