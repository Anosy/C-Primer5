#include<iostream>
/*
用户输入两个数，输出用户输入的两个数之间的所有数
*/
int main()
{
	std::cout << "请输入两个数字: " << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	if (v1<=v2)
	{
		while (v2 - v1 >= 0)
		{
			std::cout << v1 << "" << std::endl;
			++v1;
		}
	}
	else
	{
		while (v1-v2 >= 0)
		{
			std::cout << v1 << "" << std::endl;
			--v1;
		}
	}
	system("pause");
	return 0;
}
