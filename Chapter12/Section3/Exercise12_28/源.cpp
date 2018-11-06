#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<string>

using namespace std;

using line_no = vector<string>::size_type;
vector<string> file; // �ļ�ÿ�е�����
map<string, set<line_no>> wm;  // ���ʵ��кŵ�ӳ��

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
	while (getline(is, text))  // ���ļ���ÿһ��
	{
		file.push_back(text);   // ������е��ı�
		int n = file.size() - 1;   // ��ǰ�к�
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
		os << sought << "������0��" << endl;
	}
	else
	{
		auto lines = loc->second;
		os << sought << "������" << lines.size() << "��" << endl;
		for (const auto num : lines)
		{
			os << "\t(��" << num + 1 << "��) " << *(file.begin() + num) << endl;
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