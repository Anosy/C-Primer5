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
	cout << "�������ַ��������԰����ո�" << endl;
	getline(cin, s);

	string::size_type i = 0;
	while (s[i] != '\0')
	{
		s[i] = 'X';
		++i;

	}

	cout << s << endl;

	system("pause");
	return 0;
}