#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<string>

using namespace std;

using line_no = vector<string>::size_type;
vector<string> file; // 文件每行的内容
map<string, set<line_no>> wm;  // 单词到行号的映射

string cleanup_str(const string &word)
{
	string ret;
	for (auto it = word.begin(); it != word.end(); ++it)
	{
		if (!ispunct(*it))
		{
			ret += tolower(*it);
		}
	}
	return ret;
}

void input_text(ifstream &is)
{
	string text;
	while (getline(is, text))  // 对文件的每一行
	{
		file.push_back(text);   // 保存此行的文本
		int n = file.size() - 1;   // 当前行号
		istringstream line(text);
		string word;
		while (line >> word)
		{
			wm[cleanup_str(word)].insert(n);
		}
	}
}

ostream &query_and_print(const string &sought, ostream &os)
{
	auto loc = wm.find(sought);
	if (loc == wm.end())
	{
		os << sought << "出现了0次" << endl;
	}
	else
	{
		auto lines = loc->second;
		os << sought << "出现了" << lines.size() << "次" << endl;
		for (const auto num : lines)
		{
			os << "\t(第" << num + 1 << "行) " << *(file.begin() + num) << endl;
		}
	}
	return os;
}

void runQueries(ifstream &infile)
{
	input_text(infile);
	while (true)
	{
		cout << "enter word to lool for, or q to quit:";
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