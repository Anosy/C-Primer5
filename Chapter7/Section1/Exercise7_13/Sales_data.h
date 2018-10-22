#include<iostream>
#include<string>

struct Sales_data
{
	// 4�ֹ��캯��
	Sales_data() = default;
	Sales_data(const std::string &book) :bookNo(book) {};
	Sales_data(const std::string &book, unsigned num, double rev);
	Sales_data(std::istream &is);

	// ��ʼ��
	std::string bookNo; // �鼮���
	unsigned units_sold = 0; // ������
	double revenue = 0.0; // ����

	// ��Ա����
	std::string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data &rhs)
	{
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this; // ���غϲ���Ľ��
	}
	double avg_price() const;
};

// ���ⲿ����ĳ�Ա����
double Sales_data::avg_price() const
{
	if (units_sold)
	{
		return revenue / units_sold;
	}
	else
	{
		return 0;
	}
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

std::istream &read(std::istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}


// ���ⲿ���幹�캯��
Sales_data::Sales_data(const std::string &book, unsigned num, double rev)
{
	bookNo = book;
	units_sold = num;
	revenue = rev;
}

Sales_data::Sales_data(std::istream &is)
{
	read(is, *this);
}