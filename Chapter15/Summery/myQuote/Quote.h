#ifndef QUOTE_H
#define QUOTE_H

#include<string>
#include<iostream>

using namespace std;

class Quote
{
	friend bool operator != (const Quote &rhs, const Quote &lhs);
public:
	Quote() = default;
	Quote(const string &s, double p):bookNo(s), price(p){}
	Quote(const Quote &q)
	{
		bookNo = q.bookNo;
		price = q.price;
	}
	Quote(const Quote &&q) noexcept
	{
		bookNo = std::move(q.bookNo);
		price = std::move(q.price);
	}
	Quote & operator=(const Quote &q)
	{
		if (*this != q)
		{
			bookNo = q.bookNo;
			price = q.price;
		}
		return *this;
	}
	Quote operator=(Quote && q)
	{
		if (*this != q)
		{
			bookNo = std::move(q.bookNo);
			price = std::move(q.price);
		}
		return *this;
	}
	string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const { return n * price; }
	virtual void debug()
	{
		std::cout << "bookNo:" << bookNo << " price:" << price << std::endl;
	}
	virtual ~Quote(){ }

private:
	string bookNo;
protected:
	double price;

};

bool operator != (const Quote &rhs, const Quote &lhs)
{
	return (rhs.bookNo != lhs.bookNo) && (rhs.price != lhs.price);
}

#endif // !QUOTE_H
