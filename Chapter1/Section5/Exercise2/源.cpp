#include<iostream>
#include "Sales_item.h"
int main()
{
	Sales_item item1, item2;
	std::cout << "����������ISBN��ͬ�����ۼ�¼:" << std::endl;
	std::cin >> item1 >> item2;
	if (compareIsbn(item1, item2))
	{
		std::cout << " ������Ϣ��ISBN�� �۳��ı��������۶ƽ�����ۼ۸� " 
			<< "\n" << item1 + item2 << std::endl;
	}
	else
	{
		std::cout << "���������ISBN����ͬ��" << std::endl;
	}
	system("pause");
	return 0;
}