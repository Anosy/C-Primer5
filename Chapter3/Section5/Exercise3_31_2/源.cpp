#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	vector<int> a;
	vector<int> b;

	for (unsigned i = 0; i < 10; i++)
	{
		a.push_back(i);
	}
	
	for (unsigned j = 0; j < 10; j++)
	{
		b.push_back(a[j]);
	}

	for (auto c : b)
	{
		cout << c << endl;
	}

	unsigned s[11];
	for (auto t : s)
	{
		cout << t << endl;
	}

	system("pause");
	return 0;
}