#include <iostream>
using namespace std;
#include "List_.h"
#include "trais_iterator.h"
#include "true_tratis.h"
#include "trais_1_function.h"



int main()
{
	List_item<int>* node = (List_item<int>*)
		malloc(sizeof(List_item<int>));
	List<int> mylist(node);
	List<int>::iterator it;
	// mylist.begin();
	typedef List<int>::iterator it1;
	// traist_iterator<it1>::value_type;
	is_void_1<List<int>> a;
	display_traist(it);
	display_traist(mylist.begin());
	cout << a.value; //valueÎªÒ»¸öint
	
}
