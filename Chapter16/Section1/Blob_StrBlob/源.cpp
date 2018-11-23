#include"StrBlob_StrBlobPtr.h"

using namespace std;

int main()
{
	StrBlob sb1 = {"a", "b", "c", "d"};
	auto be = begin(sb1);
	while (be != end(sb1))
	{
		cout << be.deref() << " ";
		be.incr();
	}
	cout << endl;

	system("pause");
	return 0;
}