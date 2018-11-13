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

	cout << "��С��1~9������" << count_if(vstr.begin(), vstr.end(), StrLenIs(1, 9)) << "��" << endl;
	cout << "��С��>=10������" << count_if(vstr.begin(), vstr.end(), StrLenLonger(10)) << "��" << endl;

	system("pause");
	return 0;
}