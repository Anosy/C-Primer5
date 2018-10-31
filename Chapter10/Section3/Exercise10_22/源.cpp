#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<functional>


using namespace std;
using namespace std::placeholders;

void elimDups(vector<string> &s)
{
	sort(s.begin(), s.end());
	auto end_unique = unique(s.begin(), s.end());
	s.erase(end_unique, s.end());
}z

bool func(string &s, string::size_type sz)
{
	return s.size() >= sz;
}

int main()
{
	int sz = 6;
	vector<string> vStr = { "mikeee" ,"He", "He", "red", "red", "red", "h", "hi", "she", "apple" , "lambda1" };
	elimDups(vStr);
	auto wc = stable_partition(vStr.begin(), vStr.end(), bind(func, _1, sz));
	auto count = wc - vStr.begin();
	cout << "有" << count << "个长度大于等于" << sz << "的字符串" << endl;

	system("pause");
	return 0;
}