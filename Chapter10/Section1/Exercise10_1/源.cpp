#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

int main()
{
	std::vector<int> vInt = { 1, 2, 3, 4, 5, 1, 2, 3, 54, 3, 4, 3, 32, 2, 3, 4, 1, 2, 3 };
	auto result = count(vInt.begin(), vInt.end(), 2);
	cout << "出现的次数为：" << result << endl;

	system("pause");
	return 0;
}