#include<iostream>
int main()
{
	// currVal是我们正在统计是数，val是我们刚刚读入的数
	int currVal = 0, val = 0;
	std::cout << "请输入需要计数的数字: " << std::endl;
	// 读取第一个数，并且确保有数字可以处理
	if (std::cin >> currVal)
	{
		int cnt = 1;
		while (std::cin >> val)
		{
			if (currVal == val)   // 如果数字相同，那么计数器+1
			{
				cnt++;
			}
			else  // 否则，打印前一个数字
			{
				std::cout << currVal << " occurs " << cnt << " times " << std::endl;
				currVal = val;   // 记住新的数
				cnt = 1;	// 重置计数器
			}
		}
		// 打印最后输入的数
		std::cout << currVal << " occurs " << cnt << " times " << std::endl;

	}	
	system("pause");
	return 0;
}