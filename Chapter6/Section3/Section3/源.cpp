#include<iostream>

using namespace std;

// ��v1��v2��ֵ
void swap(int &v1, int &v2)
{
	if (v1 == v2)
	{
		return;
	}
	int temp = v2;
	v2 = v1;
	v1 = temp;
}

int main()
{
	int v1, v2;
	cout << "����������ֵ��" << endl;
	cin >> v1 >> v2;
	cout << "v1=" << v1 << "   v2=" << v2 << endl;
	swap(v1, v2);
	cout << "v1=" << v1 << "   v2=" << v2 << endl;

	system("pause");
	return 0;
}