#include<iostream>

using namespace std;


// 定义函数
int fact(int val)
{
	int ret = 1;
	while (val>1)
	{
		ret *= val--; // 将ret和val的值相乘，任何将结果给赋值给ret，并且将val-1
	}
	return ret;
}

// 调用函数
int main()
{
	int j = fact(5);
	cout << "5! is" << j << endl;
	return 0;
}
