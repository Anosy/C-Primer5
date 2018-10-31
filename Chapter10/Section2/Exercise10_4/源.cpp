#include<vector>
#include<iostream>
#include<numeric>
#include<algorithm>

using namespace std;

int main()
{
	vector<double> vInt{ 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8 };
	auto result = accumulate(vInt.cbegin(), vInt.cend(), 0.0);
	cout << "求和的结果为" << result << endl;

	system("pause");
	return 0;
}