#ifndef RB_TREE_BASE
#define RB_TREE_BASE
#include "class_function.h"
#include "rb_node.h"
#include "rb_tree_iterator.h"

template <typename key,
	typename value,
	typename keyofvalue=idenitiy<key>,
	typename compare=less_test<key>,
	class Alloc=int>

class rb_tree_base
{
protected:
	typedef __rb_node<value> rb_node; 
	//结点
public:
	typedef rb_node* rb_node_link; 
	//结点指针
	typedef rb_Tree_iterator<key>::const_iterator const_rbiterator;
	typedef rb_Tree_iterator<key>::iterator rbiterator;
private:
	size_t node_size;
	rb_node_link header; //头指针
	compare key_compare;

};





#endif // !RB_TREE_BASE
