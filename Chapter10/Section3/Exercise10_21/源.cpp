#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int number = 5;
	auto f = [number]() mutable -> bool 
	{
		if (number > 0)
		{
			--number;
			return false;
		}
		else
		{
			return true;
		}
	};

	for(int i = 0; i < 6; i++)
	{
		cout << f() << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}