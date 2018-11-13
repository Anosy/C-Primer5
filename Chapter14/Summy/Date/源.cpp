#include"Date.h"

using namespace std;

int main()
{
	Date d1(1999, 10, 10);

	cout << d1 << endl;

	Date d2;
	cin >> d2;
	cout << d2 << endl;
	cout << "d1 < d2:" << ((d1 < d2) ? "Yes" : "No") << endl;

	Date d3;
	d3 = "1999 2 21";
	cout << d3 << endl;

	system("pause");
	return 0;
}