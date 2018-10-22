#include"Screen.h"
using namespace std;

int main()
{
	Screen myScreen1(10, 5);
	Screen myScreen2(10, 5, '@');
	myScreen1.move(2, 1).set(' ').display(cout);
	cout << endl;
	myScreen2.set(2, 1, ' ').display(cout);
	cout << endl;

	system("pause");
	return 0;
}