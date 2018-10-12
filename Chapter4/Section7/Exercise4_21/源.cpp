#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>

using namespace std;

int main()
{
	vector<int> vInt;
	srand((unsigned)time(NULL)); // 生成随机种子
	int num = 0;

	for (int i = 0; i < 10; i++)
	{
		num = rand() % 10;
		vInt.push_back(num);
	}
	cout << "产生的vector的内容为：" << endl;

	for (auto c: vInt)
	{
		cout << c << " " << endl;
	}

	for (auto &v : vInt)
	{
		// (v % 2 == 0) ? (v = v) : (v *= 2);
		v = (v % 2 == 0) ? v : v * 2;
	}

	cout << "变化后的vector的内容为：" << endl;

	for (auto d : vInt)
	{
		cout << d << " " << endl;
	}



	system("pause");
	return 0;
}