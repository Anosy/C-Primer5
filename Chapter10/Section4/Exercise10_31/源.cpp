#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<string>

using namespace std;

int main()
{
	istream_iterator<int> init(cin), eof;
	ostream_iterator<int> out_iter(cout, " ");
	vector<int> vi;
	while (init != eof)
	{
		vi.push_back(*init++);
	}
	sort(vi.begin(), vi.end());
	unique_copy(vi.begin(), vi.end(), out_iter);
	cout << endl;

	system("pause");
	return 0;
}