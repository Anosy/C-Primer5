#include<iostream>

using namespace std;

int main()
{
	int num1, num2;
	cout << "��������������" << endl;
	cin >> num1 >> num2;
	if (num2 == 0)
	{
		cout << "��������Ϊ0" << endl;
		system("pause");
		return -1;
	}
	cout << "����������Ľ����" << num1/num2 <<endl;

	system("pause");
	return 0;
}