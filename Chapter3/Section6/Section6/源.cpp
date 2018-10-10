// 多维度数组， 读取方式由内到外
#include<iostream>
using namespace std;


int main()
{
	int ia1[3][4]; // 大小为3的数组，每个元素含有4个整数的数组

	int arr[10][20][30]; // 大小为10的数组，每个元素都是大小为20的数组，这些数组的元素含有30个整数的数组

	int ia2[3][4] = { // 大小为3的数组，数组的每个元素都是大小为4的数组
		{0, 1, 2, 3},  // 第一行的初始化
		{4, 5, 6, 7},  // 第二行的初始化
		{8, 9, 10, 11} // 第三行的初始化
	};

	int ia3[3][4] = { 0,1,2,3,5,6,7,8,9,10,11 }; // 与上面的等价

	int ia4[3][4] = { {0}, {4}, {8} }; // 初始化每行的第一个元素

	int ix[3][4] = { 0 ,1, 2, 3 }; // 初始化第一行的元素

	constexpr size_t rowCnt = 3, colCnt = 4;
	int ia5[rowCnt][colCnt];
	for (size_t i = 0; i != rowCnt; i++)
	{
		for (size_t j = 0; j != colCnt; j++)
		{
			ia5[i][j] = i * colCnt + j;
		}
	}

	size_t cnt = 0;
	int ia6[3][4];
	for (auto &a : ia6)
		for (auto &b : a)
		{
			b = cnt;
			++cnt;
		}

	for (auto p = ia5; p != ia5 + 3; p++)
	{
		for (auto q = *p; q != *p + 4; q++)
		{
			cout << *q << " ";
		}
		cout << endl;
	}


	for (auto p = begin(ia6); p != end(ia6); p++)
	{
		for (auto q = begin(*p); q != end(*p); q++)
		{
			cout << *q << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}