#include<iostream>
#include<stdexcept>
using namespace std;

int main()
{
	int num1, num2;
	cout << "��������������" << endl;
	while (cin >> num1 >> num2)
	{
		try
		{
			if (num2 == 0)
			{
				throw runtime_error("��������Ϊ0��");
			}
			cout << "����������Ľ����" << num1 / num2 << endl;
		}
		catch (runtime_error err)
		{
			cout << err.what() << "\n�Ƿ���������(y or n)��" << endl;
			char c;
			cin >> c;
			if (c != 'y')
			{
				break;
			}
		}
	}

	system("pause");
	return 0;
}