#include<vector>
#include<iostream>

using namespace std;

int main()
{
	vector<int> vInt = { 1, 2, 3 };
	auto beg = vInt.begin();
	auto end = vInt.end() -1;
	auto hah = vInt.erase(beg, end);
	
	cout << *hah << endl;

	for (auto c : vInt)
	{
		cout << c;
	}
	cout << endl;

	system("pause");
	return 0;
}