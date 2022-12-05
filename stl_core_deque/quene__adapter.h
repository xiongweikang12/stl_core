
#ifndef __quene__
#define __quene__
#include "_deque__.h"

template <class T, size_t Buffsize, class TT = deque_1<T, Buffsize>>
class quene_1
{

public:
	typedef TT::value_type value_type;
	typedef TT::size_type size_type;
	typedef TT::reference reference;
	typedef TT::pointer  pointer;
	typedef TT::difference_type difference_type;

protected:
	TT c;
	//��Ϊ�ײ�����ʹ�ã�Ĭ�� deque 
	// stack<int,8,list<int>> ��ʱlist<int> ��Ϊ��ײ�������
	//������������
	//�������ڵײ������Ļ�����ʹ���亯��������Լ��Ĺ���;
	//�������Ϊ����ģʽ
	//ͬʱ����û�е�������

public:
	void push(const value_type& x)//���
	{
		c.push_back(x);
	}

	void pop()//����
	{
		c.pop_back();
	}

};
#endif