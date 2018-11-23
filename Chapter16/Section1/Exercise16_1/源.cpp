#include<iostream>
#include<string>

using namespace std;

template <typename T>
int compare(const T& lhs, const T& rhs)
{
	if (lhs < rhs)
	{
		return -1;
	}
	if (lhs < rhs)
	{
		return 1;
	}
	return 0;
}


int main()
{
	int a = 1, b = 2;
	cout << "a < b:" << ((compare(a, b) == -1) ? "F" : "T") << endl;

	string c("abc"), d("ab");
	cout << "c < d:" << ((compare(c, d) == -1) ? "F" : "T") << endl;

	system("pause");
	return 0;
}