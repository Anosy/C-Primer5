#include<iostream>

using namespace std;

void fact(int v1)
{
	if (v1==1)
	{
		cout << "猜对了！" << endl;
	}
	else
	{
		cout << "没有猜对哦！" << endl;
	}
}

int main()
{
	cout << "请猜一个数：" << endl;
	int num;
	while (cin >> num)
	{
		fact(num);
	}
	return 0;
}