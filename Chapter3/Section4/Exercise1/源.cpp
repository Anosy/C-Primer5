#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	vector<string> vString;
	string s;
	cout << "ÇëÊäÈëÒ»×é´Ê£º" << endl;

	while (cin >> s)
	{
		vString.push_back(s);
	}

	for (auto it = vString.begin(); it != vString.end(); it++)
	{
		for (auto &c: *it)
		{
			c = toupper(c);
		}
		cout << *it << endl;
	}
	
	system("pause");

	return 0;
}