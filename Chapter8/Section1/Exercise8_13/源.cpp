#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

struct PersonInfo
{
	string name;
	vector<string> phones;
};

string format(const string &s) { return s; }
bool valid(const string &s)
{
	return true;
}

int main()
{
	string line, word;
	vector<PersonInfo> people;
	ifstream ifs("data/mydata.txt");
	if (!ifs)
	{
		cerr << "无法打开输入文件！" << endl;
		return -1;
	}
	while (getline(ifs, line))
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
	ostringstream os;
	for (const auto &entry : people)
	{
		ostringstream formatted, badNums;
		for (const auto &nums : entry.phones)
		{
			if (!valid(nums))
			{
				badNums << " " << nums;
			}
			else
			{
				formatted << " " << format(nums);
			}
		}
		if (badNums.str().empty())
		{
			os << entry.name << " " << formatted.str() << endl;
		}
		else
		{
			cerr << "input error:" << entry.name << "invalid number(s)" << badNums.str() << endl;
		}
	}
	cout << os.str() << endl;

	system("pause");
	return 0;
}