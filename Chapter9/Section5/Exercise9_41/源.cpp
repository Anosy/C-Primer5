#include<vector>
#include<iostream>
#include<string>

using namespace std;

int main()
{
	vector<char> vChar = { 'H', 'E', 'L', 'L', 'O' };
	auto beg = vChar.begin();
	auto end = vChar.end();
	string s1(beg, end);
	cout << s1 << endl;

	string s2(vChar.data(), vChar.size()); // data返回内存空间首地址
	cout << s1 << endl;

	auto ch = "HELLO";
	cout << typeid(ch).name() << endl;

	cout << (s1 == s2) << endl;
	system("pause");
	return 0;
}