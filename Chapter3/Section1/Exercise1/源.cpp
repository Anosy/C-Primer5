#include<iostream>	
using std::cin;
using std::cout;
using std::endl;
int main()
{
	cout << "请输入两个数字：" << endl;
	int v1, v2;
	cin >> v1 >> v2;
	if (v1 > v2)
	{
		while (v1 >=v2)
		{
			cout << v1 << endl;
			v1--;

		}
	}
	else
	{
		while (v1<=v2)
		{
			cout << v1 << endl;
			v1++;

		}
	}

	system("pause");
	return 0;
}