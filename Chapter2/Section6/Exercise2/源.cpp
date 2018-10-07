#include<iostream>
struct Sales_data
{
	std::string	bookNo; // 书本编号
	unsigned units_sold = 0.0; // 销售量
	double sellingprice = 0.0; // 零售价
	double saleprice = 0.0; // 实售价
	double discount = 0.0; //折扣
};