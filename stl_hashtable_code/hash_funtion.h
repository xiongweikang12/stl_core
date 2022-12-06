#ifndef Hash_funciotn
#define Hash_function

#include "hashfunction_speacial_base.h"
//���ڲ�ͬ�Ĵ������͵�hash������Ӧ��
//������ȡ������%bucket.size())
//Ҳ��ģ��ķ��������ػ�

//����
template<class Key> struct hash{};

template<>
struct hash<char>
{
	size_t operator()(char x)const { return x; }

};

template<>
struct hash<short>
{
	size_t operator()(short x)const { return x; }

};


template<>
struct hash<unsigned short>
{
	size_t operator()(unsigned short x)const
	{
		return x;
	}

};

template<>
struct hash<int>
{
	size_t operator()(int x)const { return x; }
};

template<>
struct hash<unsigned int>
{
	size_t operator()(unsigned int x)const { return x; }
};

template<>
struct hash<long>
{
	size_t operator()(long x)const { return x; }

};

template<>
struct hash<unsigned long>
{
	size_t operator()(unsigned long x)const { return x; }

};


//����char pointer���ػ�
template<>
struct hash<char*>
{
	size_t operator()(const char* s)const 
	{ return __stl_hash_string(s); }

};

template<>
struct hash<const char*>
{
	size_t operator()(const char* s)const
	{
		return __stl_hash_string(s);
	}

};












#endif // !Hash_funciotn
