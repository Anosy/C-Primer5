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
	cout << "���������ַ����ܵ��ú���" << endl;
	char ch;
	while (cin >> ch)
	{
		cout << "�ұ�������" << fact() << "��" << endl;
	}

	return 0;
}