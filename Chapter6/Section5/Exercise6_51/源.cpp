#include<iostream>

using namespace std;

void f()
{
	cout << "�ú����������" << endl;
}

void f(int)
{
	cout << "�ú�����Ҫһ��int����" << endl;
}

void f(int, int)
{
	cout << "�ú�����Ҫ����int����" << endl;
}

void f(double a, double b = 3.14)
{
	cout << "�ú�����Ҫ����double����" << endl;
}

int main()
{
	// f(2.56, 46);  // �����ƥ��
	f(42);
	f(42, 0);
	f(2.56, 3.14);

	system("pause");
	return 0;
}
