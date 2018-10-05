#include<iostream>
int main()
{
	std::cout << "请输入两个数字：" << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	if (v1>=v2)
	{
		for (int i = v1; i >= v2; i--)
		{
			std::cout << i << std::endl;
		}
	}
	else
	{
		for (int i = v1; i <= v2; i++)
		{
			std::cout << i << std::endl;
		}
	}
	system("pause");
	return 0;
}