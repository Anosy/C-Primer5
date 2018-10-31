#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

void elimDups(vector<string> &s)
{
	sort(s.begin(), s.end());
	auto end_unique = unique(s.begin(), s.end());
	s.erase(end_unique, s.end());
}


void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size(); });
	auto wc = find_if(words.begin(), words.end(), [sz](string &w) {return w.size() >= sz; });
	auto count = words.end() - wc;
	cout << "有" << count << "个长度大于等于" << sz << "的字符串" << endl;
	for_each(wc, words.end(), [](const string &s) {cout << s << " "; });
	cout << endl;
}

int main()
{
	vector<string> vStr = { "mike" ,"He", "He", "red", "red", "red", "hi", "she", "apple" , "s" };
	biggies(vStr, 3);

	system("pause");
	return 0;
}