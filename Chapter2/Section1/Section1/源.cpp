#include<iostream>
int main()
{
	unsigned u = 10, u1 = 42, u2 = 10;
	int i = -42;
	std::cout << i + i << std::endl; // -84
	std::cout << u + u << std::endl; // 20
	std::cout << u + i << std::endl; // 4294967264
	std::cout << u1 - u2 << std::endl; // 32
	std::cout << u2 - u1 << std::endl; // 4294967264
	for (int i = 10; i >= 0; --i) // 正常循环
	{
		std::cout << i << "\t"<<std::endl;
	}

	for (unsigned k = 10; k >=0; --k) // 异常循环
	{
		std::cout << k << std::endl;
	}

	system("pause");
	
	return 0;

}
