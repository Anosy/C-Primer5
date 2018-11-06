#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<memory>

using namespace std;

class QueryResult;

class TextQuery
{
public:
	using line_no = vector<string>::size_type;
	TextQuery(ifstream &is);
	QueryResult query(const string &s) const;

private:
	// 文件需要共享，单词的行号需要共享
	map<string, shared_ptr<set<line_no>>> wm;
	shared_ptr<vector<string>> file;
};

// 构建map，创建文件
TextQuery::TextQuery(ifstream &is) :file(new vector<string>) //file(new vector<string>)使用的就是直接初始化
{
	string text;
	while (getline(is, text))
	{
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while (line >> word)
		{
			auto &p = wm[word]; // 使用引用改变p也改变wm
			if (!p)
			{
				p.reset(new set<line_no>);
			}
			p->insert(n);
		}
	}
}

// 保存查询到的结果类
class QueryResult
{
	friend ostream &print(ostream &, const QueryResult &s);
public:
	using line_no = vector<string>::size_type;
	QueryResult(string s, shared_ptr<set<line_no>> p,
		shared_ptr<vector<string>> f) :sought(s), ptr(p), file(f) {}
private:
	string sought;
	shared_ptr<set<line_no>> ptr;
	shared_ptr<vector<string>> file;
};

QueryResult TextQuery::query(const string &s) const
{
	static shared_ptr<set<line_no>> nodata;
	auto loc = wm.find(s);
	if (loc == wm.end())
	{
		return QueryResult(s, nodata, file);
	}
	else
	{
		return QueryResult(s, loc->second, file);
	}
}

ostream &print(ostream &os, const QueryResult &q)
{
	os << q.sought << "出现了" << q.ptr->size() << "次" << endl;
	for (const auto &num : *(q.ptr))
	{
		os << "\t(第" << num + 1 << "行) " << *(q.file->begin() + num) << endl;
	}
	return os;
}

