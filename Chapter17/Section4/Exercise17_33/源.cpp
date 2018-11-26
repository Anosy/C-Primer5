#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<fstream>
#include<sstream>
#include<random>
#include<time.h>

using namespace std;


map<string, vector<string>> buildMap(ifstream & mapfile)
{
	map<string, vector<string>> trans_map;
	string key;
	string value;
	while (mapfile >> key && getline(mapfile, value))
	{
		if (value.size() > 1)
		{
			string v;
			istringstream is(value);
			while (is >> v)
			{
				trans_map[key].push_back(v);
			}
		}
		else
		{
			throw runtime_error("没有对应" + key + "的规则");
		}
	}
	return trans_map;
}


const string & transform(const string &s, const map<string, vector<string>> &m)
{
	static default_random_engine e(time(0));
	auto map_it = m.find(s);
	if (map_it != m.cend())
	{
		uniform_int_distribution<unsigned> u(0, map_it->second.size() - 1);
		return map_it->second[u(e)];
	}
	else
	{
		return s;
	}
}

void word_trans_form(ifstream &map_file, ifstream &input)
{
	auto trans_map = buildMap(map_file);
	// 打印创建的表格
	cout << "创建的翻译表: " << endl;
	for (auto entry : trans_map)
	{
		cout << "key: " << entry.first << "\t value: ";
		for (auto s : entry.second)
		{
			cout << s << " ";
		}
		cout << endl;
	}
	cout << endl;

	string text;
	while (getline(input, text))
	{
		istringstream stream(text);
		string word;
		bool first_word = true;
		while (stream >> word)
		{
			if (first_word)
			{
				first_word = false;
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
	ifstream map_file("data\\my_map.txt");
	ifstream input("data\\input.txt");
	if ((!map_file) || (!input))
	{
		throw runtime_error("存在文件为空");
	}
	word_trans_form(map_file, input);

	system("pause");
	return 0;
}