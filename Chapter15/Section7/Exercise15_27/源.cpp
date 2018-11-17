#include"Bulk_quote.h"
#include"Quote.h"
#include"Disc_quote.h"

using namespace std;

int main()
{
	{
		cout << "Test1" << endl;
		Quote q;
	}

	{
		cout << "Test2" << endl;
		Bulk_quote bq;
	}

	{
		cout << "Test3" << endl;
		Quote q("C++", 128.0);
	}

	{
		cout << "Test4" << endl;
		Bulk_quote bq("Pyhton", 89, 5, 0.19);
	}

	system("pause");
	return 0;
}