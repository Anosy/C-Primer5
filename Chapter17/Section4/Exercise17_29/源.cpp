#include<iostream>
#include<random>

using namespace std;

unsigned random_int(unsigned sed = 0)
{
	static default_random_engine e;
	static uniform_int_distribution<unsigned>  u(0, 999);
	if (sed > 0)
	{
		e.seed(sed);
	}
	return u(e);
}

int main()
{
	for (unsigned i = 0; i != 10; ++i)
	{
		cout << random_int() << " ";
	}
	cout << endl;


	cout << random_int(1) << endl;
	for (unsigned i = 0; i != 10; ++i)
	{
		cout << random_int() << " ";
	}
	cout << endl;

	cout << random_int(2) << endl;
	for (unsigned i = 0; i != 10; ++i)
	{
		cout << random_int() << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}