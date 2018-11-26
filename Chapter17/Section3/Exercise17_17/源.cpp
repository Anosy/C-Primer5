#include<iostream>
#include<regex>
#include<string>

using namespace std;

int main()
{
	try
	{
		string pattern("[[:alnum:]]*[^c]ei[[:alpha:]]*");
		regex r(pattern, regex::icase);
		string test_word = { "receipt freind theif receive" };
		for (sregex_iterator it(test_word.begin(), test_word.end(), r), end_it; it != end_it; ++it)
		{
			cout << it->str() << endl;
		}
	}
	catch (regex_error e)
	{
		cout << e.what() << "\ncode: " << e.code() << endl;
	}


	system("pause");
	return 0;
}