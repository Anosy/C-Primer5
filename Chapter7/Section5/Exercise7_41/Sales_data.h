#include<iostream>
#include<string>

class Sales_data
{
	friend std::istream &read(std::istream &is, Sales_data &item);
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
public:
	Sales_data(const std::string &s, unsigned u, double r) :bookNo(s), units_sold(u), revenue(r) { std::cout << "调用1" << std::endl; }
	Sales_data(const std::string &s) : Sales_data(s, 0, 0.0) { std::cout << "调用2" << std::endl; }
	Sales_data() : Sales_data("", 0, 0.0){ std::cout << "调用3" << std::endl; };
	Sales_data(std::istream &is) :Sales_data() 
	{
		read(is, *this);
		std::cout << "调用4" << std::endl;
	}
};

std::istream &read(std::istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}