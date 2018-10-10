#include<vector>
#include<string>
#include<iostream>
using std::vector;
using std::string;
using namespace std;

int main()
{
	vector<int> v3(10, 42);
	vector<int> v4{ 10, 42 };
	vector<string> v5(10);
	vector<string> v7(10, "hi");

	for (auto i : v3)
	{
		cout << i << endl;
	}

	for (auto i : v4)
	{
		cout << i << endl;
	}
	for (auto i : v5)
	{
		cout << i << endl;
	}
	for (auto i : v7)
	{
		cout << i << endl;
	}


	system("pause");
	return 0;
}