#include<vector>
#include<string>
#include<iostream>
using std::vector;
using std::string;
using namespace std;

int main()
{
	vector<string> vString;
	string s;
	char cnt = 'y';
	cout << "�������һ����" << endl;

	while (cin>>s)
	{
		vString.push_back(s);
		cout << "�Ƿ��������(y/n)?" << endl;
		cin >> cnt;
		if (cnt != 'y' && cnt != 'Y')
		{
			break;
		}
		cout << "��������һ����" << endl;

	}
	for (auto &mem : vString) // ��ȡvector�е�ÿ��Ԫ��
	{
		for (auto &c : mem) // ��ȡÿ��Ԫ�ص�ÿ���ַ�
		{
			c = toupper(c);
		}
		cout << mem << endl;
	}

	system("pause");
	return 0;
}