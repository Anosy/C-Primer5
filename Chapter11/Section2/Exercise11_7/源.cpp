#include<map>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

void add_family(map<string, vector<string>> & families, const string &family)
{
	if (families.find(family) == families.end())
	{
		families[family] = vector<string>();
	}
}

void add_child(map<string, vector<string>> & families, const string &family, const string &child)
{
	families[family].push_back(child);
}

int main()
{
	map<string, vector<string>> families;
	add_family(families, "赵");
	add_family(families, "刘");
	add_child(families, "赵", "大宝");
	add_child(families, "赵", "小宝");
	add_child(families, "刘", "二狗");

	for (auto f : families)
	{
		cout << f.first << "家的孩子：";
		for (auto c : f.second)
		{
			cout << c << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;

}