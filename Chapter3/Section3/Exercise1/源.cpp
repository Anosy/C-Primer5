#include<vector>
#include<string>
#include<iostream>
using namespace std;

int main()
{
	vector<int> vInt;
	int i;
	char cont = 'y';
	while (cin>>i)
	{
		vInt.push_back(i);
		cout << "���ʻ���Ҫ������(y/n)? " << endl;
		cin >> cont;
		if (cont != 'y' && cont != 'Y')
		{
			break;
		}
	}
	for (auto c : vInt)
	{
		cout << c << endl;
	}

	system("pause");
	return 0;
}