#include<iostream>
#include<regex>
#include<string>
#include<fstream>

using namespace std;

bool valid(const smatch &m)
{
	if (m[1].matched) // 如果第一位未匹配，那么第三位也必须不匹配，第4位要么是空格要么是就没有匹配
	{
		return m[3].matched && (m[4].matched == 0 || m[4].str() == string(" "));
	}
	else
	{
		return !m[3].matched && m[4].str() == m[6].str();
	}
}


int main()
{
	string phone("(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})");

	regex r(phone);
	smatch m;
	string s;
	ifstream in("data\\mydata.txt");
	if (!in)
	{
		cout << "文件为空" << endl;
	}
	while (getline(in, s))
	{
		for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it)
		{
			if (valid(*it))
			{
				cout << "valid: " << it->str() << endl;
			}
			else
			{
				cout << "not valid: " << it->str() << endl;
			}
		}
	}

	system("pause");
	return 0;
}