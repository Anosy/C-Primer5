#include<iostream>
#include<vector>

using namespace std;

void func(vector<int> vInt, unsigned index)
{
	unsigned sz = vInt.size();
	if (!vInt.empty() && index < sz)
	{
		cout << vInt[index] << endl;
		func(vInt, ++index);  // ÿ�ε����������䣬index�ı�
	}
}

int main()
{
	vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8 };
	func(v, 0);

	system("pause");
	return 0;
}