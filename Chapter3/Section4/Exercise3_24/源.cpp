#include<vector>
#include<string>
#include<iostream>
using std::vector;
using std::string;
using namespace std;

int main()
{
	vector<int> vInt;
	int iVal;
	cout << "������һ�����ݣ�" << endl;
	while (cin>>iVal)
	{
		vInt.push_back(iVal);
	}

	if (vInt.begin() == vInt.end())
	{
		cout << "û���������ݣ�" << endl;
		return -1;
	}
	
	cout << "�����������ĺ�Ϊ��" << endl;

	for (auto it = vInt.cbegin(); it != vInt.cend()-1; it++)
	{
		cout << (*it + *(++it)) << endl;
	}
	if (vInt.size() % 2 != 0)
	{
		cout << *(vInt.cend() - 1);
	}


	system("pause");
	return 0;
}