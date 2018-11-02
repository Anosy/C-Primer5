#include<unordered_map>
#include<iostream>
#include<string>

using namespace std;

int main()
{
	unordered_map<string, size_t> word_count;
	string word;
	while (cin >> word)
	{
		++word_count[word];
	}

	for (const auto &w : word_count)
	{
		cout << w.first << "出现了" << w.second << "次"<< endl;
	}

	system("pause");
	return 0;
}