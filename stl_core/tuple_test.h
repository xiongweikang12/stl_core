#ifndef  TUPLE_TEST
#define TUPLE_TEST

/*

template<typename...Values>class tuple_test;
template<>
class tuple_test<> {};

//���ڵݹ���������ս�֣�


*/


template<typename Head,typename...Tail>
class tuple_test:private tuple_test<Tail ...>
{
	//ÿһ��tuple_test��������һ��head protected m_head����һ���̳�tuple_test<Tail ...>
	//��tuple_test<Tail ...>����Ϊ inherited;
	//�����������캯��
	//������������head��tail
	//ͨ�����Ǽ̳й�ϵ�Ͷ�head�Ĺ��캯���γɵĵݹ鹹�죬ֱ��û��head��дһ��ģ���ػ���

protected:
	Head m_head;
public:
	typedef tuple_test<Tail ...> inherited;
	tuple_test(){}
	tuple_test(Head head, Tail... vtail) :m_head(head), inherited(vtail){}
	//inherited�ᷢ���ݹ飬���ù��캯��
	// �̳������Ĺ��졣
	//tuple_test<Tail ...> ->tuple_test<Head,Tail...> ,ռ��һ������������ΪHead
	//1.inherited�ǲ��������Ա����,������ڹ��캯���ĳ�ʼ���б�������Ϊ�����ԭ��
	//inherited(vtail)-> tuple_test<Tail ...> ->tuple_test<Head,Tail...> 
	//����HeadΪTail����ȡ���� 
	//Ȼ���µ�������µĹ��� tuple_test<Head,Tail...>(vtail)->tuple_test<Head,Tail...>(head,vtail)
	

	typename Head::type head() { return m_head; }
	inherited& tail() { return *this; }
};






#endif // !1
