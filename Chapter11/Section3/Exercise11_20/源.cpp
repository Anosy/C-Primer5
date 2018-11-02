#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

string trans(string s)
{
	for (unsigned i = 0; i < s.size(); ++i)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] -= ('A' - 'a');
		}
		else if (s[i] == ',' || s[i] == '.')
		{
			s.erase(i, 1);
		}
	}
	return s;
}

int main()
{
	map<string, size_t> word_count;
	string word;
	while (cin >> word)
	{
		auto ret = word_count.insert({ word, 1 });
		if (!ret.second) // ����������ʲô��������˵���Ѿ���Ԫ�أ��򽫶�Ӧ��Ԫ��ֵ��1
		{
			++ret.first->second;
		}
	}

	for (const auto &s : word_count)
	{
		cout << s.first << " occurs " << s.second << ((s.second > 1) ? " times " : " time ") << endl;
	}

	system("pause");
	return 0;

}