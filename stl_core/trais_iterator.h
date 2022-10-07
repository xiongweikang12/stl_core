#ifndef Traist_iterator
#define Traist_iterator
#include "list_iterator.h"
#include<cstddef>
#include <iterator>
template <typename input_iterator>
struct traist_iterator //泛化类型
{
	typedef typename input_iterator::value_type  value_type;
	typedef typename input_iterator::pointer pointer;
	typedef typename input_iterator::reference reference;
	typedef typename input_iterator::size_type size_type;
	typedef typename input_iterator::difference_type difference_type;
	typedef typename input_iterator::category category;
};

//关于native_pointer的特化版本
template <typename T>
struct traist_iterator<T*>
{
	typedef T value_type;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef T* pointer;
	typedef T& reference;
	typedef random_access_iterator_tag  category;
};


template <typename T>
struct traist_iterator<const T*>
{
	typedef T value_type;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef T* pointer;
	typedef T& reference;
	typedef random_access_iterator_tag  category;
};


#endif // !Traist_iterator
