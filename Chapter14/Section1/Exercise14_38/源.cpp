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
	for (unsigned i = 1; i < 11; ++i)
	{
		auto num = count_if(vstr.begin(), vstr.end(), StrLenIs(i));
		cout << "长度为" << i << "的单词有" << num << "个" << endl;
	}

	system("pause");
	return 0;
}