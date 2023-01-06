#ifndef FUNCTOR
#define FUNCTOR
#include "functor_base.h"

//各种仿函数的定义
//通过模板（继承基类（用于说明相关操作数，如一元操作数，二元操作数，结果的其类型））
//类中有类对象的（）重载，创建一个临时对象temp --》 plus_test<int>()
template <typename T>
struct  plus_test:public binary_funtion_test<T,T,T>
{
	T operator()( const T& x1, const  T& x2 )
	{
		return x1 + x2;
	}
};


template<typename T>
struct minus_test:public binary_funtion_test<T,T,T>
{
	T operator()(const T& x1, const T& x2)
	{
		return x1 - x2;
	}
};


template<typename T>
struct multiplies_test:public binary_funtion_test<T,T,T>
{
	T operator()(const T& x1, const T& x2)
	{
		return x1 * x2;
	}
};


template<typename T>
struct divides_test:public binary_funtion_test<T,T,T>
{
	T operator()(const T& x1, const T& x2)
	{
		return x1 / x2;
	 }
};

template<typename T>
struct modules_test:public binary_funtion_test<T,T,T>
{
	T operator()(const T& x1, const T& x2)
	{
		return x1 % x2;
	}
};

template<typename T>
struct negate_test:public unary_funtion_test<T,T>
{
	T operator()(const T& x1)
	{
		return -x1;
	}
};

template<typename T>
struct equal_to_test:public binary_funtion_test<T,T,bool>
{
	bool operator()(const T& x1, const T& x2)
	{
		return x1 == x2;
	}
};

template<typename T>
struct no_equal_to_test:public binary_funtion_test<T,T,bool> 
{
	bool operator()(const T& x1, const T& x2)
	{
		return x1 != x2;
	}
};

template<typename T>
struct greater_test :public binary_funtion_test<T, T, bool>
{
	bool operator()(const T& x1, const T& x2)
	{
		return x1>x2;
	}
};

template<typename T>
struct less_test :public binary_funtion_test<T, T, bool>
{
	bool operator()(const T& x1, const T& x2)const
	{
		return x1<x2;
	}
};

template<typename T>
struct greater_equal_test :public binary_funtion_test<T, T, bool>
{
	bool operator()(const T& x1, const T& x2)
	{
		return x1>=x2;
	}
};

template<typename T>
struct less_equal_test :public binary_funtion_test<T, T, bool>
{
	bool operator()(const T& x1, const T& x2)
	{
		return x1<=x2;
	}
};

template<typename T>
struct logical_and_test :public binary_funtion_test<T, T, bool>
{
	bool operator()(const T& x1, const T& x2)
	{
		return x1 && x2;
	}
};

template<typename T>
struct logical_or_test :public binary_funtion_test<T, T, bool>
{
	bool operator()(const T& x1, const T& x2)
	{
		return x1 or x2;
	}
};

template<typename T>
struct logical_not_test :public unary_funtion_test<T,bool>
{
	bool operator()(const T& x1)
	{
		return !x1;
	}
};



//functor_ad
template<typename Predicate>
struct unary_negate_test
{
public:
	bool operator()(typename Predicate::result_argument_type& x)const
	{
		//函数改变,改写...
		return true;
	}

};


#endif // !FUNCTOR
