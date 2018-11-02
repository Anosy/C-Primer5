#include<unordered_map>
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;

unordered_map<string, string> buildMap(ifstream &map_file)
{
	unordered_map<string, string> trans_map;
	string key, value;
	while (map_file >> key, getline(map_file, value))
	{
		if (value.size() > 1)
		{
			trans_map[key] = value.substr(1); // 跳过第一个空格
		}
		else
		{
			throw runtime_error("没有对应" + key + "的规则");
		}
	}
	return trans_map;
}

const string & transform(const string &s, const unordered_map<string, string> &m)
{
	auto map_it = m.find(s);
	if (map_it != m.end())
	{
		return map_it->second;
	}
	else
	{
		return s;
	}
}

void word_transform(ifstream &map_file, ifstream & input)
{
	auto trans_map = buildMap(map_file);
	string text;
	while (getline(input, text))
	{
		istringstream stream(text);
		string word;
		bool firstword = true;
		while (stream >> word)
		{
			if (firstword)
			{
				firstword = false;
			}
			else
			{
				cout << " ";
			}
			cout << transform(word, trans_map);
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