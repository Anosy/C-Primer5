#include<iostream>

std::string global_str; // ��ʼ��Ϊ�մ�
int global_int; // ������Ĭ�ϳ�ʼ��Ϊ0
extern int local_ha = 0;

int main()
{
	/* ������1
	int input_value;
	std::cout << input_value << std::endl;
	����ԭ��ʹ����δ��ʼ���ľֲ���������Ϊ�ں����ڣ��������͵ı���û�б���ʽ��ʼ���������ᱻ��ʼ��
	*/
	
	/* ������2
	std::cin >> input_value; 
	����ԭ���Ҳ���Ҫһ����ȷ�ı������ƣ����Ƕ�����������
	*/
	
	/* ������3 
	int i = { 3.14 }; 
	����ԭ����䶨����һ�����͵ı�����ʹ���б��ʼ���ķ�ʽ�Ѹ���������ֵ��i
	*/
	
	/* ������4
	double salary = wage = 9.99;
	����ԭ����ͼ��ֵ9.99����ֵ��salary��waga������������������������������Ҫ�ö��Ÿ���
	��ȷд����
	double salary , waga;
	salary = waga = 9.99;
	*/
	int local_int; // �ں�����ʹ������������δ����ʽ��ʼ�������ᵼ�¸ñ���������ʼ���������������������ᱨ��
	std::string local_str;  // ����string���͵Ĳ�����˵�������ͽ����޲����ĳ�ʼ������
	system("pause");
	

	return 0;
}