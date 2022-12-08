#ifndef FUNCTION_FUNCTOR
#define	FUNCTION_FUNCTOR
#include "functor_adapters.h"
#include <iostream>
using namespace std;

template<typename iterator_test ,typename functor_test>
void search_test(iterator_test begin, iterator_test end, functor_test test)
{
	for (auto i = begin; i != end; i++)
	{
		if (test(*i))
		{
			cout<<"search_alright" << *i<<endl;
		}
	}
}

//��ģ�庯���ĵķ�ʽ,���벻ͬ�ķº��������Ǻ���ָ�����ʽ��,
//����Ҳ������ģ������֮�¸����㣬��չ�Ը�ǿ
//����Ƿº�������㷨ʵ�ֶ��ֲ���




template<typename iterator_test ,typename functor_test,typename T>
typename functor_test::result_argument_type accumlate_test
(iterator_test begin, iterator_test end, functor_test test,const T& init)
{
	bool flag = true;
	typename functor_test::result_argument_type  sum = 0;
	auto sum_c = sum;
	for (auto i = begin; i != end; i++)
	{
		if (flag)
		{
			sum = test(init, (*i));
			//��Ҫ�ڷº����ڶ���������������ֲ�ͬ�ķº���Ӧ��ͬһ���㷨
			//��accumlate_test �㷨 �ڴ���ʱ�º����ĳ�ֵ��ͬ������ mult_test ��ֵ
			//test(1,(*i));, plus_testʱ���ֵΪ test(0,(*i))
			//��һ���������:�������������ͨ������������һ�������� 1��0��Ӧ��Ӧ�ķº�����ʼֵ

			flag = false;
		}
		else
		{
			sum = test(sum, (*i));
		}

	}
	return sum;
};







#endif // !FUNCTION_FUNCTOR
