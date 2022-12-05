#ifndef  Hash_key
#define Hash_key
#include <string.h>



template <typename T>
struct identity
{
	typedef T key_type;
	key_type operator()(const key_type& x)
	{
		return x;
	}

};
//泛化

//特化
template <>
struct identity<char*>
{
	typedef char* pointer_type;
	char operator()(const pointer_type x)
	{
		return *x;
	}
};

///

//比较大小
template<typename T>
struct eqstr
{
	bool operator()(const T& x1, const T& x2)
	{
		return x1 < x2;
	}

};

template<>
struct eqstr<const char*>
{
	bool operator()(const char* x1, const char* x2)
	{
		//对于比较指针所指向内容的大小
		//一般使用专用自定函数
		return strcmp(x1, x2) == 0;
	}
};

///













#endif // ! Hash_key
