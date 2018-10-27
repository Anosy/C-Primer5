#include<string>
#include<iostream>
#include<deque>
using namespace std;

int main()
{
	string str;
	deque<string> dStr;

	while (cin >> str)
	{
		dStr.push_back(str);
	}

	for (auto it = dStr.begin(); it != dStr.end(); ++it)
	{
		cout << *it << endl;
	}

	system("pause");
	return 0;
}