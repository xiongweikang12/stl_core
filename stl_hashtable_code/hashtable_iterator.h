#ifndef Hash_iterator
#define Hash_iterator
#include "hashtable_node.h"
#include<vector>
#include "hashtable.h"

template <typename Value,
	typename Key,
	typename hashfuntion,
	typename Extrackey,
	typename EqualKey,
	class Alloc=int>
struct hash_iterator {
	
	typedef __Hash_node<Value> node;
	typedef hashtable<Value, Key, hashfuntion, Extrackey, EqualKey, Alloc> hashtable_;

	node* cur;
	hashtable_* ht;

	//对其有关运算符的重载



};







#endif // !Hash_iterator
