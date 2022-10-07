#ifndef  __List_iterator
#define __List_iterator
#include <cstddef>
#include <iostream>
using namespace std;
template <typename item ,typename category_1 >
struct List_iterator
{
	//定义类型
	typedef item  value_type;
	typedef item* pointer;
	typedef item& reference;
	typedef size_t  size_type;
	typedef ptrdiff_t difference_type;
	typedef category_1  category;

	

	item* ptr; //使用一个指针作为成员变量
	List_iterator(item* p=0) :ptr(p) {};

	//各种重载
	item& operator*()const { return *ptr; }
	item* operator->()const { return ptr; }

	List_iterator& operator++() {
		ptr = ptr->next();
		return *this;
	}//对于迭代器来说是控制指针运动的其本身是没有什么变化的
	
	List_iterator operator++(int dummy)
	{
		List_iterator temp = *this;
		++(*this);
		return temp;

	}
	List_iterator operator--()
	{
		ptr = ptr->prev();
		return *this;
	}
	

};

#endif // ! __List_iterator

