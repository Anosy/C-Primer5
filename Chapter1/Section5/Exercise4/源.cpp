#include<iostream>
#include "Sales_item.h"
int main()
{
	Sales_item currVal, val;
	std::cout << "请输入多条销售记录：" << std::endl;
	if (std::cin >> currVal)
	{
		int cnt = 1;
		while (std::cin >> val)
		{
			if (currVal.isbn() == val.isbn())
			{
				cnt++;
			}
			else
			{
				std::cout << currVal.isbn() << "有" << cnt << "条销售记录" << std::endl;
				currVal = val;
				cnt = 1;
			}
		}
		std::cout << currVal.isbn() << "有" << cnt << "条销售记录" << std::endl;
	}
	else
	{
		std::cout << "没有输入销售记录！" << std::endl;
	}
	system("pause");
	return 0;
}