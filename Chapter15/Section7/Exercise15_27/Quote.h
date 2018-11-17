#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include<iostream>

class Quote
{
	friend bool operator !=(const Quote& lhs, const Quote& rhs);
public:
	Quote() { std::cout << "Quote默认构造函数" << std::endl; }
	Quote(const std::string &b, double p) :
		bookNo(b), price(p) {
		std::cout << "Quote带两个参数的构造函数" << std::endl;
	}
	Quote(const Quote &q) :bookNo(q.bookNo), price(q.price)
	{
		std::cout << "Quote拷贝构造函数" << std::endl;
	}
	Quote(Quote &&q) noexcept :bookNo(std::move(q.bookNo)), price(std::move(q.price))
	{
		std::cout << "Quote移动构造函数" << std::endl;
	}
	Quote & operator=(const Quote & q)
	{
		if (*this != q)
		{
			bookNo = q.bookNo;
			price = q.price;
		}
		std::cout << "Quote拷贝赋值运算符" << std::endl;
		return *this;
	}
	Quote operator=(Quote &&q) noexcept
	{
		if (*this != q)
		{
			bookNo = std::move(q.bookNo);
			price = std::move(q.price);
		}
		std::cout << "Quote移动赋值运算符" << std::endl;
		return *this;
	}

	std::string isbn() const { return bookNo; }
	virtual double  net_price(std::size_t n) const { return n * price; }
	virtual void  debug()
	{
		std::cout << "bookNo:" << bookNo << " price:" << price << std::endl;
	}
	virtual ~Quote()
	{
		std::cout << "Quote析构函数" << std::endl;
	}

private:
	std::string bookNo;

protected:
	double  price = 0.0;

};

bool inline
operator !=(const Quote& lhs, const Quote& rhs)
{
	return lhs.bookNo != rhs.bookNo && lhs.price != rhs.price;
}




#endif // QUOTE_H