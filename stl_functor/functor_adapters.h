#ifndef FUNCTOR_ADAPTERS
#define	FUNCTOR_ADAPTERS

#include "functor.h"

//将可配接的二元函数转换成一元函数


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
		//表示捆绑了第一参数，第二参数指定;
	}//构造函数

	bind1st_test(const bind1st_test& test)
	{
		this->op = test.op;
		this->value = test.value;
	}
	//对象构造函数 


	const typename operation::result_argument_type operator()(const typename operation::seconed_argument_type& x)
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
	//返回一个对象
	//通过模板函数省去类模板
	//neta_test(bind1st(less<int>,12)(15)

	/*
	not1_test_function(bind1st_test_function(less_test<int>(), 12))
	
	*/
}

//配接后的依然是仿函数


//组合（嵌套)关系的仿函数配接多为两个
//(v+3)*5
template <class  functor_1,class functor_2>
class compose_test
{
protected:
	functor_1 functor_compose_1;
	functor_2 functor_compose_2;
	typedef typename functor_1::first_argument_type value_1;
	typedef typename  functor_1::first_argument_type value_2;
public:
	typedef typename functor_1::result_argument_type  result_argument_type1;
	typedef typename functor_2::result_argument_type  result_argument_type2;
	compose_test(const functor_1& functor1,const functor_2& functor2)
		:functor_compose_1(functor1),functor_compose_2(functor2)
	{}
	
	typename result_argument_type1 operator()(const typename functor_2::first_argument_type& v)
	{
		return functor_compose_1(functor_compose_2(v));
	}
};

template <class  functor_1, class functor_2>
inline  compose_test<functor_1, functor_2> compose_test_function
(const functor_1& functor1, const functor_2& functor2)

{
	return compose_test<functor_1, functor_2>(functor1, functor2);
}








#endif // !FUNCTOR_ADAPTERS
