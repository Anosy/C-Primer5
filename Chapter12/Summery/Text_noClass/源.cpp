#include<set>
#include<map>
#include<string>
#include<vector>
#include<iostream>
#include<sstream>
#include<fstream>

using namespace std;

using line_no = vector<string>::size_type;
vector<string> file; // 全局变量
map<string, set<line_no>> wm; // 全局变量

// 清除标点
string clean_str(const string &word)
{
	string temp;
	for (auto it = word.cbegin(); it != word.cend(); ++it)
	{
		if (!ispunct(*it))
		{
			temp += tolower(*it);
		}
	}
	return temp;
}

// 将文本转化为map，并且保存文本
void input_text(ifstream &is)
{
	string text;
	while (getline(is, text))
	{
		file.push_back(text);
		int n = file.size() - 1; // 当前的行号
		string word;
		istringstream iss(text);
		while (iss >> word)
		{	
			wm[clean_str(word)].insert(n);
		}
	}
}

// 查询输入的单词，并且打印结果
ostream &query_and_print(const string &sought, ostream &os)
{
	auto loc = wm.find(sought);
	if (loc == wm.end())
	{
		os << sought << "出现0次" << endl;
	}
	auto lines = loc->second;
	cout << sought << "出现了" << lines.size() << "次" << endl;
	for (const auto &c : lines)
	{
		os << "\t(第" << c + 1 << "行) " << *(file.begin() + c) << endl;
	}
	return os;
}

void runQueries(ifstream &infile)
{
	input_text(infile);
	while (true)
	{
		cout << "输入要查询的单词:" << endl;
		string s;
		if (!(cin>>s) || s == "q")
		{
			break;
		}
		query_and_print(s, cout) << endl;
	}
}

int main()
{
	ifstream infile("data/mydata.txt");
	if (!infile)
	{
		cout << "No input file!" << endl;
		return -1;
	}
	runQueries(infile);
	return 0;
}