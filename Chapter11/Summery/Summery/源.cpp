#include<map>
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;

map<string, string> build_map(ifstream & in)
{
	string key;
	string value;
	map<string, string> trans_map;

	while (in >> key && getline(in, value))
	{
		if (value.size() > 1)
		{
			trans_map[key] = value.substr(1);
		}
		else
		{
			throw runtime_error("没有对应" + key + "的规则");
		}
	}
	return trans_map;
}

const string & transform(const string &s, const map<string, string> &m)
{
	auto map_it = m.find(s);
	if (map_it != m.end())
	{
		return map_it ->second;
	}
	else
	{
		return s;
	}
}

void word_transform(ifstream &in, ifstream & input)
{
	auto transmap = build_map(in);
	string line;
	while (getline(input, line))
	{
		istringstream iss(line);
		string word;
		bool first_line = true;

		while (iss >> word)
		{
			if (first_line)
			{
				first_line = false;
			}
			else
			{
				cout << " ";
			}
			cout << transform(word, transmap);
		}
		cout << endl;
	}
}


int main()
{
	ifstream map_file("data/dict.txt");
	ifstream input("data/trans.txt");
	word_transform(map_file, input);

	system("pause");
	return 0;
}
