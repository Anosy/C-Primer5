#include<vector>
#include<string>
#include<iostream>

using namespace std;

int main()
{
	vector<string> vStr1 = {"2", "-3", "4", "5"};
	vector<string> vStr2 = {"2.2", "-3.2", "4.2", "5.2"};
	
	int sum1 = 0;
	double sum2 = 0;

	for (auto s : vStr1)
	{
		sum1 += stoi(s);
	}
	cout << sum1 << endl;

	for (auto s : vStr2)
	{
		sum2 += stod(s);
	}
	cout << sum2 << endl;


	system("pause");
	return 0;
}