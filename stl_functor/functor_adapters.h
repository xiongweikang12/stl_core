#ifndef FUNCTOR_ADAPTERS
#define	FUNCTOR_ADAPTERS

#include "functor.h"

//������ӵĶ�Ԫ����ת����һԪ����


template<class operation>
class bind1st_test:public unary_funtion_test<typename operation::first_argument_type,typename operation::result_argument_type>
{
protected:
	operation op;
	typename operation::first_argument_type value;
public:
	typedef typename  operation::first_argument_type first_argument_type;
	typedef typename	operation::result_argument_type  result_argument_type;
	bind1st_test(const operation& x, const typename operation::seconed_argument_type& y)
		:op(x), value(y)
	{
		//��ʾ�����˵�һ�������ڶ�����ָ��;
	}//���캯��

	bind1st_test(const bind1st_test& test)
	{
		this->op = test.op;
		this->value = test.value;
	}
	//�����캯�� 


	const typename operation::result_argument_type operator()(const typename operation::seconed_argument_type&  x)const
	{
		return op(x,value);
	}

	//bind1st_test<less<int>>(less<int>(),12)(15)
};

template<class operation ,class T>
inline bind1st_test<operation> bind1st_test_function(const operation& op, const T& x)
{
	typedef typename operation::first_argument_type arg1_type;
	return bind1st_test<operation>(op, arg1_type(x));
	//bind1st_test_function(less<int>(), 12)(15)
};

template<class Preticate>
class neta_test
{
protected:
	Preticate pre;
	typedef typename Preticate::result_argument_type   result_type_1;
	// typename Preticate::first_argument_type value;
public:
	neta_test(const Preticate&x) 
		:pre(x){}
	result_type_1 operator()(const typename Preticate::first_argument_type& y)
	{ return !pre(y); }
	//neta_test<bind1st_test<less<int>>(bind1st_test(less<int>,12))(15)
	/*
	
	 neta_test<bind1st_test<less_test<int>>>
		(bind1st_test<less_test<int>>(less_test<int>(), 12))
	*/
};

template<class Preticate>
inline neta_test<Preticate> not1_test_function(const Preticate& pre)
{
	// const typename Preticate::result_argument_type 
	typedef typename Preticate::first_argument_type  arg_type;
	return neta_test<Preticate>(pre);
	//����һ������
	//ͨ��ģ�庯��ʡȥ��ģ��
	//neta_test(bind1st(less<int>,12)(15)

	/*
	not1_test_function(bind1st_test_function(less_test<int>(), 12))
	
	*/
}

//��Ӻ����Ȼ�Ƿº���


#endif // !FUNCTOR_ADAPTERS
