#include<string>
#include<iostream>

using namespace std;

int main()
{
	string str1, str2;
	bool b1 = true;
	cout << "�����������ַ�����" << endl;
	cin >> str1;
	while (cin >> str2)
	{
		if (str1 == str2)
		{
			b1 = false;
			cout << "�������ֵĵ���Ϊ��" << str1 << endl;
			break;
		}
		str1 = str2;
	}
	if (b1)
	{
		cout << "û���������ֵĵ��ʣ�" << endl;
	}

	system("pause");
	return 0;
}