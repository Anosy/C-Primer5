#include<set>
#include<map>
#include<string>
#include<vector>
#include<iostream>
#include<sstream>
#include<fstream>

using namespace std;

using line_no = vector<string>::size_type;
vector<string> file; // ȫ�ֱ���
map<string, set<line_no>> wm; // ȫ�ֱ���

// ������
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

// ���ı�ת��Ϊmap�����ұ����ı�
void input_text(ifstream &is)
{
	string text;
	while (getline(is, text))
	{
		file.push_back(text);
		int n = file.size() - 1; // ��ǰ���к�
		string word;
		istringstream iss(text);
		while (iss >> word)
		{	
			wm[clean_str(word)].insert(n);
		}
	}
}

// ��ѯ����ĵ��ʣ����Ҵ�ӡ���
ostream &query_and_print(const string &sought, ostream &os)
{
	auto loc = wm.find(sought);
	if (loc == wm.end())
	{
		os << sought << "����0��" << endl;
	}
	auto lines = loc->second;
	cout << sought << "������" << lines.size() << "��" << endl;
	for (const auto &c : lines)
	{
		os << "\t(��" << c + 1 << "��) " << *(file.begin() + c) << endl;
	}
	return os;
}

void runQueries(ifstream &infile)
{
	input_text(infile);
	while (true)
	{
		cout << "����Ҫ��ѯ�ĵ���:" << endl;
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