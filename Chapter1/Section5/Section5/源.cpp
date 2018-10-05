#include<iostream>
#include "Sales_item.h"
int main()
{
	Sales_item book;
	// 读入ISBN号、售出的册数以及销售的价格
	std::cin >> book;
	// 写入ISBN、售出的册数、总的销售额度和平均的价格
	std::cout << book << std::endl;
	system("pause");
	return 0;
}