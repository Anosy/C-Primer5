#include<iostream>
#include<regex>
#include<string>
#include<fstream>

using namespace std;

bool valid(const smatch &m)
{
	if (!(m[3].matched))
	{
		return !(m[2].matched);
	}
	else
	{
		return true;
	}
}


int main()
{
	string mail("(\\d{4})([-])?(\\d{5})?");

	regex r(mail);
	smatch m;
	string s;
	ifstream in("data\\mydata.txt");
	string fmt = "$1-$3";
	if (!in)
	{
		cout << "ÎÄ¼þÎª¿Õ" << endl;
	}
	while (getline(in, s))
	{
		for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it)
		{
			if (valid(*it))
			{
				cout << it->format(fmt) << endl;
			}
			else
			{
				continue;
			}
		}
	}

	system("pause");
	return 0;
}