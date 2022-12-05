#ifndef HASHTABLE
#define HASHTABLE
#include "hashtable_node.h"
#include<vector>

template <typename Value,
	typename Key,
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
	key_equal equals;
	Extrackey get_key;
	typedef __Hash_node<Value> node;
	vector<node* Alloc> buckets;
	size_type num_elemments;
public:
	size_type buckets_count(){return  }
};





#endif // !HASHTABLE
