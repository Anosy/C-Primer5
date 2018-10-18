#include<iostream>
#include<vector>

using namespace std;

void func(vector<int> vInt, unsigned index)
{
	auto sz = vInt.size();
	#ifndef NDEBUG
	cout << "vector对象的大小为:" << sz << endl;
	#endif // NDEBUG

	if (!vInt.empty() && index != sz)
	{
		
		cout << vInt[index] << endl;
		func(vInt, ++index);
	}
}


int main()
{
	vector<int>  vInt = { 1, 3, 5, 7 ,9 };
	func(vInt, 1);

	system("pause");
	return 0;
}