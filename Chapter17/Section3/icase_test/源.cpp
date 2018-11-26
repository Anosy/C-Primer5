#include<regex>
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string pattern("\\.(cpp|cxx|cc)$"); // ��׺������
	pattern = "[[:alnum:]]+" + pattern; // ����ƥ��һ�����߶��
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