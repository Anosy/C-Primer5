#include<iostream>
#include<string>
using namespace std;

// �����������õ���������ֵ
string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
	auto ret = s.size();
	occurs = 0;
	for (decltype(ret) i = 0; i != s.size(); i++)
	{
		if (s[i] == c)
		{
			if (ret == s.size()) // �����һ�γ��֣���ô�ͽ���һ�ε�λ�ø�ֵ��ret
			{
				ret = i;
			}
			++occurs;
		}
	}
	return ret;
}

int main()
{
	string s = "Hello World";
	string::size_type ctr;
	auto index = find_char(s, 'o', ctr);
	cout << "Occur index = " << index << endl;
	cout << "Occur nums = " << ctr << endl;

	system("pause");
	return 0;
}