#include<string>
#include<iostream>
#include<fstream>
#include<vector>

class Sales_data
{
	// 友元声明
	friend std::ifstream &read(std::ifstream& is, Sales_data& item);
	friend std::ostream &print(std::ostream& os, Sales_data& item);
public:
	// 构造函数
	Sales_data() = default;
	Sales_data(const std::string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p*n) {}
	Sales_data(const std::string &s) : Sales_data(s, 0, 0.0) {}
	Sales_data(std::ifstream& is) { read(is, *this); }
	// 成员函数
	std::string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data &);

private:
	// 数据成员
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

	double avg_price() const
	{
		return units_sold ? revenue / units_sold : 0;
	}
};
// 类外定义成员函数
Sales_data & Sales_data::combine(const Sales_data &trans)
{
	units_sold += trans.units_sold;
	revenue += trans.revenue;
	return *this;
}
// 类外函数
Sales_data add(const Sales_data &lhs, const Sales_data&rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}
std::ifstream &read(std::ifstream &is, Sales_data& item)
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