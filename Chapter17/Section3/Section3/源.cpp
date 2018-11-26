#include<string>
#include<regex>
#include<iostream>
using namespace std;

int main()
{
	string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern);
	smatch result;
	string test_str = "recepit freind theif receive";

	if (regex_search(test_str, result, r))
	{
		cout << result.str() << endl;
	}

	system("pause");
	return 0;
}