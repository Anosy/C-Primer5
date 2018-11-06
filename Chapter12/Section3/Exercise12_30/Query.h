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
	using line_no = vector<string>::size_type; // 行号类型别名
	TextQuery(ifstream &); // 构造函数
	QueryResult query(const string &) const;

private:
	shared_ptr<vector<string>> file; // 保存输入的文件（共享）
	map <string, shared_ptr<set<line_no>>> wm; // 保存每个词对应的行号（行号共享）
};

// 类外定义构造函数
TextQuery::TextQuery(ifstream &is) :file(new vector<string>)
{
	string text;
	while (getline(is, text)) // 读入每行
	{
		file->push_back(text);
		int n = file->size() - 1; // 当前的行号
		istringstream line(text);
		string word;
		while (line >> word) // 每行的每个字符
		{
			auto &lines = wm[word]; // lines为share_ptr<set<line_no>>类型
			if (!lines) // 如果lines为空，分配一个新的set
			{
				lines.reset(new set<line_no>);
			}
			lines->insert(n); // 将此行插入set中
		}
	}
}

class QueryResult
{
	friend ostream &print(ostream&, const QueryResult &);
public:
	using line_no = vector<string>::size_type; // 类型别名
	QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) : sought(s), lines(p), file(f) {} //构造函数

private:
	string sought; // 待查找的字
	shared_ptr<set<line_no>> lines;  // 行号 
	shared_ptr<vector<string>> file; // 文件
};

inline
QueryResult TextQuery::query(const string &sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>); // 如果未找到sought，返回指向此set的指针

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