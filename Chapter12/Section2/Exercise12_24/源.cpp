#include<iostream>
#include<string>
#include<memory>

using namespace std;

int main()
{
	char c;

	char *r = new char[20];
	int l = 0;

	while (cin.get(c))
	{
		if (isspace(c))
		{
			break;
		}
		r[l++] = c;
		if (l == 20)
		{
			cout << "�ﵽ������������" << endl;
			break;
		}
	}
	r[l] = 0;
	cout << r << endl;

	delete[] r;

	system("pause");
	return 0;
}