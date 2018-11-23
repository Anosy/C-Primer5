#include<iostream>
#include<string>

using namespace std;

template <typename T, unsigned N>
void print(const T(&arr)[N])
{
	for (auto c : arr)
	{
		cout << c << " ";
	}
	cout << endl;
}

int main()
{
	int a[] = { 1, 2, 3, 4 , 5, 4, 3, 2, 1 };
	print(a);

	string b[] = { "a", "b", "c" };
	print(b);

	system("pause");
	return 0;
}