#include"HasPtr.h"

using namespace std;

int main()
{
	HasPtr h("hi bob!");
	HasPtr h2(h); 
	h2 = "hi mike";
	
	cout << "h:" << *h << endl;
	cout << "h2:" << *h2 << endl;
	
	swap(h, h2);

	cout << "h:" << *h << endl;
	cout << "h2:" << *h2 << endl;



	system("pause");
	return 0;
}