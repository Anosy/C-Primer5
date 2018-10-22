#include<string>

class Sales_data
{
	std::string bookNo; // �鼮���
	unsigned units_sold = 0; // ������
	double sellingprice = 0.0; // ԭʼ�۸�
	double saleprice = 0.0; // ʵ�ۼ۸�
	double discount = 0.0; // �ۿ�

	std::string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data &rhs)
	{
		units_sold += rhs.units_sold;
		saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold) / (rhs.units_sold + units_sold); // ���¼���ʵ�ʵ����ۼ۸�
		if (sellingprice !=0)
		{
			discount = saleprice / sellingprice; // ���¼����ۿ�
		}
		return *this; // ���غϲ���Ľ��
	}
};