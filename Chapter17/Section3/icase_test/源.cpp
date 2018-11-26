#include<regex>
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string pattern("\\.(cpp|cxx|cc)$"); // 后缀的类型
	pattern = "[[:alnum:]]+" + pattern; // 可以匹配一个或者多个
	regex r(pattern, regex::icase);
	smatch result;
	string filename;
	while (cin >> filename)
	{
		if (regex_search(filename, result, r))
		{
			cout << result.str() << endl;
		}
	}

	system("pause");
	return 0;
}