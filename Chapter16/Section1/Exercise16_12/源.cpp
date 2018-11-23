#include"Blob.h"

using namespace std;

int main()
{
	Blob<string> b1 = { "a", "b", "c", "d" };
	b1.push_back("e");
	for (size_t i = 0; i != b1.size(); ++i)
	{
		cout << b1[i] << " ";
	}
	cout << endl;

	Blob<int> b2 = { 1,2,3,4,3,2,1 };
	b2.push_back(999);
	for (size_t i = 0; i != b2.size(); ++i)
	{
		cout << b2[i] << " ";
	}
	cout << endl;

	cout << (b1 == b1) << endl;

	cout << "-------------------------------" << endl;

	BlobPtr<string> bp1(b1);
	BlobPtr<string> bp2(b1);
	cout << (bp1 == bp2) << endl;

	cout << *bp1++ << endl;
	cout << (bp1 == bp2) << endl;

	system("pause");
	return 0;
}