#include<iostream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

void add_child(multimap<string, string> &families, const string &family, const string &child)
{
	families.insert({ family, child });  // 之前的版本中，由于需要考虑map它将无法插入已经存在的元素
}

int main()
{
	multimap<string, string> families;
	add_child(families, "张", "哈哈");
	add_child(families, "刘", "二狗");
	add_child(families, "张", "强");

	for (const auto &f : families)
	{
		cout << f.first << "家的孩子：" << f.second << endl;
	}

	system("pause");
	return 0;
}