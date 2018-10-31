#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<iterator>
#include<string>
#include<fstream>

using namespace std;

int main()
{
	ifstream in("data/mydata.txt");
	istream_iterator<string> init(in), eof;
	vector<string> vStr;
	while (init != eof)
	{
		vStr.push_back(*init++);
	}

	for (const auto v : vStr)
	{
		cout << v << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}