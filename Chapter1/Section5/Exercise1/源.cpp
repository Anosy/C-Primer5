#include<iostream>
#include "Sales_item.h"
int main()
{
	Sales_item item;
	std::cout << "�������鱾��ISBN�š����۵Ĳ��������۵ļ۸�" << std::endl;
	while (std::cin>>item)
	{
		std::cout << item << std::endl;
	}
	system("pause");
	return 0;
}
