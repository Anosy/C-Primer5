#include<iostream>
#include<string>
using namespace std;

// 利用引用来得到两个返回值
string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
	auto ret = s.size();
	occurs = 0;
	for (decltype(ret) i = 0; i != s.size(); i++)
	{
		if (s[i] == c)
		{
			if (ret == s.size()) // 如果第一次出现，那么就将第一次的位置赋值给ret
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