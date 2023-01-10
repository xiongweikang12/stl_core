#ifndef REVERSE_ITERATOR
#define REVERSE_ITERATOR
#include "trais_iterator.h"

template<typename iterator>
class reverse_iterator
{
protected:

	iterator current;

public:
	//声明迭代器类型
	//声明迭代器所指的值类型
	//定义 self reverse_iterator<iterator>
	//...
	typedef typename traist_iterator<iterator>::value_type value_type;
	typedef  typename traist_iterator<iterator>::pointer  pointer;
	typedef  typename traist_iterator<iterator>::reference  reference;
	typedef  typename traist_iterator<iterator>::size_type  size_type;
	typedef  typename traist_iterator<iterator>::difference_type  difference_type;
	typedef  typename traist_iterator<iterator>::category  category;

	typedef iterator iterator_type;
	typedef reverse_iterator<iterator> self;

public:
	//添加原生构造函数，和拷贝构造函数
	explicit reverse_iterator(iterator_type& x) :current(x) {};
	reverse_iterator(self& x) :current(x.current) {};

	
	//添加相关的运算符重构
	iterator_type base()const { return current; }
	//对迭代器的正向返回
	reference operator*()const { iterator temp = current; return *(--temp); };
	//对迭代器内容的逆向返回

	pointer operator->()const{return &(operator*()) } 
	//返回指针

	self& operator++() { --current; return *this }
	self& operator--() { ++current; return *this }
	self operator+(difference_type n) { 
		return self(current - n);
		//调用构造函数
		//返回新对象
	}

	self operator-(difference_type n){
		return self.(current + n);
	}

	// rbegin_tset(){return reverse_iterator(end()) }

};






#endif // !REVERAE_ITERATOR