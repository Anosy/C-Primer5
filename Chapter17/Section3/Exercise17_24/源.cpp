#include<iostream>
#include<string>
#include<regex>
#include<fstream>

using namespace std;

int main()
{
	string phone("(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})");
	regex r(phone);
	smatch m;
	string s;
	string fmt = "$2.$5.$7";
	ifstream in("data\\mydata.txt");
	while (getline(in, s))
	{
		using std::regex_constants::format_no_copy;
		cout << regex_replace(s, r, fmt, format_no_copy) << endl;
	}

	system("pause");
	return 0;
}