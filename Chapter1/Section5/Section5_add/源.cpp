#include<iostream>
#include "Sales_item.h"
int main()
{
	// 定义了item1, item2两个对象
	Sales_item item1, item2;
	std::cin >> item1 >> item2;
	std::cout << item1 + item2 << std::endl;
	system("pause");
	return 0;
}