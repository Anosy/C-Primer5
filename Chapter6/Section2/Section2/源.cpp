// 指针形参
#include<iostream>

using namespace std;

// 接受一个指针，然后让指针所指的位置的值置0
void reset(int *ip)
{
	*ip = 0; // 改变指针所指对象的值
	ip = 0; // 值改变ip的局部拷贝，实参没有改变
}

int main()
{
	int i = 42;
	int *p = &i;
	reset(p);
	cout << "i = " << i << endl;

	system("pause");
	return 0;
}