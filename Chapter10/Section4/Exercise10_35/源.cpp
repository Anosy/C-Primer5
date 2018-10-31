#include<fstream>
#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<int> vInt = { 1,2,3,4,5,6,7,8,9 };
	for (auto it = vInt.end(); it != vInt.begin(); )
	{
		cout << *(--it) << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}