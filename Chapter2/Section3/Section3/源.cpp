#include<iostream>
// ����������Ҫ�Ƕ����õĽ���
using namespace std;
int main()
{
	int ival = 1024;
	int &refVal = ival; //  refValָ����ival����ival����ȡ������һ�����֣�
	// ������� int &refVal2; ��Ϊ���ñ��뱻��ʼ��
	refVal = 2; // ��2��ֵ��reValָ��Ķ��󣬴˴���ֵ����ֵ����ival
	int ii = refVal; // ��ival��ֵ����ֵ��reaVal,�ȼ���ii = ival;
	
	int &refVal3 = refVal; // ��refVal3Ҳ���󶨵�ival��
	
	int i = refVal; // ��ival��ֵ������ʼ��i

	// ������� int &refVal4 = 10; ��Ϊ���ñ���ָ��һ��ʵ�ʴ��ڵĶ��󣬶�������ֵ����
	// ������� double dval = 3.14; int &refVal5 = dval; ��Ϊ���õ�����Ҫ�Ͱ󶨶����ϸ��ƥ��

	int a, &ra = a;
	a = 5, ra = 10;
	cout << a << ra << endl; // �õ��Ľ��Ϊ10 10

	system("pause");
	return	0;
}
