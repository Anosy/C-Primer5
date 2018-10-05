#include<iostream>
#include "Sales_item.h"
int main()
{
	Sales_item total, trans;
	std::cout << "请输入几条ISBN相同的销售记录：" << std::endl;
	if (std::cin >> total)
	{
		while (std::cin >> trans)
		{
			if (compareIsbn(total, trans))
			{
				total += trans;
			}
			else
			{
				std::cout << "当前输入的ISBN不相同" << std::endl;
				system("pause");
				return -1;
			}
		}
		std::cout << " 汇总信息：ISBN、 售出的本数、销售额、平均销售价格: " << total << std::endl;
	}
	else
	{
		std::cout << "没有数据输入！" << std::endl;
		system("pause");
		return -1;
	}
	system("pause");
	return 0;
}