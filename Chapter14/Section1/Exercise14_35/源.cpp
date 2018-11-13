#include"PrintString.h"
#include<vector>

using namespace std;

int  main()
{
	vector<string> vstr;
	ReadString rs;
	while (true)
	{
		string line = rs();
		if (line != " ")
		{
			vstr.push_back(line);
		}
		else
		{
			break;
		}
	}

	for (const auto &v : vstr)
	{
		cout << v << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}