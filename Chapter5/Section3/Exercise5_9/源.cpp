#include<iostream>

using namespace std;

int main()
{
	unsigned aCnt = 0, bCnt = 0, cCnt = 0, dCnt = 0, other = 0;
	char ch;

	while (cin >> ch)
	{
		if (ch == 'a')
		{
			++aCnt;
		}
		else if(ch == 'b')
		{
			++bCnt;
		}
		else if (ch == 'c')
		{
			++cCnt;
		}
		else if (ch == 'd')
		{
			++dCnt;
		}
		else
		{
			++other;
		}
	}

	cout << "Number of a:" << aCnt << '\n' << endl;
	cout << "Number of b:" << bCnt << '\n' << endl;
	cout << "Number of c:" << cCnt << '\n' << endl;
	cout << "Number of d:" << dCnt << '\n' << endl;
	cout << "Number of other:" << other << "\n" << endl;


	system("pause");
	return 0;
}