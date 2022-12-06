#ifndef HASHTABLE
#define HASHTABLE
#include "hashtable_node.h"
#include<vector>

template <typename value_type,
	typename key_type,
	typename hashfuntion,
	typename Extrackey,
	typename Equalkey,
	class Alloc = int>
class hashtable
{
public:
	typedef hashfuntion hasher; //表示一个寻址仿函数
	// typedef Extrackey get_key;
	typedef Equalkey key_equal;
	typedef size_t size_type;

private:
	hasher hash;
	//hashfunction 仿函数class 的对象
	key_equal equals;
	Extrackey get_key;
	typedef __Hash_node<Value> node;
	std::vector<node* ,Alloc> buckets;
	size_type num_elemments;

	size_type bucket_num_key(const key_type& key, size_t n)
	{
		return hash(key) % n;
	}
	//基于key

	size_type bucket_num(const value_type& obj, size_t n)
	{
		return bucket_num_key(get_key(obj),n)
	}
	//基于key get_key(obj) 表示key的表示方式
	//以某种形式

	size_type bucket_num_key(const key_type& key) const
	{
		return bucket_num_key(key, buckets.size());
	}

	size_type bucket_num(const value_type& obj)const
	{
		return bucket_num_key(get_key(obj));
	}

public:
	size_type buckets_count() const{ return buckets.size(); }
	//链表头结点的数量(寻址入口)

	//一些hashtable中的函数
	hash_iterator  find(const key_type& key)
	{
		size_type n = bucket_num_key(key);
		//n 表示哈希映射位置
		//....
		hash_iterator a;
		return a;
		
	}

	//像find,count，iterator中对++,--的操作符重置都需要
	//用到映射行为后的结果;
	
	



};





#endif // !HASHTABLE
