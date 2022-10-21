#ifndef  __deque__
#define __deque__
#include "_deque__iterator.h"
#include <iterator>
#include <iostream>
using namespace std;

template <class T,size_t Buffsize>
class deque_1
{
public:
	typedef T value_type;
	typedef T* reference;
	typedef value_type* pointer;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef __deque__iterator_1<T, T&, T*, Buffsize, random_access_iterator_tag>
		iterator_deque;


protected:
	typedef pointer* map_pointer;
	map_pointer map; //指向控制中心的指针
	size_type map_size;
	iterator_deque start;
	iterator_deque finish;

public:
	iterator_deque begin() { return start; }
	iterator_deque end() { return finish; }
	reference operator[](size_type n) 
	{ return start[difference_type(n)]; }

	void pop_back()
	{
		if (finish.cur != finish.first)
		{
			cout << *finish << "  尾部弹出" << endl;
			--finish;
			//destory(finish.cur)

		}
		else
		{
			pop_back_aux(); 
			//表示cur==frist ，需指向下一个缓冲区last
		}
	}
	void pop_front()
	{
		if (start.cur != start.last - 1)
		{
			//destory(start.cur);
			cout << *start << " 头部弹出" << endl;
			++start;
		}
		else
		{
			pop_front_aux();
		}
	}
	void push_back(const value_type& x)
	{
		//
	}
	//....
	void pop_back_aux();
	void pop_front_aux();

		 

};

template<class T,size_t Buffsize>
void deque_1<T, Buffsize>::pop_back_aux()
{
	free(finish.first);
	finish.set_node(finish.node - 1);
	//finish.last=*node+difference_type(buffsize())
	finish.cur = finish.last - 1; //指向尾部
	//destory(finish.cur)
}


template<class T, size_t Buffsize>
void deque_1<T, Buffsize>::pop_front_aux()
{
	free(start.first);
	start.set_node(start.node + 1); //start.first=*node
	start.cur = start.first;
}




#endif // ! __deque__
