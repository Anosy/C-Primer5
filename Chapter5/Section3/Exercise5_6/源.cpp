#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	int grade;
	string score;

	cout << "ÇëÊäÈë³É¼¨:" << endl;
	cin >> grade;
	score = (grade < 60) ? "E" : (grade < 70) ? "D" : (grade < 80) ? "C" : (grade < 90) ? "B" : (grade < 100) ? "A" : "A+";

	cout << score << endl;

	system("pause");
	return 0;
}