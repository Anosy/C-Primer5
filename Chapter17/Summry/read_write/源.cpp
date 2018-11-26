#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	fstream in("data\\mydata.txt", fstream::ate | fstream::in | fstream::out);
	auto file_end = in.tellg();
	in.seekg(0, fstream::beg);
	unsigned cnt = 0;
	string line;
	while (in && in.tellg() != file_end && getline(in, line))
	{
		cnt = line.size();
		auto mark = in.tellg();
		in.seekg(0, fstream::end);
		in << cnt;
		if (mark != file_end)
		{	
			in << " ";
		}
		in.seekg(mark);
	}
	in.seekg(0, fstream::end);
}