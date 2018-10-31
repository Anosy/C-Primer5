#include<list>
#include<iostream>
#include<string>

using namespace std;

void elimDups(list<string> &words)
{
	words.sort();
	words.unique();
}

int main()
{
	list<string> lStr = { "mike" ,"He", "He", "red", "red", "red", "hi", "she", "apple" , "s" };
	elimDups(lStr);

	for (auto l : lStr)
	{
		cout << l << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}