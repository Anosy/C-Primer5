#include<iostream>
#include "Sales_item.h"
int main()
{
	Sales_item currVal, val;
	std::cout << "������������ۼ�¼��" << std::endl;
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
				std::cout << currVal.isbn() << "��" << cnt << "�����ۼ�¼" << std::endl;
				currVal = val;
				cnt = 1;
			}
		}
		std::cout << currVal.isbn() << "��" << cnt << "�����ۼ�¼" << std::endl;
	}
	else
	{
		std::cout << "û���������ۼ�¼��" << std::endl;
	}
	system("pause");
	return 0;
}