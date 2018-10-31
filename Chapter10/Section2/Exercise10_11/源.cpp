#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

void elimDups(vector<string> &s)
{
	sort(s.begin(), s.end());
	auto end_unique = unique(s.begin(), s.end());
	s.erase(end_unique, s.end());
}

bool isShroter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

int main()
{
	vector<string> vStr = {"mike" ,"He", "He", "red", "red", "red", "hi", "she", "apple" , "s"};
	elimDups(vStr);
	for (const auto v : vStr)
	{
		cout << v << " ";
	}
	cout << endl;
	
	stable_sort(vStr.begin(), vStr.end(), isShroter);
	for (const auto v : vStr)
	{
		cout << v << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}