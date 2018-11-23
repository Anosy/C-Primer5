#include<iostream>
#include<utility>
#include<type_traits>

using namespace std;

template <typename F, typename T1, typename T2>
void filp(F f, T1 &&t1, T2 &&t2)
{
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void func1(int v1, int v2)
{
	cout << v1 << " " << v2 << endl;
}

void func2(int &v1, int v2)
{
	cout << v1 << " " << v2 << endl;
}

void func3(int &&v1, int &v2)
{
	cout << v1 << " " << v2 << endl;
}


int main()
{
	int a = 0;
	int b = 1;
	filp(func1, a, b);
	filp(func2, a, b);
	filp(func3, a, 42);

	system("pause");
	return 0;
}