#ifndef  __Stack__
#define __Stack__
#include "_deque__.h"

template <class T,size_t Buffsize ,class TT=deque_1<T,Buffsize>>
class stack_1
{

public:
	typedef TT::value_type value_type;
	typedef TT::size_type size_type;
	typedef TT::reference reference;
	typedef TT::pointer  pointer;
	typedef TT::difference_type difference_type;

protected:
	TT c;
	//作为底层容器使用，默认 deque 
	// stack<int,8,list<int>> 这时list<int> 成为其底层容器，
	//这样适配起来
	//对于其在底层容器的基础上使用其函数，完成自己的功能;
	//因此设置为保护模式
	//同时其是没有迭代器的

public:
	void push(const value_type& x)//入栈
	{
		c.push_back(x);
	}

	void pop()//出栈
	{
		c.pop_front();
	}






};






#endif // ! Stack
