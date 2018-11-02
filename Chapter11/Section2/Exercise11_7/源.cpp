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
	add_family(families, "��");
	add_family(families, "��");
	add_child(families, "��", "��");
	add_child(families, "��", "С��");
	add_child(families, "��", "����");

	for (auto f : families)
	{
		cout << f.first << "�ҵĺ��ӣ�";
		for (auto c : f.second)
		{
			cout << c << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;

}