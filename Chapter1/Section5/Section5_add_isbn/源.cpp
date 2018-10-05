#include<iostream>
#include "Sales_item.h"
int main()
{
	Sales_item item1, item2;
	std::cin >> item1 >> item2;
	if (item1.isbn()==item2.isbn()) // isbn()函数返回item的ISBN
	{
		std::cout << item1 + item2 << std::endl; 
		system("pause");
		return 0; // 表示成功
	}
	else
	{
		std::cerr << "Data must refer to same ISBN " << std::endl;
		system("pause");
		return -1; // 表示失败
	}
}
