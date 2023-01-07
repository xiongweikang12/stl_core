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
	//对象构造函数,拷贝构造。


	const typename operation::result_argument_type operator()(const typename operation::seconed_argument_type&  x)const
	{
		return op(x,value);
	}

	//通过将另一个仿函数作为其类成员，同时指定仿函数的frist_argument_type （）重构时传入自身的secoond_argument_type 调用之前的仿函数（二元） 
	// return op(x,value); value为绑定值
	//bind1st_test<less<int>>(less<int>(),12)(15)
};

template<class operation ,class T>
inline bind1st_test<operation> bind1st_test_function(const operation& op, const T& x)
{
	typedef typename operation::first_argument_type arg1_type;
	return bind1st_test<operation>(op, arg1_type(x));
	//bind1st_test_function(less<int>(), 12)(15)
	//bind1st_test_function(less<int>(),12) 是利用了模板函数自动识别的特性从而return 一个绑定对象类的对象，
	//（）利用重构传入secoond_argument_type；
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
	//意义为15>12的否定  bind1st_test(less<int>(),12) 为对象(15)
	/*
	
	 neta_test<bind1st_test<less_test<int>>>
		(bind1st_test<less_test<int>>(less_test<int>(), 12))
	*/
	//表示一元的否定
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
	//以上为返回对象，然后通过调用重构() ！pre(y) -> !bind1st_test_function(less_test<int>(),12))(15) -> op(x,value) ->!less_test<int>(15,12)
	*/
}

//配接后的依然是仿函数


#endif // !FUNCTOR_ADAPTERS
