#include<iostream>
int main()
{
	std::cout << "��������Ҫ������������֣�(��ctrl+Z�س�����)" << std::endl;
	int sum = 0, value = 0;
	// ��ȡ����ֱ�������ļ���β���������������ֵ�ֵ�ĺ�
	while (std::cin>>value)
	{
		sum += value;
	}
	std::cout << "The sum is " << sum << std::endl;
	system("pause");
	return 0;
}