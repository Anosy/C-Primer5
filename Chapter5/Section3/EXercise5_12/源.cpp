#include<iostream>
#include<string>
#include<wchar_t>
using namespace std;

int main()
{
	unsigned int ffCnt = 0, flCnt = 0 , fiCnt = 0;
	wchar_t ch, prech = '\0';

	cout << "请输入一段话：" << endl;

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
			prech = '\0'; // 如果这次还是f，计算完ff的数目之后，跳过这个f
		}
		else
		{
			prech = ch;
		}
	}
	cout << "ff的数量是：" << ffCnt << endl;
	cout << "fl的数量是：" << flCnt << endl;
	cout << "fi的数量是：" << fiCnt << endl;

	system("pause");
	return 0;
}