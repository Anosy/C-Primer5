#include<iostream>
#include<string>
#include<map>
#include<memory>
#include<vector>
#include<set>
#include<fstream>
#include<sstream>

using namespace std;

class QueryResult;
class TextQuery
{
public:
	using line_no = vector<string>::size_type; // �к����ͱ���
	TextQuery(ifstream &); // ���캯��
	QueryResult query(const string &) const;

private:
	shared_ptr<vector<string>> file; // ����������ļ�������
	map <string, shared_ptr<set<line_no>>> wm; // ����ÿ���ʶ�Ӧ���кţ��кŹ���
};

// ���ⶨ�幹�캯��
TextQuery::TextQuery(ifstream &is) :file(new vector<string>)
{
	string text;
	while (getline(is, text)) // ����ÿ��
	{
		file->push_back(text);
		int n = file->size() - 1; // ��ǰ���к�
		istringstream line(text);
		string word;
		while (line >> word) // ÿ�е�ÿ���ַ�
		{
			auto &lines = wm[word]; // linesΪshare_ptr<set<line_no>>����
			if (!lines) // ���linesΪ�գ�����һ���µ�set
			{
				lines.reset(new set<line_no>);
			}
			lines->insert(n); // �����в���set��
		}
	}
}

class QueryResult
{
	friend ostream &print(ostream&, const QueryResult &);
public:
	using line_no = vector<string>::size_type; // ���ͱ���
	QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) : sought(s), lines(p), file(f) {} //���캯��

private:
	string sought; // �����ҵ���
	shared_ptr<set<line_no>> lines;  // �к� 
	shared_ptr<vector<string>> file; // �ļ�
};

inline
QueryResult TextQuery::query(const string &sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>); // ���δ�ҵ�sought������ָ���set��ָ��

	auto loc = wm.find(sought);
	if (loc == wm.end())
	{
		return QueryResult(sought, nodata, file);
	}
	else
	{
		return QueryResult(sought, loc->second, file);
	}
}

ostream &print(ostream &os, const QueryResult &qr)
{
	os << qr.sought << "occurs" << qr.lines->size() << " " << "times" << endl;
	for (auto num : *qr.lines)
	{
		os << "\t(line" << num + 1 << ")" << *(qr.file->begin() + num) << endl;
	}
	return os;
}