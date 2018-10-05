#include<iostream>
int main()
{
	std::cout << "请输入两个数字：";
	std::cout << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << v1;
	std::cout << "和";
	std::cout << v2;
	std::cout << "的积为";
	std::cout << v1 * v2;
	std::cout << "\n";
	system("pause");
	return 0;
}