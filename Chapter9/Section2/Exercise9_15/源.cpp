#include<vector>
#include<iostream>

using namespace std;

int main()
{
	vector<int> vInt1 = { 1, 2, 3 };
	vector<int> vInt2 = { 1, 3 };

	if (vInt1>vInt2)
	{
		cout << "ǰ�߱Ⱥ��ߴ�" << endl;
	}
	else if (vInt1 < vInt2)
	{
		cout << "ǰ�߱Ⱥ���С" << endl;
	}
	else
	{
		cout << "ǰ�߱Ⱥ������" << endl;
	}
	
	system("pause");
	return 0;
}