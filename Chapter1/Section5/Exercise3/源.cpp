#include<iostream>
#include "Sales_item.h"
int main()
{
	Sales_item total, trans;
	std::cout << "�����뼸��ISBN��ͬ�����ۼ�¼��" << std::endl;
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
				std::cout << "��ǰ�����ISBN����ͬ" << std::endl;
				system("pause");
				return -1;
			}
		}
		std::cout << " ������Ϣ��ISBN�� �۳��ı��������۶ƽ�����ۼ۸�: " << total << std::endl;
	}
	else
	{
		std::cout << "û���������룡" << std::endl;
		system("pause");
		return -1;
	}
	system("pause");
	return 0;
}