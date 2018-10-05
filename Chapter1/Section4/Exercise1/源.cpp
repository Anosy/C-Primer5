#include<iostream>
int main()
{
	int sum = 0, val = 50;
	while (val<=100)
	{
		sum += val;
		++val;
	}
	std::cout << "数50到数100的和为：" << sum << std::endl;
	system("pause");
	return 0;
}