#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> vInt1 = {0, 1, 2, 3, 4};
	vector<int> vInt2 = {0, 1, 2, 3, 4, 5};

	auto size1 = vInt1.size();
	auto size2 = vInt2.size();

	if (size1 > size2)
	{
		for (unsigned i = 0; i < size2; i++)
		{
			if (vInt1[i] != vInt2[i])
			{
				cout << "����vector���󲻴��ڰ�����ϵ" << endl;
			}
		}
		cout << "������ǰ�ߵ�ǰ׺��" << endl;
	}
	else if (size1 < size2)
	{
		for (unsigned i = 0; i < size1; i++)
		{
			if (vInt1[i] != vInt2[i])
			{
				cout << "����vector���󲻴��ڰ�����ϵ" << endl;
			}
		}
		cout << "ǰ���Ǻ��ߵ�ǰ׺��" << endl;
	}
	else
	{
		cout << "��vector�ȳ���" << endl;
	}


	system("pause");
	return 0;
}