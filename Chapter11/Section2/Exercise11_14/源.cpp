#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<map>

using namespace std;

void add_family(map<string, vector<pair<string, string>>> &families, const string &family)
{
	families[family];
}

void add_child(map<string, vector<pair<string, string>>> &families, const string &family, const string &child, const string &birthday)
{
	families[family].push_back({ child, birthday });
}

int main()
{
	map<string, vector<pair<string, string>>> families;
	add_family(families, "张");
	add_family(families, "刘");
	add_child(families, "张", "小张", "1995-10-10");
	add_child(families, "张", "老六", "1995-11-11");
	add_child(families, "刘", "拉拉", "1995-1-1");


	for (const auto &f : families)
	{
		cout << f.first << "家的孩子: ";
		for (const auto &c : f.second)
		{
			cout << c.first << " (生日：" << c.second << "),";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
