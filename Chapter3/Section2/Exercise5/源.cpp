#include<iostream>
#include<string>
using std::endl;
using std::cin;
using std::cout;
using std::string;
using std::getline;

int main()
{
	string s;

	cout << "������һ���ַ��������԰����ո�: " << endl;
	getline(cin, s);

	for (char &c : s)
	{
		if (c != ' ')
		{
			c = 'X';
		}
	}
	cout << s << endl;


	system("pause");
	return 0;
}