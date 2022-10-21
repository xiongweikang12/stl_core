#ifndef __deque__iterator
#define __deque__iterator
template <class T,class ptr ,class refer,size_t Buffsize,typename category>
struct __deque__iterator_1
{
	typedef __deque__iterator_1<T, T&, T*, Buffsize, category> 
		iterator;
	typedef __deque__iterator_1<T, const T&, const T* Buffsize, category> 
		const_iterator;

	static size_t Buffer_size()
	{
		return __deque_buf_size(Buffsize,sizeof(T))
	}

	typedef category iterator_category
	typedef T value_type;
	typedef ptr pointer;
	typedef refer reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef T** map_pointer;
	typedef iterator self;


	pointer cur;
	pointer first;
	pointer last;
	map_pointer node;

	//operator overloading

	void set_node(map_pointer new_node)
	{
		node = new_node;
		first = *new_node;
		last = first + difference_type(Buffer_size());
	}

	reference operator*(){return *cur;} //返回cur指向的内容
	pointer operator->() { return &(operator*()); }

	difference_type operator-(const self& x)
	{
		return difference_type(Buffer_size() * (node - x.node - 1)
			+ (cur - first) + (x.last - x.cur));
	}

	self& operator++()
	{
		++cur;
		if (cur == last)
		{
			set_node(node + 1);
		}
		cur = first;
		return *this;
	}

	self operator++(int dummy)
	{
		self temp = *this;
		++(*this);
		return temp;
	}

	self& operator--()
	{
		--cur;
		if (cur = first)
		{
			set_node(node - 1);
			cur = last;
		}
		return *this
	}

	self operator--(int dummy)
	{
		self temp = *this;
		--(*this);
		return temp;
	}

	self& operator+= (difference_type n)
	{
		difference_type offset = n + (cur - first);
		if (offset >= 0 && offset < difference_type(Buffer_size()))
		{
			cur += n;
			//同一个缓存区
		}
		else
		{
			difference_type node_set = offset > 0 ?
				offset / difference_type(Buffer_size())
				: -difference_type((-offset - 1) / Buffer_size()) - 1;

			set_node(node + node_set);
			cur = first + (offset - node_set * difference_type(Buffer_size()));
		}
		return *this;
	}

	self operator+(difference_type n)
	{	
		self temp = *this;
		return temp += n;
		//相当于创建了一个新对象
	}

	self& operator-=(difference_type n)
	{
		return *this += -n;
		//单目运算符自身发生改变，返回引用
	}

	self operator-(difference_type n)
	{
		self temp = *this;
		return temp -= n;
	}

	reference operator[](difference_type n)
	{
		return *((*this) + n);  //* return *cur,返回iterator的cur内容
	}

	



};

inline size_t __deque_buf_size(size_t n, size_t sz)
{
	return n != 0 ? n 
		: (sz < 512 ? size_t(512 / sz) : size_t(1));
}






#endif // !__deque__iterator
