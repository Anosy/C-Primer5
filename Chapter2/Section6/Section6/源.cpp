#include<iostream>

struct Sales_data
{
	std::string bookNo; // 默认初始化为空字符串
	unsigned units_sold = 0; 
	double revenue = 0.0;
};