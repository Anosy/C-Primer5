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
	
	cout << "请输入一个字符串，可以包含空格: " << endl;
	getline(cin, s);

	for (auto &c : s)
	{
		
		c = 'X';
	}
	cout << s << endl;


	system("pause");
	return 0;
}