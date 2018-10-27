#include<iostream>
#include<string>

using namespace std;

void func(string &name, const string &prefix, const string &suffix)
{
	name.insert(name.begin(), 1, ' ');
	name.insert(name.begin(), prefix.begin(), prefix.end());
	name.append(" ");
	name.append(suffix);
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