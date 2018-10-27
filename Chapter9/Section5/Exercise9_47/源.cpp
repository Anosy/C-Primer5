#include<string>
#include<iostream>

using namespace std;

int main()
{
	string s("ab2c3d7R4E6");
	string zimu("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM");
	string number("0123456789");
	unsigned pos1 = 0;
	while ((pos1 = s.find_first_of(number, pos1)) != string::npos)
	{
		cout << s[pos1];
		++pos1;
	}
	cout << endl;

	string::size_type pos2 = 0;

	while ((pos2 = s.find_first_not_of(number, pos2)) != string::npos)
	{
		cout << s[pos2];
		++pos2;
	}
	cout << endl;

	system("pause");
	return 0;
}