#include<iostream>
#include "Sales_item.h"
int main()
{
	Sales_item item1, item2;
	std::cin >> item1 >> item2;
	if (item1.isbn()==item2.isbn()) // isbn()��������item��ISBN
	{
		std::cout << item1 + item2 << std::endl; 
		system("pause");
		return 0; // ��ʾ�ɹ�
	}
	else
	{
		std::cerr << "Data must refer to same ISBN " << std::endl;
		system("pause");
		return -1; // ��ʾʧ��
	}
}
