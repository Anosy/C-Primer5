#include<iostream>
using namespace std;

int main()
{
	unsigned aCnt = 0, bCnt = 0, cCnt = 0, dCnt = 0, other = 0;
	unsigned spaceCnt = 0, tabCnt = 0, newlineCnt = 0;
	char ch;

	while (cin.get(ch))
	{
		switch (ch)
		{
		case 'a':
		case 'A':
			++aCnt;
			break;

		case 'b':
		case 'B':
			++bCnt;
			break;

		case 'c':
		case 'C':
			++cCnt;
			break;

		case 'd':
		case 'D':
			++dCnt;
			break;
		case ' ':
			++spaceCnt;
			break;
		case '\t':
			++tabCnt;
			break;
		case '\n':
			newlineCnt;
			break;
		default:
			++other;
			break;
		}
	}


	cout << "Number of a:" << aCnt << '\n' << endl;
	cout << "Number of b:" << bCnt << '\n' << endl;
	cout << "Number of c:" << cCnt << '\n' << endl;
	cout << "Number of d:" << dCnt << '\n' << endl;
	cout << "Number of space:" << spaceCnt << '\n' << endl;
	cout << "Number of tab:" << tabCnt << '\n' << endl;
	cout << "Number of newline:" << newlineCnt << '\n' << endl;


	cout << "Number of other:" << other << "\n" << endl;


	system("pause");
	return 0;
}