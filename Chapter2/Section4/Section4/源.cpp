#include<iostream>
int main()
{
	const int bufSize = 512; // ���뻺�����Ĵ�С
	// bufSize=120; ������ͼ��ocnst����д��ֵ


	// ��ʼ��
	const int i = 42; // ��ȷ
	// const int k; ����const��������ʼ��
	const int ci = i; // ��ȷ��i��ֵ����������ci
	int j = ci; // ��ȷ:ci��ֵ����������j

	
	// const������
	const int ct = 1024;
	const int &r1 = ct; // ��ȷ�������Լ����Ӧ�Ķ����ǳ���
	// r1 = 42; ����r1�ǶԳ���������,��˲��ܹ�ͨ���������ı䳣����ֵ
	// int &r2 = ci;  ������ͼ��һ���ǳ�������ָ��һ������������Ϊ���r2���ǳ���������ô����ֵ���Ա���ֵ��ô����Ӱ��ci����ֵ�ı仯
	int t = 42;
	const int &r2 = t; // ����const int &�󶨵�һ����ͨ��int ������
	const int &r3 = 42; // ��ȷ, ��������������������ǳ������õĻ�����ô���õĳ�ʼֵ������һ������
	const int &r4 = r2 * 2; // ��ȷ
	// int &r5 = r2 * 2; ������Ϊr2�ǳ������ã��Ӷ�r5����Ҳ���ǳ�������

	double dval = 3.14;
	const int &ri = dval; // ��ȷ�����ǳ������õ�����һ����������������õ����Ϳ��Ժ��䱻���ö�������Ͳ���ͬ����Ϊ�䴴����һ��temp��ʱ����

	// ��const�����ÿ�������һ����const�Ķ���
	int k = 42;
	int &ki = k;
	const int &k2 = k; // k2Ҳ�󶨶���i�����ǲ�����ͨ��r2�޸�i��ֵ
	ki = 0;
	// k2 = 0; ���� k2Ϊ�������ã�����䲻���޸�k��ֵ


	//ָ���const(Ū�������ĺ�������Ч�ķ������Ǵ��������)
	int errNumb = 0;
	int *const curErr = &errNumb; // ��curErr��һֱָ��errNumb
	const double pi = 3.1415926;
	const double *const pip = &pi; // pip��һ��ָ��������ĳ���ָ��\]��pip��һ������ָ�룬ָ�����˫���ȸ����͵ĳ�����

	// *pip = 2.71; ����pip��ָ������ָ�룬��˲��ܸı���ָ������ֵ
	*curErr = 10;
	std::cout << errNumb << std::endl;


	system("pause");
	return 0;
}