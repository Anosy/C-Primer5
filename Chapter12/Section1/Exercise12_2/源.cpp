#include<iostream>
#include"StrBlob.h"

using namespace std;

int main()
{
	// 共享数据
	StrBlob b1;
	{
		StrBlob b2 = {"a", "an", "the"};
		b1 = b2;
		b2.push_back("about");
		cout << b2.size() << endl;
	}
	cout << b1.size() << endl;
	cout << b1.front() << " " << b1.back() << endl;
	StrBlob b3 = b1;
	cout << b3.front() << " " << b3.back() << endl;

	// 非共享数据
	
	vector<string> str1;
	{
		vector<string> str2 = { "a", "b", "c" };
		vector<string> str1 = str2;
		cout << str2.size() << endl;
	} 
	cout << str1.size() << endl;

	system("pause");
	return 0;
}