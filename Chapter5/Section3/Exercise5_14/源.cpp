#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	string currStr, preStr = " ", maxStr;

	unsigned currCnt = 1, maxCnt = 0;
	cout << "������������" << endl;

	while (cin >> currStr)
	{
		if (currStr == preStr)
		{
			++currCnt;
			if (currCnt > maxCnt)
			{
				maxStr = currStr;
				maxCnt = currCnt;
			}
		}
		else
		{
			currCnt = 1;
		}

		preStr = currStr;
	}

	if (maxCnt>1)
	{
		cout << "�������ĵ���Ϊ: " << maxStr << "�ҳ�����" << maxCnt << "��" << endl;
	}
	else
	{
		cout << "û���������ֵĵ��ʣ�" << endl;
	}


	system("pause");
	return 0;
}