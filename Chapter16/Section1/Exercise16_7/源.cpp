#include<iostream>
#include<string>

using namespace std;

template <typename T, size_t N>
constexpr size_t arr_size(const T(&arr)[N])
{
	return N;
}


int main()
{
	int a[] = { 1, 2, 3, 4 , 5, 4, 3, 2, 1 };
	string b[] = { "a", "b", "c" };

	cout << arr_size(a) << endl;
	cout << arr_size(b) << endl;

	system("pause");
	return 0;
}