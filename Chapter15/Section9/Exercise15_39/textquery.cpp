#include "TextQuery.h"

//QueryResult
std::ostream &operator<<(std::ostream &os, const QueryResult &result)
{
	os << "���ʳ�����:" << result.lines_->size() << "��\n";
	for (line_no i : *result.lines_)
	{
		os << "  " << "line(" << i + 1 << ") ";
		os << (*(result.word_file_))[i] << "\n";
	}
	return os;
}


std::set<line_no>::iterator QueryResult::begin()
{
	return lines_->begin();
}

std::set<line_no>::iterator QueryResult::end()
{
	return lines_->end();
}

std::shared_ptr<std::vector<std::string>> QueryResult::get_file()
{
	return word_file_;
}



//TextQuery
//���캯��
TextQuery::TextQuery(std::ifstream &is) : m_file_(new std::vector<std::string>)
{
	std::string word;	//����
	std::string line;	//һ���ı�
	static int i = 0;	//�к�

	while (std::getline(is, line))
	{
		m_file_->push_back(line);	//����vactor<string>��ĩβ
		i = m_file_->size() - 1;	//���һ�е��к�
		std::istringstream ist(line);
		while (ist >> word)
		{
			auto &li = m_word_line_[word];	//����word���ڵ��кż�
			if (!li)
			{
				//Ϊ�գ�����һ��set<line_no>
				li.reset(new std::set<line_no>);
			}
			//��Ϊ��
			li->insert(i);
		}
	}
}

//���ʲ�ѯ
QueryResult TextQuery::query(const std::string &word) const
{
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);	//ָ���кż���ָ��
	auto ret = m_word_line_.find(word);
	if (ret == m_word_line_.end())
	{
		return QueryResult(word, nodata, m_file_);
	}
	else
	{
		return QueryResult(word, ret->second, m_file_);
	}
}

std::ostream &operator<<(std::ostream &os, const Query &query)
{
	return os << query.rep();
}


//NotQuery
QueryResult NotQuery::eval(const TextQuery &text) const
{
	auto result = query_.eval(text);	//�ı���ѯ�Ľ������
	auto ret_lines = std::make_shared<std::set<line_no>>();	//�кż���
	auto begin = result.begin();
	auto end = result.end();
	auto sz = result.get_file()->size();	//�ı�������

	for (std::size_t n = 0; n != sz; ++n)
	{
		if (begin == end || *begin != n)
		{
			ret_lines->insert(n);
		}
		else if (begin != end)
		{
			++begin;
		}
	}

	return QueryResult(rep(), ret_lines, result.get_file());
}


//AndQuery
QueryResult AndQuery::eval(const TextQuery &text) const
{
	auto left = left_.eval(text);
	auto right = right_.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	//��������Χ�Ľ���д��һ��Ŀ�ĵ�������
	//���ε��õ�Ŀ�ĵ�������ret_lines���Ԫ��
	set_intersection(left.begin(), left.end(),
		right.begin(), right.end(),
		std::inserter(*ret_lines, ret_lines->begin()));

	return QueryResult(rep(), ret_lines, left.get_file());
}


//OrQuery
QueryResult OrQuery::eval(const TextQuery &text) const
{
	auto left = left_.eval(text);
	auto right = right_.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());

	return QueryResult(rep(), ret_lines, left.get_file());
}

