#ifndef __True_tratis
#define __True_tratis
#include<iostream>
#include<cstdlib>
using namespace std;
// ʵ��is_void()

//remove_cv const ,volatile
template <typename Tp>
struct remove_c1{ typedef Tp Tp;}; //�ػ��汾

template <typename Tp>
struct remove_c1<Tp const> { typedef Tp Tp; };

template<typename Tp>
struct remove_v1 { typedef Tp Tp; };

template<typename Tp>
struct remove_v1<Tp volatile> { typedef Tp Tp; };

template <typename Tp>
struct remove_cv1 { 
	typedef typename 
		remove_c1<typename remove_v1<Tp>::Tp >::Tp Tp; };

template <typename Tp>
struct is_void_help :public false_type{};
//����

template <>
struct is_void_help<void> :public true_type{};

template <typename Tp>
struct is_void_1:
	public is_void_help<typename remove_cv1<Tp>::Tp>{};


#endif // !__True_tratis

//��ȷ������ �����ռ��ڴ���ͬ��

//�˷�����Ϊ�·�������ͨ��ģ������������ʹ���
//Ȼ��ͨ��ģ�巺�����ػ�����һ���ж����ã���
//�ͼ̳�true_type �ͼ̳� false_type

//��ͳ���������������У�typedef �Լ���true_trstis
/*
struct iterator_test
{
	typedef typename true_type is_void;
	.....
}
ʹ�� iterator_test<type>::is_void; ���ʾһ������

Ȼ��ͨ��true_trstis ��ȡ�����з��ط������ػ�
true_tratis<typename e>
{
	typedef e::is_void is_void ;
	....//����
	����ĳЩ���ʹ����ػ�
}
ʹ�� true_tratis<iterator_test>::is_void;
ͬ����ʾһ�����ͣ� class ,struct)
������ϣ��� ���Ǵ���һ��temp��ʱ����



*/