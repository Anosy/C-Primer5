#include<iostream>
int main()
{
	int i = 5, j=10;
	int *p = &i;
	std::cout << p << "   " << *p << std::endl;

	// 改变指针的值
	p = &j;
	std::cout << p << "   " << *p << std::endl;

	// 通过指针来改变指针所指对象的值
	*p = 20;
	std::cout << p << "   " << *p << std::endl;

	// 通过直接改变指针所指对象的值
	j = 30;
	std::cout << p << "   " << *p << std::endl;


	system("pause");
	return 0;
}