#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> vInt1 = { 0, 1, 2, 3, 4 ,5, 6};
	vector<int> vInt2 = { 0, 1, 2, 3, 4, 5 };
	
	auto begin1 = vInt1.begin();
	auto begin2 = vInt2.begin();
	auto end1 = vInt1.end();
	auto end2 = vInt2.end();

	while (begin1 != end1 && begin2!= end2)
	{
		if (*begin1 != *begin2)
		{
			cout << "����û��ǰ׺��ϵ��" << endl;
			break;
		}
		++begin1;
		++begin2;
	}
	if (begin1==end1)
	{
		cout << "ǰ���Ǻ��ߵ�ǰ׺��" << endl;
	}
	if (begin2==end2)
	{
		cout << "������ǰ�ߵ�ǰ׺��" << endl;
	}

	system("pause");
	return 0;
}