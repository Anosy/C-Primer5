#include<string>
#include<iostream>
#include<vector>

class Sales_data
{
	// ��Ԫ����
	friend std::istream &read(std::istream& is, Sales_data& item);
	friend std::ostream &print(std::ostream& os, Sales_data& item);
public:
	// ���캯��
	Sales_data() = default;
	Sales_data(const std::string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p*n) {}
	Sales_data(const std::string &s) : Sales_data(s, 0, 0.0) {}
	Sales_data(std::istream&is) { read(is, *this); }
	// ��Ա����
	std::string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data &);

private:
	// ���ݳ�Ա
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

	double avg_price() const
	{
		return units_sold ? revenue / units_sold : 0;
	}
};
// ���ⶨ���Ա����
Sales_data & Sales_data::combine(const Sales_data &trans)
{
	units_sold += trans.units_sold;
	revenue += trans.revenue;
	return *this;
}
// ���⺯��
Sales_data add(const Sales_data &lhs, const Sales_data&rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}
std::istream &read(std::istream& is, Sales_data& item)
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}
std::ostream &print(std::ostream& os, Sales_data& item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}