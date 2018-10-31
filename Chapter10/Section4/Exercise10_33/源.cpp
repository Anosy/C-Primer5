#include<fstream>
#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>
#include<string>

using namespace std;

int main()
{
	string name1 = "data/mydata1.txt";
	string name2 = "data/mydata2.txt";
	string name3 = "data/mydata3.txt";

	ifstream fin(name1);
	ofstream fout2(name2);
	ofstream fout3(name3);
	
	istream_iterator<int> init1(fin), eof1;
	ostream_iterator<int> out_iter2(fout2, " ");
	ostream_iterator<int> out_iter3(fout3, " ");

	while (init1 != eof1)
	{
		if (*init1 % 2 != 0)
		{
			out_iter2++ = *init1++;
		}
		else
		{
			out_iter3++ = *init1++;
		}
	}

	return 0;
}