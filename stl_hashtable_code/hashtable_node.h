#ifndef Hash_Node
#define Hash_Node

template<typename value>
struct __Hash_node
{
	value val;
	__Hash_node<value>* next;
	//表示为一个链表结点结构
};


#endif // !Hash_Node
