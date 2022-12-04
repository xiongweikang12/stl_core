#ifndef Set_test
#define Set_test
#include "rb_tree_base.h"

template<typename T,typename compara=less_test<T> >
class set_test
{
public:
	typedef T key;
	typedef T value;
	typedef compara key_Compare;
	typedef compara value_Compare;

private:
	typedef rb_tree_base<T, T, idenitiy<T>, compara> rb_tree;

	rb_tree t;
	//其本质上是依赖rb_tree,而且 key与value一同，不可重复，
	//不能通过迭代器修改 (内容为const)
public:
	typedef typename rb_tree::const_rbiterator iterator;
	
};







#endif // !Set_test
