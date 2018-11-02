#include<iostream>
#include<map>
#include<set>
#include<string>

using namespace std;

int main()
{
	map<string, unsigned> word_count;
	string word;
	while (cin >> word)
	{
		++word_count[word];
	}
	for (const auto &s : word_count)
	{
		cout << s.first << " occurs " << s.second << ((s.second > 1) ? " times " : " time ") << endl;
	}

	system("pause");
	return 0;
}