#ifndef DISCQUOTE_H
#define DISCQUOTE_H

#include<string>
#include"Quote.h"

class Disc_quote :public Quote
{
public:
	Disc_quote() = default;
	Disc_quote(const std::string &s, double p, std::size_t q, double d) :
		Quote(s, p), quantity(q), discount(d) {}
	double net_price(std::size_t n) const = 0;

protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};

#endif // !DISCQUOTE_H
