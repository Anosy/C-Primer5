#include<string>
#include<iostream>
#include<vector>
#include<stdexcept>

template <typename T> struct std::hash;

class out_of_stock : public std::runtime_error
{
public:
	explicit out_of_stock(const std::string &s) :std::runtime_error(s) {}
};

class isbn_mismatch : public std::logic_error
{
public:
	explicit isbn_mismatch(const std::string &s) : std::logic_error(s) {}
	isbn_mismatch(const std::string &s, const std::string &lhs, const std::string &rhs) :
		std::logic_error(s), left(lhs), right(rhs) {}
	const std::string left, right;
};

class Sales_data
{
	// ��Ԫ����
	friend std::istream &operator>>(std::istream &, Sales_data &);
	friend std::ostream &operator<<(std::ostream &, const Sales_data &);
	friend bool operator==(const Sales_data &lhs, const Sales_data &rhs);
	friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
	friend struct std::hash<Sales_data>;
	friend std::istream & read(std::istream &, Sales_data &);
public:
	// ���캯��
	Sales_data() = default;
	Sales_data(const std::string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p*n) {}
	Sales_data(const std::string &s) : bookNo(s), units_sold(0), revenue(0.0) {}
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
std::istream & read(std::istream & is, Sales_data & s)
{

	double price;
	is >> s.bookNo >> s.units_sold >> price;
	if (is)
	{
		s.revenue = s.units_sold * price;
	}
	else
	{
		s = Sales_data();
	}
	return is;
}
// ���⺯��
Sales_data add(const Sales_data &lhs, const Sales_data&rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

std::ostream &operator<<(std::ostream &os, const Sales_data &rhs)
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

// ������ļӷ�������2
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum;
	sum.units_sold = lhs.units_sold + rhs.units_sold;
	sum.revenue = lhs.revenue + rhs.revenue;
	return sum;
}

//Sales_data &Sales_data::operator+=(const Sales_data &rhs)
//{
//	*this = (*this) + rhs;
//	return *this;
//}

Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
	if (isbn() !=  rhs.isbn())
	{
		throw isbn_mismatch("wrong isbns", isbn(), rhs.isbn());
	}
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
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

//Sales_data &Sales_data::operator-=(const Sales_data &item)
//{
//	units_sold -= item.units_sold;
//	revenue -= item.revenue;
//	return *this;
//}

Sales_data &Sales_data::operator-=(const Sales_data &item)
{
	if (isbn() != item.isbn())
	{
		throw isbn_mismatch("wrong isbns", isbn(), item.isbn());
	}
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

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}


