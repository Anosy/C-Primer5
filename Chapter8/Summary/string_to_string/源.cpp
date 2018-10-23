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
	cout << "请输入用户名和手机号：" << endl;
	// 写入到vector中
	while (getline(cin, line))
	{
		PersonInfo info;
		iss.clear();
		iss.str(line);
		iss >> info.name;
		iss >> info.phone;
		people.push_back(info);
	}
	//从vector中读取
	ostringstream oss;
	for (const auto &c : people)
	{
		
		oss << c.name << " " << c.phone << endl;
	}
	cout << oss.str() << endl;

	system("pause");
	return 0;
}