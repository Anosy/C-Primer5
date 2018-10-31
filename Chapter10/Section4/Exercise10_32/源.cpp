#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<string>
#include"Sales_data.h"
#include<numeric>

using namespace std;

bool compareIsbn(const Sales_data & item1, const Sales_data &item2)
{
	return item1.isbn() < item2.isbn();
}


int main()
{
	vector<Sales_data> vs;
	// istream_iterator<int> init(cin);
	// istream_iterator<int> eof;
	Sales_data item;
	while (read(cin, item))
	{
		vs.push_back(item);
	}
	if (vs.empty())
	{
		cerr << "NO data!" << endl;
		return -1;
	}
	sort(vs.begin(), vs.end(), compareIsbn);

	auto l = vs.begin();
	while (l != vs.end())
	{
		auto item = *l;
		auto r = find_if(l + 1, vs.end(), [item](const Sales_data &item1) {return item1.isbn() != item.isbn(); });
		print(cout, accumulate(l + 1, r, item));
		l = r;
	}

	system("pause");
	return 0;
}