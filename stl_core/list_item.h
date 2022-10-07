//TODO 定义一个链表结点 list_ietm
#ifndef _List_item_
#define _List_item_

//链表结点有两个成员
//一个value
//一个List_item的指针

template <typename T>
class List_item
{
public:
	T value_;
	List_item* _next;
	List_item* _prev;
	T value()const { return value_; }
	List_item* next()const { return this->_next; }
	List_item* prev()const { return this->_prev; }
};

#endif // !_List_item_
