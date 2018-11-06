#include"StrBlob_StrBlobPtr.h"

using namespace std;

int main()
{
	StrBlob b1;
	{
		StrBlob b2 = { "a", "an", "the" };
		b1 = b2;
		b2.push_back("about");
		cout << b2.size() << endl;
	}
	cout << b1.size() << endl;
	cout << b1.front() << " " << b1.back() << endl;

	cout << "´òÓ¡b1" << endl;
	for (auto it = b1.begin(); neq(it, b1.end()); it.incr())
	{
		cout << it.deref() << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}