#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	cout << scientific << setw(20) << sqrt(2.0) << endl;
	cout << fixed << setw(20) << sqrt(2.0) << endl;
	cout << hexfloat << setw(20) << sqrt(2.0) << endl;
	cout << defaultfloat << setw(20) << sqrt(2.0) << endl;

	system("pause");
	return 0;
}