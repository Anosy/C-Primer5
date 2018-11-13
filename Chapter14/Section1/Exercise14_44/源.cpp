#include<iostream>
#include<functional>
#include<vector>
#include<map>
#include<string>

using namespace std;

int add(int a, int b)
{
	return a + b;
}

class multi
{
public:
	int operator()(int a, int b)
	{
		return a * b;
	}
};

int main()
{
	auto binOps = map<string, function<int(int, int)>> 
	{
		{"+", add},
		{"-", minus<int>()},
		{"*", multi()},
		{"/", [](int a, int b) {return a * b; }},
		{"%", modulus<int>()}
	};
	int a, b;
	string op;
	cin >> a >> op >> b;
	cout << binOps[op](a, b) << endl;

	system("pause");
	return 0;
}

