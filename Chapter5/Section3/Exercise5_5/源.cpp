#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	int grade;
	cout << "请输入你需要查询的成绩" << endl;

	cin >> grade;

	if (grade<0 || grade > 100)
	{
		cout << "输入的成绩有误！" << endl;
	}
	else if (grade < 60)
	{
		cout << "F" << endl;
	}
	else if (grade < 70)
	{
		cout << "E" << endl;
	}
	else if (grade < 80)
	{
		cout << "D" << endl;
	}
	else if (grade < 90)
	{
		cout << "B" << endl;
	}
	else if (grade < 100)
	{
		cout << "A" << endl;
	}
	else
	{
		cout << "A+" << endl;
	}

	system("pause");
	return 0;
}