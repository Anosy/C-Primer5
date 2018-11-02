#include<map>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> vInt;
	int num;
	while (cin >> num)
	{
		if (find(vInt.begin(), vInt.end(), num) == vInt.end())
		{
			vInt.push_back(num);
		}
	}
	                           
	for (const auto &v : vInt)
	{
		cout << v << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}