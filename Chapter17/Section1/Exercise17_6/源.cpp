#include<tuple>
#include"Sales_data.h"
#include<vector>
#include<iostream>
#include<algorithm>
#include<functional>
#include<fstream>
#include<numeric>

using namespace std;


class matches
{
public:
	matches(vector<Sales_data>::size_type n,
		vector<Sales_data>::const_iterator f, vector<Sales_data>::const_iterator s ) :
		num(n), first(f), second(s) {}
	vector<Sales_data>::size_type get_num() const { return num; }
	vector<Sales_data>::const_iterator get_first() const { return first; }
	vector<Sales_data>::const_iterator get_second() const { return second; }
private:
	vector<Sales_data>::size_type num;
	vector<Sales_data>::const_iterator first, second;
};


vector<matches>
findBook(const vector<vector<Sales_data>> &files, const string &book)
{
	vector<matches> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it)
	{
		auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (found.first != found.second)
		{
			// matches mat(it - files.cbegin(), found.first, found.second);
			ret.emplace_back(it - files.cbegin(), found.first, found.second);
		}
	}
	return ret;
}

void reportResults(istream &in, ostream &os, const vector<vector<Sales_data>> &files)
{
	string s;
	while (in >> s)
	{
		auto trans = findBook(files, s);
		if (trans.empty())
		{
			os << "not found in any stores!" << endl;
			continue;
		}

		for (const auto &store : trans)
		{
			os << "store " << store.get_num() << " sales: " << accumulate(store.get_first(), store.get_second(), Sales_data(s)) << endl;
		}

	}
}

vector<Sales_data> build_store(const string &s)
{
	Sales_data item;
	vector<Sales_data> ret;
	ifstream is(s);
	while (read(is, item))
	{
		ret.push_back(item);
	}
	sort(ret.begin(), ret.end(), compareIsbn);
	return ret;
}

int main()
{
	vector<vector<Sales_data>> files;
	files.push_back(build_store("data/mydata.txt"));

	reportResults(cin, cout, files);


	system("pause");
	return 0;
}