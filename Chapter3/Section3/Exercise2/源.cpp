#include<string>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<string> vString;
	string s;
	char cont = 'y';
	while (cin>>s)
	{
		vString.push_back(s);
		cout << "�Ƿ�Ҫ�������룺(y/n)?  " << endl;
		cin >> cont;
		if (cont != 'y' && cont != 'Y')
		{
			break;
		}
	}

	for (auto mem : vString)
	{
		cout << mem << endl;
	}

	system("pause");
	return 0;
}