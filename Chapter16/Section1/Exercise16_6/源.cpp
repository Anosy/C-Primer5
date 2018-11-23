#include<iostream>
#include<string>
using namespace std;

template <typename T, unsigned N>
const T * my_begin(const T (&arr)[N])
{
	return &arr[0];
}

template <typename T, unsigned N>
const T * my_end(const T(&arr)[N])
{
	return &arr[N];
}

int main()
{
	int arr[] = { 1, 2, 3, 2, 1 };
	for (auto b = my_begin(arr); b != my_end(arr); ++b)
	{
		cout << *b << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
