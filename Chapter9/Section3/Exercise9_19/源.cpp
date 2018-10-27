#include<string>
#include<iostream>
#include<list>
using namespace std;

int main()
{
	string str;
	list<string> lStr;

	while (cin >> str)
	{
		lStr.push_back(str);
	}

	for (auto it = lStr.begin(); it != lStr.end(); ++it)
	{
		cout << *it << endl;
	}

	system("pause");
	return 0;
}