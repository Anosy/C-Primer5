#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	char s1[] = "hello";
	char s2[] = "world";
	char s3[20];
	strcat(s1, s2);
	strcpy(s3, s1);
	cout << s3 << endl;
	return 0;

	cout << "��һ���ַ���:" << s1 << endl;
	cout << "�ڶ����ַ���" << s2 << endl;
	cout << "�������ַ���" << s3 << endl;

	system("pause");
	return 0;
}