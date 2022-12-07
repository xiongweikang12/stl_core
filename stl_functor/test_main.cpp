#include "functor.h"
#include "functor_adapters.h"
#include <iostream>
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
	cout << less<int>()(a, b) << endl;
	cout << greater_equal_test<int>()(a, b) << endl;
	cout << less_equal_test<int>()(a, b) << endl;
	cout << "\n";
	cout << logical_and_test<int>()(true, false) << endl;
	cout << logical_or_test<int>()(true, false) << endl;
	cout << logical_not_test<int>()(true) << endl;
	cout << "\n";
	cout << bind1st_test<less_test<int>>(less_test<int>(),12)(15) << endl;
	cout << bind1st_test_function(less_test<int>(), 12)(15) << endl;

	return 0;
}