#include<iostream>
#include<string>

using namespace std;

int &get(int *arry, int index) { return arry[index]; } // �������������͵ĺ��������򷵻صĲ�����ֵ

int main()
{
	int ia[10];
	for (int i = 0; i != 10; i++)
	{
		get(ia, i) = i;
	}

	for (auto c : ia)
	{
		cout << c;
	}
	cout << endl;

	system("pause");
	return 0;
}