#include<vector>
#include<string>
#include<iostream>
using std::vector;
using std::string;
using namespace std;


// 成绩统计程序
int main()
{
	vector<unsigned> scores(11, 0);
	unsigned grade;
	while (cin >> grade)
	{
		if (grade <= 100)
		{
			++scores[grade / 10];
		}
	}

	for (auto i : scores)
	{
		cout << i << endl;
	}

	system("pause");
	return 0;
}