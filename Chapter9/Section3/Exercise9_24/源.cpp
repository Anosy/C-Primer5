#include<vector>
#include<string>
#include<iostream>

using namespace std;

int main()
{
	vector<string> vStr{ "hello", "world" };
	// vector<string> vStr;
	cout << vStr.at(0) << endl;
	cout << vStr.front() << endl;
	cout << vStr[0] << endl;
	cout << *(vStr.begin()) << endl;

	system("pause");
	return 0;
}