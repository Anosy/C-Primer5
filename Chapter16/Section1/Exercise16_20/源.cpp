#include<iostream>
#include<vector>
#include<string>

using namespace std;

template <typename T>
void my_print(const T &t)
{	
	for (auto b = t.begin(); b != t.end(); ++b)
	{
		cout << *b << " ";
	}
}


int main()
{
	vector<int> vInt = { 1, 2, 3, 4, 3, 2, 1 };
	my_print(vInt);
	cout << endl;

	vector<string> vStr = { "Hello", "World", "!" };
	my_print(vStr);
	cout << endl;

	string s = "LOL";
	my_print(s);
	cout << endl;

	system("pause");
	return 0;
}