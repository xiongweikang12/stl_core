//TODO ����һ�������� list_ietm
#ifndef _List_item_
#define _List_item_

//��������������Ա
//һ��value
//һ��List_item��ָ��

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
