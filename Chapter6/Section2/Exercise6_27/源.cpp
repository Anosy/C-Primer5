#include<iostream>
#include<initializer_list>

using namespace std;

int mySum(initializer_list<int> ls)
{
	int sum= 0;
	for (auto c : ls)
	{
		sum += c;
	}
	return sum;
}

int main()
{
	cout << "the sum is of 1, 6, 9 is " << mySum({ 1, 6, 9 }) << endl;
	
	system("pause");
	return 0;
}