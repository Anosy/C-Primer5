#include"myStrBlob.h"

using namespace std;

int main()
{
	StrBlob b1;
	{
		StrBlob b2 = { "a", "an", "the" };
		b1 = b2;
		b2.push_back("about");
		cout << "b2�Ĵ�С" << b2.size() << endl;
		cout << b2.front() << " " << b2.back() << endl;
	}
	cout << "b1�Ĵ�С" << b1.size() << endl;
	cout << b1.front() << " " << b1.back() << endl;

	StrBlob b3 = b1;
	b3.push_back("next");
	cout << "b3�Ĵ�С" << b3.size() << endl;
	cout << b3.front() << " " << b3.back() << endl;

	system("pause");
	return 0;
}