#ifndef RB_TREE_ITERATOR
#define RB_TREE_ITERATOR
#include "rb_node.h"

template<typename item>
class rb_Tree_iterator
{	
	typedef const item it_const;
	typedef __rb_node<item>* iterator;
	typedef __rb_node<it_const>* const_iterator;
	//以指针为迭代器
	//重载操作符...
};





#endif // !RB_TREE_ITERATOR
