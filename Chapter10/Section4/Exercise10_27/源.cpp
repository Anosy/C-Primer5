#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<iterator>
#include<string>

using namespace std;

int main()
{
	vector<string> vStr = { "mike" ,"He", "He", "red", "red", "red", "hi", "she", "apple" , "s" };
	list<string> lStr;
	unique_copy(vStr.cbegin(), vStr.cend(), back_inserter(lStr));

	for (const auto s : lStr)
	{
		cout << s << " ";
	}
	cout << endl;

	system("pause");
	return 0;

}