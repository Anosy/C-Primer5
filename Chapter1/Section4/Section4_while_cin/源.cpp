#include<iostream>
int main()
{
	std::cout << "请输入需要求和是所有数字：(按ctrl+Z回车结束)" << std::endl;
	int sum = 0, value = 0;
	// 读取数据直到遇到文件的尾部，计算所有数字的值的和
	while (std::cin>>value)
	{
		sum += value;
	}
	std::cout << "The sum is " << sum << std::endl;
	system("pause");
	return 0;
}