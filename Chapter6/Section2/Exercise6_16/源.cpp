#include<iostream>
#include<string>

using namespace std;

bool isUp(const string &str)
{
	for (const auto c : str)
	{
		if (isupper(c))
		{
			return true;
		}
	}
	return false;
}

void translow(string &str)
{
	for (auto &c : str)
	{
		c = tolower(c);
	}
}



int main()
{
	string str;
	cout << "������һ���ַ�����" << endl;

	cin >> str;
	if (isUp(str))
	{
		translow(str);
		cout << "ת������ַ���Ϊ��" << str << endl;
	}
	else
	{
		cout << "���ַ�û�д�д��ĸ������ת��" << endl;
	}

	system("pause");
	return 0;
}