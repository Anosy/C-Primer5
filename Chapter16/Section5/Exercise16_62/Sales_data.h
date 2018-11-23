#include<string>
#include<iostream>
#include<vector>

template <typename T> struct std::hash;

class Sales_data
{
	// ��Ԫ����
	friend std::istream &operator>>(std::istream &, Sales_data &);
	friend std::ostream &operator<<(std::ostream &, Sales_data &);
	friend bool operator==(const Sales_data &lhs, const Sales_data &rhs);
	friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
	friend struct std::hash<Sales_data>;
public:
	// ���캯��
	Sales_data() = default;
	Sales_data(const std::string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p*n) {}
	Sales_data(const std::string &s) : Sales_data(s, 0, 0.0) {}
	// ��Ա����
	std::string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data &);
	// ���������
	Sales_data &operator+=(const Sales_data &);
	Sales_data &operator-=(const Sales_data &);
	Sales_data &operator=(const std::string &);

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

// ������ļӷ�������1
//inline
//Sales_data operator+(const Sales_data& lhs, const Sales_data&rhs) //������ֵ
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

// ������ļӷ�������2
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

// ���������
inline
Sales_data operator-(const Sales_data &lhs, const Sales_data&rhs) //������ֵ
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

// �Ⱥ������
inline
bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn() && lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue;
}

inline bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
	return !(lhs == rhs);
}

// ��ֵ�����
Sales_data & Sales_data::operator=(const std::string &s)
{
	bookNo = s;
	return *this;
}

