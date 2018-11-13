#include"StrLenIs.h"
#include<fstream>
#include<sstream>

using namespace std;

int main()
{
	vector<string> vstr;
	ifstream is("data/mydata.txt");
	string line;
	while (getline(is, line))
	{
		istringstream iss(line);
		string word;
		while (iss >> word)
		{
			vstr.push_back(word);
		}
	}

	cout << "大小在1~9的数有" << count_if(vstr.begin(), vstr.end(), StrLenIs(1, 9)) << "个" << endl;
	cout << "大小在>=10的数有" << count_if(vstr.begin(), vstr.end(), StrLenLonger(10)) << "个" << endl;

	system("pause");
	return 0;
}