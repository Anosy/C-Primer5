#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	char cal1[80], cal2[80];

	cout << "�����������ַ���:" << endl;

	cin >> cal1 >> cal2;

	if (strcmp(cal1, cal2) == 0)
		cout << "�����ַ�����ͬ��" << endl;
	else if (strcmp(cal1, cal2) > 0)
		cout << "��һ���ַ����ȵڶ����ַ�����!" << endl;
	else
		cout << "��һ���ַ����ȵڶ����ַ���С��" << endl;
	system("pause");
	return 0;
}