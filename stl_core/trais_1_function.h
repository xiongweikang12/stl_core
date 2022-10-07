#include "trais_iterator.h"
#include "List_.h"
#include <iostream>
using namespace std;

template <typename T>
void display_traist(T iter)
{
	typedef typename traist_iterator<T>::value_type value_type_1;
	typedef typename traist_iterator<T>::category category_1;
	value_type_1 vt1;
	category_1 ca1;
	cout << typeid(vt1).name() << endl;
	cout << typeid(ca1).name() << endl;
}

//类模板的定义声明应当放入头文件中，不应该分开
