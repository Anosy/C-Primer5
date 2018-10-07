#include<iostream>
int main()
{
	std::cout << "2\115\n" << std::endl; // 先输出2M然后转到下一行
	std::cout << "2\t\115\n" << std::endl; // 先输出2然后输出制表符然后输出M最后转到下一行
	system("pause");
	return 0;
}