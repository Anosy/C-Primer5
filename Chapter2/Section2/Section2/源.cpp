#include<iostream>
// �ó��������˵���������ڲ����˶�����ȫ�ֱ���ͬ�����±���
int reused = 42; // reusedӵ��ȫ������
int main()
{
	int unique = 0; // uniqueӵ�п�������
	// ���#1��ʹ��ȫ�ֱ���reused;
	std::cout << reused << " " << unique << std::endl;
	int reused = 0;// �½��ֲ�����reused��������ȫ�ֱ���reused
	// ���#2��ʹ�þֲ�����reused��
	std::cout << reused << " " << unique << std::endl;;
	// ���#3����ʽ�ط���ȫ�ֱ���reused��
	std::cout << ::reused << " " << unique << std::endl;
	system("pause");
	return 0;
}