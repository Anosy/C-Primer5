#include<iostream>
#include<string>

using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
	return (ctr > 1) ? word + ending : word;
}

int main()
{
	size_t ctr = 2;
	string word = "Apple";
	cout << make_plural(ctr, word) << endl;

	system("pause");
	return 0;
}
