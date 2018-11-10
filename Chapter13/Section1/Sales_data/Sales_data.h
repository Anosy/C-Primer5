#include<string>
#include<iostream>

class Sales_data 
{
public:
	Sales_data() = default;
	// 拷贝构造函数
	Sales_data(const Sales_data &);
	// 拷贝赋值运算符
	Sales_data & operator=(const Sales_data &);
	// 析构函数
	~Sales_data(){}
private:
	std::string bookNo;
	int units_sold = 0;
	double revenue = 0.0;
};
Sales_data::Sales_data(const Sales_data & orig) :
	bookNo(orig.bookNo), units_sold(orig.units_sold), revenue(orig.revenue) {}

Sales_data & Sales_data::operator=(const Sales_data & orig)
{
	bookNo = orig.bookNo;
	units_sold = orig.units_sold;
	revenue = orig.revenue;
	return *this;0
}