#include<iostream>
#include<map>
#include<set>
#include<string>

using namespace std;

int main()
{
	// 使用map
	/*map<string, unsigned> word_count;
	string word;
	while (cin >> word)
	{
		++word_count[word];
	}
	for (const auto &s : word_count)
	{
		cout << s.first << " occurs " << s.second << ((s.second > 1) ? " times " : " time ") << endl;
	}*/

	// 使用set
	map<string, unsigned> word_count2;
	set<string> exclude = { "a", "b", "c" };
	string word2;
	while (cin >> word2)
	{
		if (exclude.find(word2) == exclude.end())
		{
			++word_count2[word2];
		}
	}
	for (const auto &s : word_count2)
	{
		cout << s.first << " occurs " << s.second << ((s.second > 1) ? " times " : " time ") << endl;
	}


	system("pause");
	return 0;
}