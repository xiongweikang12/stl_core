#ifndef FUNCTION_FUNCTOR
#define	FUNCTION_FUNCTOR
#include "functor_adapters.h"
#include <iostream>
#include <vector>
using namespace std;

template<typename iterator_test ,typename functor_test,typename T>
vector<T> search_test(iterator_test begin, iterator_test end, functor_test test,T find_data)
{
	
	/*
	begin:iterator 
	end:iterator
	test:��طº���,ΪһԪ�º���
	find_data:Ѱ�ҵ���
	//�����������ݷº���Ѱ��
	
	*/
	int flag = 0;
	vector<T>  collation_contianer;
	cout << "collection_vector_containter:";

	for (auto i = begin; i != end; i++)
	{
		if (test(*i))
		{
			cout << (*i) << "->";
			collation_contianer.push_back(*i);
			flag++;
		}
	}
	if (flag == 0)
	{
		cout << "sorry don't search the data" << endl;
	}
	cout << ":search_alright" << endl;
	return collation_contianer;

	//find_test��ʾҪfind�Ķ�������
	//�º���ɸѡ���������û�����õ�
	//��Ҫ������base_function
	//�����������亯���������������κ�ֵ
}

//��ģ�庯���ĵķ�ʽ,���벻ͬ�ķº��������Ǻ���ָ�����ʽ��,
//����Ҳ������ģ������֮�¸����㣬��չ�Ը�ǿ
//����Ƿº�������㷨ʵ�ֶ��ֲ���

template<typename iterator_test ,typename T>
vector<T> search_test(iterator_test begin, iterator_test end, T find_data)
{

	/*
	begin:iterator
	end:iterator
	find_data:Ѱ�ҵ���
	//��������Ѱ�ҵ���Ѱ��

	*/
	int flag =0;
	vector<T>  collation_contianer;
	cout << "collection_vector_containter:";
	for (auto i = begin; i != end; i++)
	{
		if ((*i) == find_data)
		{
			cout <<(*i)<<"->";
			collation_contianer.push_back(*i);
			flag++;
		}
	}
	if (flag == 0)
	{
		cout << "sorry don't search the data" << endl;
	}
	cout << ":search_alright" << endl;
	return collation_contianer;
}
	 




template<typename iterator_test ,typename functor_test,typename T>
typename functor_test::result_argument_type accumlate_test
(iterator_test begin, iterator_test end, functor_test test,const T& init)
{	
	
	/*
	begin:iterator
	end:iterator
	test:��طº���,��Ԫ�º�����plus mult....
	init:��ʼֵ ����ӵĳ�ʼֵ����Ϊ0�����ǳ˷�����Ϊ0
	//��������Ϊ��begin��end������������*iterator����ʾ����ͬʱ��Ҳ���ع�
	//*iteratorҲ���Ա�ʾ������������Ҫ��test��Ӧ�ķ����ع�

	T operator()( const T& x1, const  T& x2 )
	{
		return x1 + x2; //��������+���ع�
	}

	*/

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



template<typename iterator_test, typename functor_test, typename T,typename Preticate>
typename functor_test::result_argument_type accumlate_test
(iterator_test begin, iterator_test end, functor_test test, const T& init,const Preticate& pre_object)
{

	/*
	begin:iterator
	end:iterator
	test:��طº���,��Ԫ�º�����plus mult....
	init:��ʼֵ ����ӵĳ�ʼֵ����Ϊ0�����ǳ˷�����Ϊ0
	pre_object :��طº�����һԪ�º��� ����ɸѡ
	//��������Ϊ��begin��end������������*iterator����ʾ����ͬʱ��Ҳ���ع�
	//*iteratorҲ���Ա�ʾ������������Ҫ��test��Ӧ�ķ����ع�

	T operator()( const T& x1, const  T& x2 )
	{
		return x1 + x2; //��������+���ع�
	}

	*/
	bool flag = true;
	typename functor_test::result_argument_type  sum = 0;
	auto sum_c = sum;
	// Preticate pre_boject; //�ж϶���
	for (auto i = begin; i != end; i++)
	{
		if (pre_object(*i)) //��ԭ����������һ���º���������ָ���ɸѡ
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
		else
		{
			continue;
		}
	}
	return sum;

	//����һ�㷨�����ؼ���һ���º����ж�ɸѡ;
};







#endif // !FUNCTION_FUNCTOR
