#include<type_traits>
#include<iostream>

using namespace std;

template <typename T1, typename T2>
auto mysum(T1 a, T2 b) -> decltype(a + b)
{
	return a + b;
}

int main()
{
	int a = 1; 
	double b = 2.2;
	auto sum = mysum(a, b);
	cout << sum << endl;

	system("pause");
	return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    