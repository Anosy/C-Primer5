#include<iostream>
#include "Sales_item.h"
int main()
{
	Sales_item item1, item2;
	std::cout << "请输入两条ISBN相同的销售记录:" << std::endl;
	std::cin >> item1 >> item2;
	if (compareIsbn(item1, item2))
	{
		std::cout << " 汇总信息：ISBN、 售出的本数、销售额、平均销售价格 " 
			<< "\n" << item1 + item2 << std::endl;
	}
	else
	{
		std::cout << "输入的两条ISBN不相同！" << std::endl;
	}
	system("pause");
	return 0;
}