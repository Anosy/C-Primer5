#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

int main()
{
	vector<int> vInt = { 1,2,3,4,5,6,6,7,7,8 };
	fill_n(vInt.begin(), vInt.size(), 0);

	for (const auto v : vInt)
	{
		cout << v << " ";
	}
	cout << endl;
	
	system("pause");
	return 0;
}