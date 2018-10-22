#include<string>

struct Sales_data
{

	std::string bookNo; // �鼮���
	unsigned units_sold = 0; // ������
	double revenue = 0.0; // ����
	


	std::string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data &rhs)
	{
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this; // ���غϲ���Ľ��
	}
};