#include<iostream>

using namespace std;

int compare(const int v1, const int *v2)
{
	if (v1 > *v2)
	{
		return v1;
	}
	else 
	{
		return *v2;
	}
}

int main()
{
	int v1, v2;
	cout << "����������������" << endl;
	cin >> v1 >> v2;
	int result = compare(v1, &v2);
	cout << "������������Ϊ��" << result << endl;

	system("pause");
	return 0;
}