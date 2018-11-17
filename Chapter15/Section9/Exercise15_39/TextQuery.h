#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <iterator>
#include <sstream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>

class QueryResult;	//��ѯ�����
class TextQuery;	//�ı���ѯ��

using line_no = std::vector<std::string>::size_type;

//��ѯ�����
class QueryResult
{
	friend class TextQuery;
	friend std::ostream &operator<<(std::ostream &os, const QueryResult &q);

public:
	QueryResult() = default;

	QueryResult(std::string q_word, std::shared_ptr<std::set<line_no>> lines,
		std::shared_ptr<std::vector<std::string>> word_file) :
		q_word_(q_word), lines_(lines), word_file_(word_file) {}

	std::set<line_no>::iterator begin();

	std::set<line_no>::iterator end();

	std::shared_ptr<std::vector<std::string>> get_file();

private:
	std::string q_word_;										//Ҫ��ѯ�ĵ���
	std::shared_ptr<std::set<line_no>> lines_;					//�����кŵļ���
	std::shared_ptr<std::vector<std::string>> word_file_;		//�����ļ�
};


//�ı���ѯ��
class TextQuery
{
	friend class QueryResult;

public:
	TextQuery() = default;

	TextQuery(std::ifstream &is);

	//��ѯ����
	QueryResult query(const std::string &word) const;

private:
	std::shared_ptr<std::vector<std::string>> m_file_;	//��ѯ���ı�
	std::map<std::string, std::shared_ptr<std::set<line_no>>> m_word_line_;	//ÿ�������Լ������кż���
};


//Query_base������࣬�ƶ�һ����׼
class Query_base
{
	friend class Query;

protected:
	virtual ~Query_base() = default;

private:
	//eval�����뵱ǰTextQueryƥ���QueryResult
	virtual QueryResult eval(const TextQuery &) const = 0;
	//rep��ʾ��ѯ��һ��string
	virtual std::string rep() const = 0;
};


//�ӿ��࣬������������඼����ͨ��Query��ʹ�ã�����ʵ��
//Query��װ��Query_base
class Query
{
	friend Query operator~(const Query &);					//��
	friend Query operator&(const Query &, const Query &);	//��
	friend Query operator|(const Query &, const Query &);	//��
	friend std::ostream &operator<<(std::ostream &os, const Query &query);

public:
	Query(const std::string &query_word);

	QueryResult eval(const TextQuery &t) const
	{
		return query_->eval(t);
	}

	std::string rep() const
	{
		return query_->rep();
	}

private:
	//���캯������Ϊprivate,��ϣ��һ���û���㶨��Query_base���� 
	//ע�⣺��Ԫ����Է���protected��private��Ա��
	Query(std::shared_ptr<Query_base> query) : query_(query) {}

	//ͨ������ָ��ʵ�ֶ�̬��
	std::shared_ptr<Query_base> query_;	//��ѯ
};


//������
class WordQuery : public Query_base
{
	friend class Query;

	WordQuery(const std::string &query_word) : query_word_(query_word) {}

	//��ѯ����
	QueryResult eval(const TextQuery &t) const
	{
		return t.query(query_word_);
	}

	//��ѯ��һ��string
	std::string rep() const
	{
		return query_word_;
	}

private:
	std::string query_word_;	//Ҫ���ҵĵ���	
};

//�������ֲ�ѯ���ǽ�����WordQuery�ĸ����ϣ���� Query�Ĺ��캯����һ��WordQuery����ʼ��  
inline Query::Query(const std::string &query_word) :
	query_(new WordQuery(query_word)) {}


//�ǲ�ѯ��
class NotQuery : public Query_base
{
	friend Query operator~(const Query &query);

	NotQuery(const Query &query) : query_(query) {}

	//���Ǵ��麯��
	QueryResult eval(const TextQuery &) const override;

	std::string rep() const override
	{
		return "~(" + query_.rep() + ")";
	}

private:
	Query query_;	//��ѯ����
};

inline Query operator~(const Query &query)
{
	return std::shared_ptr<Query_base>(new NotQuery(query));
}


//����������ĳ������  
class BinaryQuery : public Query_base
{
protected:
	BinaryQuery(const Query &left, const Query &right, std::string op) :
		left_(left), right_(right), op_(op) {}

	std::string rep() const override
	{
		return "(" + left_.rep() + " " + op_ + right_.rep() + ")";
	}

	//��Ϊeval������û�ж��壬����BinaryQuery���ǳ�����

	Query left_;			//�������
	Query right_;			//�Ҳ�����
	std::string op_;		//������
};


//�������
class AndQuery : public BinaryQuery
{
	friend Query operator&(const Query &left, const Query &right);

	AndQuery(const Query &left, const Query &right) :
		BinaryQuery(left, right, "&") {}

	QueryResult eval(const TextQuery &t) const;
};

inline Query operator&(const Query &left, const Query &right)
{
	return std::shared_ptr<Query_base>(new AndQuery(left, right));
}


//�������
class OrQuery : public BinaryQuery
{
	friend Query operator|(const Query &left, const Query &right);

	OrQuery(const Query &left, const Query &right) :
		BinaryQuery(left, right, "|") {}

	QueryResult eval(const TextQuery &t) const;
};

inline Query operator|(const Query &left, const Query &right)
{
	return std::shared_ptr<Query_base>(new OrQuery(left, right));
}

#endif TEXTQUERY_H
