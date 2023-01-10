#ifndef REVERSE_ITERATOR
#define REVERSE_ITERATOR
#include "trais_iterator.h"

template<typename iterator>
class reverse_iterator
{
protected:

	iterator current;

public:
	//��������������
	//������������ָ��ֵ����
	//���� self reverse_iterator<iterator>
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
	//���ԭ�����캯�����Ϳ������캯��
	explicit reverse_iterator(iterator_type& x) :current(x) {};
	reverse_iterator(self& x) :current(x.current) {};

	
	//�����ص�������ع�
	iterator_type base()const { return current; }
	//�Ե����������򷵻�
	reference operator*()const { iterator temp = current; return *(--temp); };
	//�Ե��������ݵ����򷵻�

	pointer operator->()const{return &(operator*()) } 
	//����ָ��

	self& operator++() { --current; return *this }
	self& operator--() { ++current; return *this }
	self operator+(difference_type n) { 
		return self(current - n);
		//���ù��캯��
		//�����¶���
	}

	self operator-(difference_type n){
		return self.(current + n);
	}

	// rbegin_tset(){return reverse_iterator(end()) }

};






#endif // !REVERAE_ITERATOR