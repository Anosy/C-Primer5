#include<vector>
#include<iostream>
#include<numeric>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> vInt{ 1,2,3,4,5,6,7,8 };
	auto result = accumulate(vInt.cbegin(), vInt.cend(), 0);
	cout << "求和的结果为" << result << endl;

	system("pause");
	return 0;
}