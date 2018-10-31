#include<fstream>
#include<iostream>
#include<algorithm>
#include<iterator>
#include<list>
#include<string>
#include<vector>

using namespace std;

int main()
{
	vector<int> vInt = { 1,2,3,4,5,6,7,8,9,10 };
	ostream_iterator<int> out_iter(cout, " ");
	copy(vInt.cbegin(), vInt.cend(), out_iter);
	cout << endl;
	list<int> ilist;
	vector<int>::reverse_iterator re(vInt.begin() + 2);
	vector<int>::reverse_iterator rb(vInt.begin() + 7);
	copy(rb, re, back_inserter(ilist));
	copy(ilist.cbegin(), ilist.cend(), out_iter);
	cout << endl;

	system("pause");
	return 0;
}