#include<iostream>

std::string global_str; // 初始化为空串
int global_int; // 函数外默认初始化为0
extern int local_ha = 0;

int main()
{
	/* 错误案例1
	int input_value;
	std::cout << input_value << std::endl;
	错误原因：使用了未初始化的局部变量，因为在函数内，内置类型的变量没有被显式初始化，将不会被初始化
	*/
	
	/* 错误案例2
	std::cin >> input_value; 
	错误原因：右侧需要一个明确的变量名称，而非定义变量的语句
	*/
	
	/* 错误案例3 
	int i = { 3.14 }; 
	错误原因：语句定义了一个整型的变量，使用列表初始化的方式把浮点数给赋值给i
	*/
	
	/* 错误案例4
	double salary = wage = 9.99;
	错误原因：试图将值9.99给赋值给salary和waga，但是在声明语句中声明多个变量需要用逗号隔开
	正确写法：
	double salary , waga;
	salary = waga = 9.99;
	*/
	int local_int; // 在函数内使用内置类型且未被显式初始化，将会导致该变量不被初始化，如果拷贝或者输出将会报错
	std::string local_str;  // 对于string类型的参数来说，本来就接受无参数的初始化方法
	system("pause");
	

	return 0;
}