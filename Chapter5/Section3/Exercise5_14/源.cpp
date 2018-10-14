#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	string currStr, preStr = " ", maxStr;

	unsigned currCnt = 1, maxCnt = 0;
	cout << "请输入多个单词" << endl;

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
		cout << "出现最多的单词为: " << maxStr << "且出现了" << maxCnt << "次" << endl;
	}
	else
	{
		cout << "没有连续出现的单词！" << endl;
	}


	system("pause");
	return 0;
}