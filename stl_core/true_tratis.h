#ifndef __True_tratis
#define __True_tratis
#include<iostream>
#include<cstdlib>
using namespace std;
// 实现is_void()

//remove_cv const ,volatile
template <typename Tp>
struct remove_c1{ typedef Tp Tp;}; //特化版本

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
//泛化

template <>
struct is_void_help<void> :public true_type{};

template <typename Tp>
struct is_void_1:
	public is_void_help<typename remove_cv1<Tp>::Tp>{};


#endif // !__True_tratis

//不确定类型 命名空间内存在同名

//此方法作为新方法，是通过模板和重名对类型处理，
//然后通过模板泛化，特化（起到一个判断作用），
//和继承true_type 和继承 false_type

//传统上是在容器（类中）typedef 自己的true_trstis
/*
struct iterator_test
{
	typedef typename true_type is_void;
	.....
}
使用 iterator_test<type>::is_void; 这表示一个类型

然后通过true_trstis 萃取机进行返回泛化，特化
true_tratis<typename e>
{
	typedef e::is_void is_void ;
	....//泛化
	对于某些类型存在特化
}
使用 true_tratis<iterator_test>::is_void;
同样表示一个类型（ class ,struct)
如果填上（） 就是创建一个temp临时变量



*/