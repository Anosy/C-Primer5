// ָ���β�
#include<iostream>

using namespace std;

// ����һ��ָ�룬Ȼ����ָ����ָ��λ�õ�ֵ��0
void reset(int *ip)
{
	*ip = 0; // �ı�ָ����ָ�����ֵ
	ip = 0; // ֵ�ı�ip�ľֲ�������ʵ��û�иı�
}

int main()
{
	int i = 42;
	int *p = &i;
	reset(p);
	cout << "i = " << i << endl;

	system("pause");
	return 0;
}