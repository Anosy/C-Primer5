#include<iostream>

using namespace std;

int fact(int val)
{
	int result = 1;
	if (val < 0)
	{
		return -1;
	}

	while (val>1)
	{
		result *= val--;
	}
	return result;
}

int main()
{
	cout << "������һ�����֣�" << endl;
	int num;

	cin >> num;
	int result = fact(num);
	if (result == -1)
	{
		cout << "�������������" << endl;
		system("pause");
		return -1;
	}
	cout << "�׳˼���Ľ��Ϊ��" << result << endl;
	
	system("pause");
	return 0;
}