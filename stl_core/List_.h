#ifndef List__
#define List__
#include<cstdlib>
#include "list_item.h"
#include"list_iterator.h"
#include <iterator>
#include <malloc.h>


template <typename T >
class  List
{
public:
	typedef List_item<T> item;
	typedef List_iterator<item,input_iterator_tag>  iterator;
	
private:
	long _size;
	List_item<T>* _end;
	List_item<T>* _front;

public:
	typedef item* link_type;
	link_type node; //头指针用于表示整个数据结构
	List(link_type node1):node(node1) {
		node->_next = node;
		node->_prev = node;
		node->value_ = 0;
		_end = node;
		_front = node;
		_size = 0;

		
	}
	iterator begin() { return node->_next; }
	iterator end() { return node; }



};
#endif // !List__
