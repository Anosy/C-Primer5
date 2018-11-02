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
	add_family(families, "��");
	add_family(families, "��");
	add_child(families, "��", "С��", "1995-10-10");
	add_child(families, "��", "����", "1995-11-11");
	add_child(families, "��", "����", "1995-1-1");


	for (const auto &f : families)
	{
		cout << f.first << "�ҵĺ���: ";
		for (const auto &c : f.second)
		{
			cout << c.first << " (���գ�" << c.second << "),";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
