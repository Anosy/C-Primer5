#include<iostream>
int main()
{
	int sum = 0, val = 1;
	// 只要val的值小于等于10，while循环就会持续的执行
	while(val<=10)
	{
		sum += val; // 将sum+val的值给赋予sum
		++val; // 将val加1
	}
	std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
	system("pause");
	return 0;
}