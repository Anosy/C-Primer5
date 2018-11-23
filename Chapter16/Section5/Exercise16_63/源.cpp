#include<string>
#include<vector>
#include<iostream>

using namespace std;

template <typename T>
int occur(const vector<T> & vec, const T &t)
{
	int ret = 0;
	for (auto v : vec)
	{
		if (t == v)
		{
			++ret;
		}
	}
	return ret;
}

int main()
{
	vector<double> vDouble = { 1.1, 2.2, 3.3, 1.1, 1.1 };
	cout << occur(vDouble, 1.1) << endl;
	
	vector<int> vInt = { 1, 2, 3, 4, 1, 1, 1 };
	cout << occur(vInt, 1) << endl;

	vector<string> vStr = { "aa", "bb", "aa" };
	string s("aa");
	cout << occur(vStr, s) << endl;

	system("pause");
	return 0;
}