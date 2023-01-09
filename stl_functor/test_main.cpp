#include "functor.h"
#include "functor_adapters.h"
#include <iostream>
#include "function_functor.h"
#include <vector>

using namespace std;

int main()
{
	int a = 4;
	int b = 2;
	cout << plus_test<int>()(a, b) << endl;
	cout << minus_test<int>()(a, b) << endl;
	cout << multiplies_test<int>()(a, b) << endl;
	cout << divides_test<int>()(a, b) << endl;
	cout << modules_test<int>()(a, b) << endl;
	cout << negate_test<int>()(a) << endl;
	cout << "\n";
	cout << equal_to_test<int>()(a, b) << endl;
	cout << no_equal_to_test<int>()(a, b) << endl;
	cout << greater<int>()(a, b) << endl;
	cout << "4<2=\t"<<less<int>()(a, b) << endl;
	cout << greater_equal_test<int>()(a, b) << endl;
	cout << less_equal_test<int>()(a, b) << endl;
	cout << "\n";
	cout << logical_and_test<int>()(true, false) << endl;
	cout << logical_or_test<int>()(true, false) << endl;
	cout << logical_not_test<int>()(true) << endl;
	cout << "\n";
	cout << bind1st_test<less_test<int>>(less_test<int>(),12)(15) << endl;
	
	cout << bind1st_test_function(less_test<int>(), 12)(15) << endl;


	cout<<"new:" << compose_test_function(bind1st_test_function(multiplies_test<int>(), 3),
		bind1st_test_function(plus_test<int>(), 2))(3);




	vector<int> test = { 10,13,16,17,18,1,14 };
	auto temp_vector1=search_test(test.begin(), test.end(),
		bind1st_test_function(less_test<int>(), 15),10);

	auto temp_vector2=search_test(test.begin(), test.end(), 13);
	cout << "search_size :" << temp_vector1.size() << endl;
	cout <<"search_size :" << temp_vector2.size() << endl;

	//对于vector的输出没有 cout<< 
	/*
	1.写一个对于vector的<<符号重载 ，但不能是泛化
	2.在外部遍历 temp_vector1.begin()  for (...
	*/

	vector<int> test1 = { 2,4,6,8 };
	auto res = accumlate_test(test1.begin(), test1.end(), plus_test<int>(),0);
	auto res_1= accumlate_test(test1.begin(), test1.end(), multiplies_test<int>(),1);
	
	cout << res << endl;
	cout << res_1 << endl;

	
	cout << "\n";
	cout<< neta_test<bind1st_test<less_test<int>>>
		(bind1st_test<less_test<int>>(less_test<int>(), 12))(15)<<endl;
	//传入一个对象
	cout << not1_test_function(bind1st_test_function(less_test<int>(), 12))(15) << endl;
	//模板函数自动识别类型 
	
	auto ii = less_test<int>();
	auto res_2=accumlate_test(test1.begin(),test1.end(),multiplies_test<int>(),1,
		bind1st_test_function(ii, 5));
	cout << res_2 << endl;
	
	//当

	return 0;
}