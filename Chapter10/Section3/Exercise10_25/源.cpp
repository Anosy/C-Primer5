#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<functional>

using namespace std;
using namespace std::placeholders;

void elimDups(vector<string> &s)
{
	sort(s.begin(), s.end());
	auto end_unique = unique(s.begin(), s.end());
	s.erase(end_unique, s.end());
}

bool check_size(string &s, string::size_type sz)
{
	return s.size() >= sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size(); });
	auto wc = partition(words.begin(), words.end(), bind(check_size, _1, sz));
	auto count = wc - words.begin();
	cout << "有" << count << "个长度大于等于" << sz << "的字符串" << endl;
	for_each(words.begin(), wc, [](const string &s) {cout << s << " "; });
	cout << endl;
}

int main()
{
	vector<string> vStr = { "mike" ,"He", "He", "red", "red", "red", "hi", "she", "apple" , "s" };
	biggies(vStr, 3);

	system("pause");
	return 0;
}