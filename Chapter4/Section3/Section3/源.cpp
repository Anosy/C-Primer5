#include<iostream>
#include<string>
using namespace std;

int main()
{
	const char *cp = "Hello World";
	while (cp && *cp)
	{
		cout << cp << " " << *cp << endl;
		cp++;
	}

	system("pause");
	return 0;
}
