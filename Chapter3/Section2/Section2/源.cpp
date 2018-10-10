#include<iostream>
#include<string>
using std::endl;
using std::cin;
using std::cout;
using std::string;

int main()
{
	string s1;
	string s2=s1;
	string s3 = "hiya";
	string s4(10, 'c');
	string s6("hiya");

	// string s;
	// cin >> s;
	// cout << s << endl;  输入:   Hello World  输出: Hello
	
	// string ss, sss;
	// cin >> ss >> sss;
	// cout << ss << sss << endl; 输入： Hello World  输出: HelloWorld

	string word;
	while (cin>>word)
	{
		cout << word << endl;
	}

	system("pause");
	return 0;
}