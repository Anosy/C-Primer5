#include<iostream>
#include<string>
using namespace std;

int main()
{
	cout << "ÇëÊäÈë³É¼¨" << endl;

	int grade;
	string finallgrade;

	while (cin >> grade && grade > 0 && grade <= 100)
	{
		finallgrade = (grade < 60) ? "fail" : (grade < 75) ? "low pass" : (grade < 90) ? "pass" : "high pass";
		cout << finallgrade;
	}

	system("pasue");
	return 0;
}