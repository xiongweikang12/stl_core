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
	//�䱾����������rb_tree,���� key��valueһͬ�������ظ���
	//����ͨ���������޸� (����Ϊconst)
public:
	typedef typename rb_tree::const_rbiterator iterator;
	
};







#endif // !Set_test
