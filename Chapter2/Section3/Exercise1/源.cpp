#include<iostream>
int main()
{
	int i = 5, j=10;
	int *p = &i;
	std::cout << p << "   " << *p << std::endl;

	// �ı�ָ���ֵ
	p = &j;
	std::cout << p << "   " << *p << std::endl;

	// ͨ��ָ�����ı�ָ����ָ�����ֵ
	*p = 20;
	std::cout << p << "   " << *p << std::endl;

	// ͨ��ֱ�Ӹı�ָ����ָ�����ֵ
	j = 30;
	std::cout << p << "   " << *p << std::endl;


	system("pause");
	return 0;
}