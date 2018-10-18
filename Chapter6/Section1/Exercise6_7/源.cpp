#include<iostream>

using namespace std;

int fact()
{
	static int cnt = 0;
	++cnt;
	return cnt;
}

int main()
{
	cout << "输入任意字符就能调用函数" << endl;
	char ch;
	while (cin >> ch)
	{
		cout << "我被调用了" << fact() << "次" << endl;
	}

	return 0;
}