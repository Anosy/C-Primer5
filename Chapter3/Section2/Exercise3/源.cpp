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

	for (auto &c : s)
	{
		
		c = 'X';
	}
	cout << s << endl;


	system("pause");
	return 0;
}