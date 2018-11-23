#include<string>
#include<iostream>
#include<vector>

template <typename T> struct std::hash;

class Sales_data
{
	// 友元声明
	friend std::istream &operator>>(std::istream &, Sales_data &);
	friend std::ostream &operator<<(std::ostream &, Sales_data &);
	friend bool operator==(const Sales_data &lhs, const Sales_data &rhs);
	friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
	friend struct std::hash<Sales_data>;
public:
	// 构造函数
	Sales_data() = default;
	Sales_data(const std::string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p*n) {}
	Sales_data(const std::string &s) : Sales_data(s, 0, 0.0) {}
	// 成员函数
	std::string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data &);
	// 重载运算符
	Sales_data &operator+=(const Sales_data &);
	Sales_data &operator-=(const Sales_data &);
	Sales_data &operator=(const std::string &);

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

std::ostream &operator<<(std::ostream &os, Sales_data &rhs)
{
	os << rhs.isbn() << " " << rhs.units_sold << " "
		<< rhs.revenue << " " << rhs.avg_price();
	return os;
}

std::istream &operator>>(std::istream &is, Sales_data &rhs)
{
	double price;
	is >> rhs.bookNo >> rhs.units_sold >> price;
	if (is)
	{
		rhs.revenue = rhs.units_sold * price;
	}
	else
	{
		rhs = Sales_data();
	}
	return is;
}

// 定义类的加法，方法1
//inline
//Sales_data operator+(const Sales_data& lhs, const Sales_data&rhs) //返回右值
//{
//	Sales_data sum = lhs;
//	sum += rhs;
//	return sum;
//}
//
//
//Sales_data & Sales_data::operator+=(const Sales_data &item)
//{
//	units_sold += item.units_sold;
//	revenue += item.revenue;
//	return *this;
//}

// 定义类的加法，方法2
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum;
	sum.units_sold = lhs.units_sold + rhs.units_sold;
	sum.revenue = lhs.revenue + rhs.revenue;
	return sum;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
	*this = (*this) + rhs;
	return *this;
}

// 减法运算符
inline
Sales_data operator-(const Sales_data &lhs, const Sales_data&rhs) //返回右值
{
	Sales_data sub = lhs;
	sub += rhs;
	return sub;
}

Sales_data &Sales_data::operator-=(const Sales_data &item)
{
	units_sold -= item.units_sold;
	revenue -= item.revenue;
	return *this;
}

// 等号运算符
inline
bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn() && lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue;
}

inline bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
	return !(lhs == rhs);
}

// 赋值运算符
Sales_data & Sales_data::operator=(const std::string &s)
{
	bookNo = s;
	return *this;
}

