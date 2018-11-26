#include<iostream>
#include<string>
#include<regex>

using namespace std;

int main()
{
	regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
	//smatch results;
	cmatch results;
	if (regex_search("myfile.cc", results, r))
	{
		cout << results.str() << endl;
	}

	system("pause");
	return 0;
}