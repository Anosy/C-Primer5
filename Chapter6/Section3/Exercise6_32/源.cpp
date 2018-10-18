#include<iostream>
#include<string>

using namespace std;

int &get(int *arry, int index) { return arry[index]; } // 必须是引用类型的函数，否则返回的不是左值

int main()
{
	int ia[10];
	for (int i = 0; i != 10; i++)
	{
		get(ia, i) = i;
	}

	for (auto c : ia)
	{
		cout << c;
	}
	cout << endl;

	system("pause");
	return 0;
}