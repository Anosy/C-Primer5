#include<vector>
#include<iostream>
using namespace std;

int main()
{
	int a[10];
	for (unsigned i = 0; i < 10; i++)
		a[i] = i;
	
	cout << "�����ֵΪ��" << endl;

	for (auto c : a)
		cout << c << " " << endl;

	vector<int> vInt(begin(a), end(a));

	cout << "������ֵΪ��" << endl;
	
	for (auto v: vInt)
	{
		cout << v << " " << endl;
	}

	system("pause");
	return 0;
}