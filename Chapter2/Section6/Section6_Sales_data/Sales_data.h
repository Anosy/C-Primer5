#ifndef SALE_DATA_H
#define SALE_DATA_H
#include<iostream>
#include <string>
struct Sales_data
{
	std::string bookNo; // 默认初始化为空字符串
	unsigned units_sold = 0;
	double revenue = 0.0;
};
#endif // !SALE_DATA_H
