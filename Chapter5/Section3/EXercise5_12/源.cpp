#include<iostream>
#include<string>
#include<wchar_t>
using namespace std;

int main()
{
	unsigned int ffCnt = 0, flCnt = 0 , fiCnt = 0;
	wchar_t ch, prech = '\0';

	cout << "������һ�λ���" << endl;

	while (cin >> ch)
	{
		cout << ch << endl;
		
		bool bl = true;

		if (prech == 'f')
		{
			switch (ch)
			{
			case 'f':
				++ffCnt;
				bl = false;
				break;

			case 'l':
				++flCnt;
				break;

			case 'i':
				++fiCnt;
				break;

			default:
				break;
			}
		}
		if (!bl)
		{
			prech = '\0'; // �����λ���f��������ff����Ŀ֮���������f
		}
		else
		{
			prech = ch;
		}
	}
	cout << "ff�������ǣ�" << ffCnt << endl;
	cout << "fl�������ǣ�" << flCnt << endl;
	cout << "fi�������ǣ�" << fiCnt << endl;

	system("pause");
	return 0;
}