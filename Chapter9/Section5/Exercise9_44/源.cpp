#include<iostream>
#include<string>

using namespace std;

void change(string &s, const string &oldVal, const string &newVal)
{
	int p = 0;
	while ((p=s.find(oldVal, p)) != string::npos)
	{
		s.replace(p, oldVal.size(), newVal);
		p += newVal.size();
	}
}


int main()
{
	string s("tho i like tho");
	string oldVal("tho");
	string newVal("though");

	change(s, oldVal, newVal);
	cout << s << endl;

	system("pause");
	return 0;
	
}