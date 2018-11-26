#include<iostream>
#include<string>
#include<regex>

using namespace std;

int main()
{
	try
	{
		regex r("[[:alnum]]+\\.(cpp|cxx|cc)$", regex::icase);
		cmatch results;
		if (regex_search("myfile.cc", results, r))
		{
			cout << results.str() << endl;
		}
	} m `
	catch (regex_error e)
	{
		cout << e.what() << "\ncode: " << e.code() << endl;
	}
	

	system("pause");
	return 0;
}