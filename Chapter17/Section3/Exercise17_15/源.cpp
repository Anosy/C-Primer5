#include<iostream>
#include<regex>
#include<string>

using namespace std;

int main()
{
	string s("[[:alpha:]]*[^c]ei[[:alpha:]]*");
	regex r(s);
	smatch results;
	string str;
	while (true)
	{
		cin >> str;
		if (str == "q")
		{
			break;
		}
		if (regex_search(str, results, r))
		{
			cout << results.str() << endl;
		}
	}

	system("pause");
	return 0;
}