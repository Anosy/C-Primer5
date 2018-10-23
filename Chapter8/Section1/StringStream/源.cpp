#include<string>
#include<vector>
#include<iostream>
#include<sstream>

using namespace std;

struct PersonInfo
{
	string name;
	vector<string> phones;
};

int main()
{
	string line, word;
	vector<PersonInfo> people;
	while (getline(cin, line))
	{
		PersonInfo info;
		istringstream record(line);
		record >> info.name;
		while (record >> word)
		{
			// cout << word << endl;
			info.phones.push_back(word);
		}
		people.push_back(info);
	}
	for (auto c : people)
	{
		cout << c.phones[1] << endl;
	}

	system("pause");
	return 0;
}