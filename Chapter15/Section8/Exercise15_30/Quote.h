#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include<iostream>

class Quote
{
	friend bool operator !=(const Quote& lhs, const Quote& rhs);
public:
	Quote() {   }
	Quote(const std::string &b, double p) :
		bookNo(b), price(p) {
	}
	Quote(const Quote &q):bookNo(q.bookNo), price(q.price)
	{
	}
	Quote(Quote &&q) noexcept :bookNo(std::move(q.bookNo)), price(std::move(q.price))
	{
	}
	Quote & operator=(const Quote & q)
	{
		if (*this != q)
		{
			bookNo = q.bookNo;
			price = q.price;
		}
		return *this;
	}
	Quote operator=(Quote &&q) noexcept
	{
		if (*this != q)
		{
			bookNo = std::move(q.bookNo);
			price = std::move(q.price);
		}
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
	}
	virtual Quote * clone() const & { return new Quote(*this); }
	virtual Quote * clone() const && { return new Quote(std::move(*this)); }
	

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