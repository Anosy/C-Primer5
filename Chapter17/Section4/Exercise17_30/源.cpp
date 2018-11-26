#include<iostream>
#include<random>

using namespace std;

unsigned random_int(unsigned min = 1, unsigned max = 0, unsigned sed = 0)
{
	static default_random_engine e;
	static uniform_int_distribution<unsigned>  u(0, 999);
	if (sed > 0)
	{
		e.seed(sed);
	}

	if (min < max)
	{
		u = uniform_int_distribution<unsigned>(min, max);
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

	cout << random_int(11, 20, 1) << endl;
	for (unsigned i = 0; i != 10; ++i)
	{
		cout << random_int() << " ";
	}
	cout << endl;

	cout << random_int(21, 30, 2) << endl;
	for (unsigned i = 0; i != 10; ++i)
	{
		cout << random_int() << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}