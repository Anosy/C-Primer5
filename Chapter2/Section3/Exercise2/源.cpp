#include<iostream>

int main() 
{
	int i = 0;
	int *pi = nullptr;
	int *p = &i;
	if (pi) // ���ָ���ֵ
	{
		std::cout << "pi pass" << std::endl;
	}
	if (p) // ���ָ���ֵ
	{
		std::cout << "p pass" << std::endl;
	}
	if (*p) // ���ָ����ָ�����ֵ
	{
		std::cout << "i pass" << std::endl;
	}

	system("pause");
	return 0;
}