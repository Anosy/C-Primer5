#include"HasPtr.h"

int main()
{
	HasPtr h("hi bob!");
	HasPtr h2(h);
	HasPtr h3 = h;
	HasPtr h4;

	h2 = "hi mike";
	h3 = "hi jack";
	h4 = h;

	cout << "h:" << *h << endl;
	cout << "h2:" << *h2 << endl;
	cout << "h3:" << *h3 << endl;
	cout << "h4:" << *h4 << endl;

	system("pause");
	return 0;
}