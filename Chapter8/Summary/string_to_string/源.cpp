#include<string>
#include<iostream>
#include<sstream>
#include<vector>

using namespace std;

struct PersonInfo
{
	string name;
	string phone;
};


int main()
{
	vector<PersonInfo> people;
	string line, word;
	istringstream iss;
	cout << " �������û������ֻ���:" << endl;
	// д�뵽vector��
	while (getline(cin, line))
	{
		PersonInfo info;
		iss.clear();
		iss.str(line);
		iss >> info.name;
		iss >> info.phone;
		people.push_back(info);
	}
	//��vector�ж�ȡ
	ostringstream oss;
	for (const auto &c : people)
	{
		
		oss << c.name << " " << c.phone << endl;
	}
	cout << oss.str() << endl;

	system("pause");
	return 0;
}