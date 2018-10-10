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

	for (auto is = v3.cbegin(); is != v3.cend(); is++)
	{
		cout << *is << endl;
	}

	cout << "\n" << endl;

	for (auto it = v4.cbegin(); it != v4.cend(); it++)
	{
		cout << *it << endl;
	}

	system("pause");
	return 0;
}
