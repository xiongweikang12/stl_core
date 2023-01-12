#ifndef  TUPLE_TEST
#define TUPLE_TEST

/*

template<typename...Values>class tuple_test;
template<>
class tuple_test<> {};

//关于递归结束的最终结局，


*/


template<typename Head,typename...Tail>
class tuple_test:private tuple_test<Tail ...>
{
	//每一个tuple_test都必须有一个head protected m_head，和一个继承tuple_test<Tail ...>
	//将tuple_test<Tail ...>声明为 inherited;
	//声明两个构造函数
	//声明两个函数head，tail
	//通过的是继承关系和定head的构造函数形成的递归构造，直到没有head（写一个模板特化）

protected:
	Head m_head;
public:
	typedef tuple_test<Tail ...> inherited;
	tuple_test(){}
	tuple_test(Head head, Tail... vtail) :m_head(head), inherited(vtail){}
	//inherited会发生递归，调用构造函数
	// 继承引发的构造。
	//tuple_test<Tail ...> ->tuple_test<Head,Tail...> ,占用一个不定参数作为Head
	//1.inherited是不属于其成员变量,其出现在构造函数的初始化列表中是因为父类的原由
	//inherited(vtail)-> tuple_test<Tail ...> ->tuple_test<Head,Tail...> 
	//其中Head为Tail中提取出的 
	//然后新的类对象，新的构造 tuple_test<Head,Tail...>(vtail)->tuple_test<Head,Tail...>(head,vtail)
	

	typename Head::type head() { return m_head; }
	inherited& tail() { return *this; }
};






#endif // !1
