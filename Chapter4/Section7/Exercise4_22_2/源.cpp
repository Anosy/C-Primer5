#include<iostream>
#include<string>
using namespace std;

int main()
{
	int grade;
	string finallgrade;

	cout << "������ɼ�" << endl;


	while (cin >> grade && grade > 0 && grade <= 100)
	{
		if (grade < 60)
		{
			finallgrade = "fail";
		}
		else if (grade < 75)
		{
			finallgrade = "low pass";
		}
		else if (grade < 90)
		{
			finallgrade = "pass";
		}
		else
		{
			finallgrade = "high pass";
		}
		cout << finallgrade << endl;
	}

	system("pause");
	return 0;
}

