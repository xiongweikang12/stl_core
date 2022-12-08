#ifndef FUNCTOR_ADAPTERS
#define	FUNCTOR_ADAPTERS

#include "functor.h"

//������ӵĶ�Ԫ����ת����һԪ����


template<class operation>
class bind1st_test:public unary_funtion_test<typename operation::first_argument_type,
	typename operation::result_argument_type>
{
protected:
	operation op;
	typename operation::first_argument_type value;
public:
	bind1st_test(const operation& x, const typename operation::first_argument_type& y)
		:op(x), value(y)
	{

	}//���캯��

	const typename operation::result_argument_type 
		operator()(const typename operation::seconed_argument_type&  x)const
	{
		return op(value,x);
	}

	//bind1st_test<less<int>>(less<int>(),12)(15)
};

template<class operation ,class T>
inline bind1st_test<operation> bind1st_test_function(const operation& op, const T& x)
{
	typedef typename operation::first_argument_type arg1_type;
	return bind1st_test<operation>(op, arg1_type(x));
	//bind1st_test_function(less<int>(), 12)(15)
}


//��Ӻ����Ȼ�Ƿº���





#endif // !FUNCTOR_ADAPTERS
