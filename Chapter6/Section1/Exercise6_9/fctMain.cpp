#include<iostream>
#include "Chapter6.h"

using namespace std;

int main()
{
	cout << "���������ַ����ܵ��ú���" << endl;
	char ch;
	while (cin >> ch)
	{
		cout << "�ұ�������" << fact() << "��" << endl;
		say_hello();
	}
}