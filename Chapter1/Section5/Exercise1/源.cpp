#include<iostream>
#include "Sales_item.h"
int main()
{
	Sales_item item;
	std::cout << "请输入书本的ISBN号、销售的册数、销售的价格" << std::endl;
	while (std::cin>>item)
	{
		std::cout << item << std::endl;
	}
	system("pause");
	return 0;
}
