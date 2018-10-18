#include<iostream>
#include "Chapter6.h"

using namespace std;

int main()
{
	cout << "输入任意字符就能调用函数" << endl;
	char ch;
	while (cin >> ch)
	{
		cout << "我被调用了" << fact() << "次" << endl;
		say_hello();
	}
}