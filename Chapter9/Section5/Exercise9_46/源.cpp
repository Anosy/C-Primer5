#include<string>
#include<iostream>

using namespace std;

void func(string &name, const string &prefix, const string &suffix)
{
	name.insert(0, " ");
	name.insert(0, prefix);
	name.insert(name.size(), " ");
	name.insert(name.size(), suffix);
}


int main()
{
	string name("Wu");
	string pre("Mr.");
	string suf("Jr.");
	func(name, pre, suf);

	cout << name << endl;
	system("pause");
	return 0;
}