#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include"Disc_quote.h"

class Bulk_quote : public Disc_quote
{
public:
	Bulk_quote() { std::cout << "Bulk_quoteĬ�Ϲ��캯��" << std::endl; }
	Bulk_quote(const std::string& b, double p, std::size_t q, double disc) :
		Disc_quote(b, p, q, disc) { std::cout << "Bulk_quote �ĸ������Ĺ��캯��" <<std::endl; }
	Bulk_quote(const Bulk_quote & bq):Disc_quote(bq)
	{
		std::cout << "Bulk_quote�������캯��" << std::endl;
	}
	Bulk_quote(Bulk_quote && bq)  noexcept :Disc_quote(std::move(bq))
	{
		std::cout << "Bulk_quote�ƶ�����" << std::endl;

	}
	Bulk_quote & operator=(const Bulk_quote& bq)
	{
		Disc_quote::operator=(bq);
		std::cout << "Bulk_quote������ֵ�����" << std::endl;
		return *this;
	}
	Bulk_quote & operator=(Bulk_quote && bq) noexcept
	{
		Disc_quote::operator=(std::move(bq));
		std::cout << "Bulk_quote�ƶ���ֵ�����" << std::endl;
		return *this;
	}

	double net_price(std::size_t n) const override;
	~Bulk_quote() override
	{
		std::cout << "Bulk_quote��������" << std::endl;
	}
};

double Bulk_quote::net_price(std::size_t n) const
{
	if (n >= quantity)
	{
		return n * (1 - discount) * price;
	}
	else
	{
		return n * price;
	}
}



#endif // BULK_QUOTE_H