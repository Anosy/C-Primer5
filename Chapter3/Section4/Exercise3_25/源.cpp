#include<vector>
#include<string>
#include<iostream>
using std::vector;
using std::string;
using namespace std;

int main()
{
	vector<unsigned> score(11, 0);
	unsigned grade;

	cout << "������0~100�����֣�" << endl;

	while (cin >> grade)
	{
		if (grade <= 100)
			++score[grade / 10];
	}

	for (auto it = score.cbegin(); it != score.cend(); it++)
	{
		cout << *it << " " << endl;
	}

	system("pause");
	return 0;
}