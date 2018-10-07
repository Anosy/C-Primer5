#include<iostream>

int main() 
{
	int i = 0;
	int *pi = nullptr;
	int *p = &i;
	if (pi) // 检查指针的值
	{
		std::cout << "pi pass" << std::endl;
	}
	if (p) // 检查指针的值
	{
		std::cout << "p pass" << std::endl;
	}
	if (*p) // 检查指针所指对象的值
	{
		std::cout << "i pass" << std::endl;
	}

	system("pause");
	return 0;
}