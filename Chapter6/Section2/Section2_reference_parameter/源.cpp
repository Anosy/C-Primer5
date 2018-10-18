#include<iostream>

using namespace std;

void reset(int &r)
{
	r = 0;
}

int main()
{
	int i = 4;
	reset(i);

	cout << "i=" << i << endl;
	system("pause");
	return 0;
}