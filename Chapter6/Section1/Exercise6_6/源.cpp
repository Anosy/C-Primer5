#include<iostream>

using namespace std;

double myAdd(double val1, double val2)
{
	double result = val1 + val2;
	static unsigned iCnt = 0;
	++iCnt;
	cout << "�ú����ۼ�ִ����" << iCnt << "��" << endl;

	return result;
}

int main()
{
	double num1, num2;
	cout << "�������������֣�" << endl;
	while (cin >> num1 >> num2)
	{
		cout << num1 << "��" << num2 << "�ĺ�Ϊ" << myAdd(num1, num2) << endl;
	}
	system("pause");
	return 0;
}