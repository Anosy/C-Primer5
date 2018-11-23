#include<iostream>
#include"Screen.h"
#include<string>

using namespace std;


int main()
{
	Screen<5, 3> myscreen('#');
	myscreen.display(cout);
	cout << endl;

	Screen<4, 5> nextscreen('X');
	nextscreen.move(1, 0).set('Y').display(cout);
	cout << endl;

	nextscreen.clear();
	nextscreen.display(cout);
	cout << endl;

	system("pause");
	return 0;
}