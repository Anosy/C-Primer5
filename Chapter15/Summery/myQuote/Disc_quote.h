#ifndef DISCQUOTE_H
#define DISCQUOTE_H

#include"Quote.h"

class Disc_quote :public Quote
{
public:
	Disc_quote() = default;
	Disc_quote(const string &s, double price, size_t n, double p) :
		Quote(s, price), quantity(n), discount(p) {}
	double net_price(size_t n) const = 0;


protected:
	size_t quantity = 0;
	double discount = 0.0;
};

#endif // !DISCQUOTE_H
