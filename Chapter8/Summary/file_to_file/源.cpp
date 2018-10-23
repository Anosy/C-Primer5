#include<string>
#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	string line;
	ifstream ifs("data/read.txt");
	ofstream ofs("data/write.txt", ofstream::out);
	if (!ifs)
	{
		cerr << "�޷����ļ���" << endl;
	}
	while (getline(ifs, line))
	{
		for (auto &l : line)
		{
			l = tolower(l);
		}
		ofs << line << endl;
	}
	ifs.close();

	system("pause");
	return 0;
}