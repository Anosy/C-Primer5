#include<iostream>
#include<string>
using namespace std;

int main()
{
	int arr[10]; // ����10������������
	
	constexpr unsigned sz = 42;
	int *parr[sz]; // ����42������ָ�������

	int ia1[3] = { 0 ,1, 2 };  // ��������Ԫ�ص����飬 Ԫ�طֱ���0,1,2

	int ia2[] = { 1, 2, 3 }; // ��������Ԫ�ص����飬Ԫ�طֱ���1��2��3

	string a4[3] = { "hi", "bye" }; // ��������Ԫ�ص����飬Ԫ�طֱ���hi , bye�� ''

	char a1[] = { 'C', '+', '+' }; // ��������Ԫ�ص����飬Ԫ�طֱ���C, +, +

	char a2[] = "C++"; // �����ĸ�Ԫ�ص����飬Ԫ�طֱ���C, +, +, ''

	int *ptr[10]; // ptr�Ǻ���10��Ԫ�ص�����ָ������

	int(*Parray)[10] = &arr; // Parray��ָ����10������Ԫ�ص�����

}