#include<string>
#include<iostream>

using namespace std;

int main()
{
	string str1, str2;
	do
	{
		cout << "�����������ַ�����" << endl;
		cin >> str1 >> str2;
		
		if (str1.size() > str2.size())
		{
			cout << "��һ���ַ����ȵڶ��ַ�����" << endl;
		}
		else if (str1.size() < str2.size())
		{
			cout << "��һ���ַ����ȵڶ��ַ�����" << endl;

		}
		else
		{
			cout << "�����ַ���������ͬ" << endl;
		}
		
	} while (cin);

	system("pause");
	return 0;
}