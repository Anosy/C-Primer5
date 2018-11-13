#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

class IsShort
{
public:
	bool operator()(const string &s1, const string &s2)
	{
		return s1.size() < s2.size();
	}
};

class Longer
{
public:
	Longer(size_t n) :sz(n) {}
	bool operator()(const string &str)
	{
		return str.size() >= sz;
	}

private:
	size_t sz;
};

class PrintString
{
public:
	void operator()(const string &s)
	{
		cout << s << " ";
	}
};

void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

string make_plural(size_t ctr, string const& word, string const& ending)
{
	return (ctr > 1) ? word + ending : word;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end(), IsShort());
	auto wc = find_if(words.begin(), words.end(), Longer(sz));
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
	for_each(wc, words.end(), PrintString());
	cout << endl;
}	


int main()
{
	vector<string> vec{ "fox", "jumps", "over", "quick", "red", "red", "slow", "the", "turtle" };
	biggies(vec, 4);

	system("pause");
	return 0;
}