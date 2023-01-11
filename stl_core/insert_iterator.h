#ifndef INSERT_ITERATOR
#define INSERT_ITERATOR
// #include<iterator>
#include<vector>
using namespace std;

template <class input_iterator,class output_interator>
output_interator copy_test(input_iterator first, input_iterator last, output_interator result)
{
	while (first != last)
	{
		*result = *first;
		++first;
		++result;
	}
	return result;
};

//拷贝函数，拷贝first~last范围的内容到result

template<class Containter_test>
class insert_iterator_test
{
protected:
	Containter_test* containter;
	typename Containter_test::iterator iter;
public:
	typedef output_iterator_tag category;
	typedef void value_type;
	typedef void pointer;
	typedef void reference;
	// typedef size_t  size_type;
	typedef void difference_type;
	// typedef category_1  category;

	insert_iterator_test(Containter_test& x,typename Containter_test::iterator y)
		:containter(&(x)),iter(y){}

	
	insert_iterator_test<Containter_test>& operator=(const typename Containter::value_type value)
	{
		//value -> *first output_iterator的value_type;
		iter = containter->insert(iter, value);
		++iter;
		return *this;
		//insert_iterator_test<Containter_test>
	}

};


template<class Containter_test,class itertor_test>
inline insert_iterator_test<Containter_test> inserter_test(Containter_test& x, itertor_test i)
{
	typedef typename Container_test::category iter;
	return insert_iterator_test<Containter_test>(x, iter(i));
	//转换为与容器同种类型的迭代器
}

/*
list<int> foo,bar;
list<int>::iterator it=foo.begin()
advance(it,3)
copy(bar.begin(),bar.end(),inserter_test(foo,it));
*/


#endif // !INSERT_ITERATOR

