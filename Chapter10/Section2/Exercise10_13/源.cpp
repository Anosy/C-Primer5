#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

bool func(const string &s)
{
	return (s.size() >= 5);
}

int main()
{
	vector<string> vStr = {"funny day", "hello" ,"mikee" ,"He", "He", "red", "red", "red", "hi", "she", "apple" , "s" };
	auto end_part = partition(vStr.begin(), vStr.end(), func);

	for (auto iter = vStr.begin(); iter != end_part; ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}