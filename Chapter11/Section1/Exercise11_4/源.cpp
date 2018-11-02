#include<iostream>
#include<map>
#include<set>
#include<string>

using namespace std;

string trans(string s)
{
	for (unsigned i = 0; i < s.size(); ++i)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] -= ('A' - 'a');
		}
		else if (s[i] == ',' || s[i] == '.')
		{
			s.erase(i, 1);
		}
	}
	return s;
}

int main()
{
	map<string, unsigned> word_count;
	string word;
	while (cin >> word)
	{
		++word_count[trans(word)];
	}
	for (const auto &s : word_count)
	{
		cout << s.first << " occurs " << s.second << ((s.second > 1) ? " times " : " time ") << endl;
	}

	system("pause");
	return 0;
}