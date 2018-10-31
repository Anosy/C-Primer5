#include<vector>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
	vector<string> vStr = { "He", "He", "red", "red", "red", "hi", "she", "apple"};
	sort(vStr.begin(), vStr.end());
	auto end_unique = unique(vStr.begin(), vStr.end());
	vStr.erase(end_unique, vStr.end());

	for (const auto v : vStr)
	{
		cout << v << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}