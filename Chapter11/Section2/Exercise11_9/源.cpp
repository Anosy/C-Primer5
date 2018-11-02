#include<map>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<list>

using namespace std;

string trans(string s)
{
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
}

int main()
{
	map<string, list<unsigned>> word_lineno;
	string word;
	string line;
	unsigned lineno = 0;
	ifstream in("data/mydata.txt");
	while (getline(in, line))
	{
		++lineno;
		istringstream l_in(line);
		while (l_in >> word)
		{
			word = trans(word);
			word_lineno[word].push_back(lineno);

		}
	}
	for (const auto &s : word_lineno)
	{
		cout << s.first << "所在的行：";
		for (const auto &l : s.second)
		{
			cout << l << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}