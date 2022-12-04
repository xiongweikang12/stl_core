#ifndef MAP_TEST
#define MAP_TEST
#include "class_function.h"
#include "rb_tree_base.h"

template <typename key,typename value>
class map_test
{
public:
	typedef key key_value;
	typedef value date_value;
	typedef pair<const key, value> value_type;
	//��ʾkeyΪconst�������޸�
	typedef less<key> key_compare;
private:
	typedef rb_tree_base<key, value, select1st<value_type>, key_compare>
		rb_tree;
	rb_tree t;
public:
	typedef typename rb_tree::iterator iterator;

	//key of value ��ȡ��pair.first ��Ϊkey��
};

#endif // !MAP_TEST
