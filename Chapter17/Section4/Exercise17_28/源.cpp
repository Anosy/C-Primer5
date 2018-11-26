#include<iostream>
#include<random>
#include<vector>

using namespace std;

unsigned random_int()
{
	static default_random_engine e;
	static uniform_int_distribution<unsigned> u(0, 999);
	return u(e);
}

int main()
{
	for (unsigned i = 0; i != 10; ++i)
	{
		cout << random_int() << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}