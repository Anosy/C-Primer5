#include"DebugDeleteh.h"
#include<vector>
#include<string>

using namespace std;

int main()
{
	int *p = new int;
	DebugDelete d;
	d(p);

	system("pause");
	return 0;
}