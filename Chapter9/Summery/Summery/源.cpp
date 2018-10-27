#include<iostream>
#include<string>

using namespace std;

void change(string &s, const string &oldVal, const string &newVal)
{
	auto l = oldVal.size();
	if (!l)
	{
		return;
	}
	auto iter = s.begin();

	while (iter != s.end())
	{
		auto iter1 = iter;
		auto iter2 = oldVal.begin();
		while (iter2 != oldVal.end() && *iter1 == *iter2)
		{
			++iter1;
			++iter2;
		}
		if (iter2 == oldVal.end())
		{
			iter = s.erase(iter, iter1); // 删除oldVal内容
			if (newVal.size())
			{
				auto iter3 = newVal.end();
				while (iter3 != newVal.begin())
				{
					--iter3;
					iter = s.insert(iter, *iter3);
				}
			}
			iter += newVal.size(); // 将迭代器移动到新加入元素之后
		}
		else
		{
			++iter;
		}
	}
}



int main()
{
	string s("tho i like tho");
	string oldVal("tho");
	string newVal("though");

	change(s, oldVal, newVal);
	cout << s << endl;

	system("pause");
	return 0;
}