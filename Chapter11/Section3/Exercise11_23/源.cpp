#include<iostream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

void add_child(multimap<string, string> &families, const string &family, const string &child)
{
	families.insert({ family, child });  // ֮ǰ�İ汾�У�������Ҫ����map�����޷������Ѿ����ڵ�Ԫ��
}

int main()
{
	multimap<string, string> families;
	add_child(families, "��", "����");
	add_child(families, "��", "����");
	add_child(families, "��", "ǿ");

	for (const auto &f : families)
	{
		cout << f.first << "�ҵĺ��ӣ�" << f.second << endl;
	}

	system("pause");
	return 0;
}