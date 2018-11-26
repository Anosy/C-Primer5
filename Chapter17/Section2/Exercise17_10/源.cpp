#include<bitset>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> vInt = { 1, 2, 3, 5, 7, 13, 21 };
	bitset<32> bset1;
	for (auto v : vInt)
	{
		bset1.set(v);
	}

	cout << "bset1: " << bset1 << endl;

	bitset<32> bset2;
	
	for (unsigned i = 0; i != 32; ++i)
	{
		bset2[i] = bset1[i];
	}
	cout << "bset2: " << bset2 << endl;
	
	system("pause");
	return 0;
}