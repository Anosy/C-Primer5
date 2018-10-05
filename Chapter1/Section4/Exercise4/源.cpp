#include<iostream>
int main()
{
	int sum = 0;
	for (int i = 50; i <= 100; i++)
	{
		sum += i;
	}
	std::cout << "计算得到50~100的和为："<< sum << std::endl;
	system("pause");
	return 0;
}