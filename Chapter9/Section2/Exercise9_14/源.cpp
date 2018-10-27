#include<iostream>
#include<vector>
#include<list>
#include<string>

using namespace std;

int main()
{
	list<const char *> slist = { "Hello", "World" };
	vector<string> svec;
	
	svec.assign(slist.begin(), slist.end());
	cout << svec.capacity() << " " << svec.size() << " " << svec[0] << " " << svec[svec.size() - 1] << endl;

	system("pause");
	return 0;
}