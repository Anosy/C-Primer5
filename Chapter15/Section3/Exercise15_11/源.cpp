#include<iostream>
#include"Bulk_quote.h"
#include"Quote.h"

using namespace std;

int main()
{
	Quote q("C++", 15);
	Bulk_quote bq("C++", 15, 10, 0.8);

	q.debug();
	bq.debug();

	system("pause");
	return 0;
}