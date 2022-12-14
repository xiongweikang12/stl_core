#ifndef FUNCTION_FUNCTOR
#define	FUNCTION_FUNCTOR
#include "functor_adapters.h"
#include <iostream>
using namespace std;

template<typename iterator_test ,typename functor_test,typename T>
void search_test(iterator_test begin, iterator_test end, functor_test test,T find_data )
{
	for (auto i = begin; i != end; i++)
	{
		if (test(*i))
		{
			cout<<"search_alright" << *i<<endl;
		}
	}
}



template<typename iterator_test ,typename T>
void search_test(iterator_test begin, iterator_test end,T find_data )
{
	int flag=0;
	for (auto i = begin; i != end; i++)
	{
		if ((*i)=find_data)
		{
			cout<<"search_alright" << *i<<endl;
			break;
			
		}
	}
	if(flag==0)
	{
		cout<<"sorry don't search the data"<<endl;
	}
	
	
	//用模板函数的的方式,传入不同的仿函数（像是函数指针的形式
	//但其也是依赖模板的相比之下更方便，拓展性更强
	//其就是仿函数配合算法实现多种操作
}














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
			//需要在仿函数内定义相关名称来区分不同的仿函数应对同一个算法
			//如accumlate_test 算法 在处理时仿函数的初值不同，如像 mult_test 初值
			//test(1,(*i));, plus_test时候初值为 test(0,(*i))
			//另一个解决方法:这样的情况可以通过函数本身传入一个参数如 1，0对应相应的仿函数初始值

			flag = false;
		}
		else
		{
			sum = test(sum, (*i));
		}

	}
	return sum;
};



template<typename iterator_test, typename functor_test, typename T,typename Preticate>
typename functor_test::result_argument_type accumlate_test
(iterator_test begin, iterator_test end, functor_test test, const T& init,const Preticate& pre_object)
{
	bool flag = true;
	typename functor_test::result_argument_type  sum = 0;
	auto sum_c = sum;
	// Preticate pre_boject; //判断对象
	for (auto i = begin; i != end; i++)
	{
		if (pre_object(*i)) //在原基础上增加一个仿函数，函数指针的筛选
		{
			if (flag)
			{
				sum = test(init, (*i));
				//需要在仿函数内定义相关名称来区分不同的仿函数应对同一个算法
				//如accumlate_test 算法 在处理时仿函数的初值不同，如像 mult_test 初值
				//test(1,(*i));, plus_test时候初值为 test(0,(*i))
				//另一个解决方法:这样的情况可以通过函数本身传入一个参数如 1，0对应相应的仿函数初始值

				flag = false;
			}
			else
			{
				sum = test(sum, (*i));
			}

		}
		else
		{
			continue;
		}
	}
	return sum;

	//对于一算法的重载加上一个仿函数判断筛选;
};







#endif // !FUNCTION_FUNCTOR
