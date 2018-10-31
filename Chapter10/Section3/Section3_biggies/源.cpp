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

string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size(); });
	auto wc = find_if(words.begin(), words.end(), [sz](const string &s) {return s.size() >= sz; });
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s") << "of length" << sz << "or longer" << endl;
	for_each(wc, words.end(), [](const string &s) {cout << s << " "; });
}
