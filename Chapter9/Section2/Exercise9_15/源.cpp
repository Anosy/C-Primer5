#include<vector>
#include<iostream>

using namespace std;

int main()
{
	vector<int> vInt1 = { 1, 2, 3 };
	vector<int> vInt2 = { 1, 3 };

	if (vInt1>vInt2)
	{
		cout << "前者比后者大" << endl;
	}
	else if (vInt1 < vInt2)
	{
		cout << "前者比后者小" << endl;
	}
	else
	{
		cout << "前者比后者相等" << endl;
	}
	
	system("pause");
	return 0;
}