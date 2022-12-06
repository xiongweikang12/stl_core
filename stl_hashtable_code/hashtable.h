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
	typedef hashfuntion hasher; //��ʾһ��Ѱַ�º���
	// typedef Extrackey get_key;
	typedef Equalkey key_equal;
	typedef size_t size_type;

private:
	hasher hash;
	//hashfunction �º���class �Ķ���
	key_equal equals;
	Extrackey get_key;
	typedef __Hash_node<Value> node;
	std::vector<node* ,Alloc> buckets;
	size_type num_elemments;

	size_type bucket_num_key(const key_type& key, size_t n)
	{
		return hash(key) % n;
	}
	//����key

	size_type bucket_num(const value_type& obj, size_t n)
	{
		return bucket_num_key(get_key(obj),n)
	}
	//����key get_key(obj) ��ʾkey�ı�ʾ��ʽ
	//��ĳ����ʽ

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
	//����ͷ��������(Ѱַ���)

	//һЩhashtable�еĺ���
	hash_iterator  find(const key_type& key)
	{
		size_type n = bucket_num_key(key);
		//n ��ʾ��ϣӳ��λ��
		//....
		hash_iterator a;
		return a;
		
	}

	//��find,count��iterator�ж�++,--�Ĳ��������ö���Ҫ
	//�õ�ӳ����Ϊ��Ľ��;
	
	



};





#endif // !HASHTABLE
