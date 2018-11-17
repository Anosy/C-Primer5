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
	
	{
		cout << "Test5" << endl;
		Quote q1("C++", 128.0);
		Quote q2(q1);
	}

	{
		cout << "Test6" << endl;
		Bulk_quote bq1("Pyhton", 89, 5, 0.19);
		Bulk_quote bq2(bq1);
	}

	{
		cout << "Test7" << endl;
		Bulk_quote bq1("Pyhton", 89, 5, 0.19);
		Bulk_quote bq2;
		bq2 = bq1;
	}

	{
		cout << "Test8" << endl;
		Bulk_quote bq1("Pyhton", 89, 5, 0.19);
		Bulk_quote bq2(std::move(bq1));
	}

	{
		cout << "Test9" << endl;
		Bulk_quote bq1("Pyhton", 89, 5, 0.19);
		Bulk_quote bq2;
		bq2 = std::move(bq1);
		cout << endl;
	}

	
	system("pause");
	return 0;
}