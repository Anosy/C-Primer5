#include<iostream>
int main()
{
	int sum = 0, val = 1;
	// ֻҪval��ֵС�ڵ���10��whileѭ���ͻ������ִ��
	while(val<=10)
	{
		sum += val; // ��sum+val��ֵ������sum
		++val; // ��val��1
	}
	std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
	system("pause");
	return 0;
}