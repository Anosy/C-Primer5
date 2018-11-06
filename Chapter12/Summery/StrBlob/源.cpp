#include"StrBlob.h"

using namespace std;

int main()
{
	StrBlob sb1;
	{
		StrBlob sb2 = { "a", "b", "c" };
		sb1 = sb2;
		sb2.push_back("d");
		cout << sb2.size() << endl;
	}
	cout << sb1.size() << endl;

	system("pause");
	return 0;
}