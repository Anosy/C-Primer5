#include<iostream>

using namespace std;

int main()
{
	int arr[3][4];
	size_t cnt = 0;
	for (auto &a : arr)
	{
		for (auto &b : a)
		{
			b = cnt;
			++cnt;
		}
	}

	// ��һ�ַ���
	cout << "��һ�ַ����������" << endl;
	for (int(&a)[4] : arr)
	{
		for (int b : a)
		{
			cout << b << " ";
		}
		cout << endl;
	}

	cout << "��һ�ַ���ʹ��auto�������" << endl;
	for (auto &a : arr) 
	{
		for (auto &b : a)
		{
			cout << b << " ";
		}
		cout << endl;
	}


	// �ڶ��ַ���
	cout << "�ڶ��ַ����������" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	//�����з���
	cout << "�����ַ����������" << endl;
	for (int(*p)[4] = arr; p != arr + 3; p++)
	{
		for (int *q = *p; q != *p + 4; q++)
		{
			cout << *q << " ";
		}
		cout << endl;
	}

	cout << "�����ַ���ʹ��auto�������" << endl;
	for (auto p = arr; p != arr + 3; p++)
	{
		for (auto q = *p; q != *p + 4; q++)
		{
			cout << *q << " ";
		}
		cout << endl;
	}



		system("pause");
	return 0;
}