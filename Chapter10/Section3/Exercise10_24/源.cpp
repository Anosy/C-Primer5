#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<functional>

using namespace std;
using namespace std::placeholders;

bool check_size(const string &s,  string::size_type sz)
{
	return s.size() <= sz;
}

int main()
{
	string  s = "Hello";
	vector<int> vInt = { 1,2,3,4,5,6,7 };
	auto wc = find_if(vInt.begin(), vInt.end(), bind(check_size, s, _1));
	cout << "第" << wc - vInt.begin() + 1 << "个数" << *wc << "大于等于" << s << "的长度" << endl;

	system("pause");
	return 0;
}