#include<iostream>
#include<string>
using std::endl;
using std::cin;
using std::cout;
using std::string;
using std::getline;

int main()
{
	string word;
	/*while (getline(cin, word)) // 一次读入一行
	{
		cout << word << endl;
	}*/
	while (cin>>word)
	{
		cout << word << endl;
	}
	
	system("pause");
	return 0;
}