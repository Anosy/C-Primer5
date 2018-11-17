#include"Bulk_quote.h"
#include"Disc_quote.h"
#include"Quote.h"
#include<vector>
#include<memory>

using namespace std;

int main()
{
	vector<shared_ptr<Quote>> basket;
	
	basket.push_back(make_shared<Bulk_quote> ("C++", 50, 10, 0.25));
	basket.push_back(make_shared<Bulk_quote>("Python", 48, 10, 0.25));

	double sum = 0;
	for (auto it = basket.begin(); it != basket.end(); ++it)
	{
		sum += (*it)->net_price(10);
	}
	cout << sum << endl;

	system("pause");
	return 0;
}