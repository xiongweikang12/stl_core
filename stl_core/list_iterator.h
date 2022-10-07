#ifndef  __List_iterator
#define __List_iterator
#include <cstddef>
#include <iostream>
using namespace std;
template <typename item ,typename category_1 >
struct List_iterator
{
	//��������
	typedef item  value_type;
	typedef item* pointer;
	typedef item& reference;
	typedef size_t  size_type;
	typedef ptrdiff_t difference_type;
	typedef category_1  category;

	

	item* ptr; //ʹ��һ��ָ����Ϊ��Ա����
	List_iterator(item* p=0) :ptr(p) {};

	//��������
	item& operator*()const { return *ptr; }
	item* operator->()const { return ptr; }

	List_iterator& operator++() {
		ptr = ptr->next();
		return *this;
	}//���ڵ�������˵�ǿ���ָ���˶����䱾����û��ʲô�仯��
	
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

