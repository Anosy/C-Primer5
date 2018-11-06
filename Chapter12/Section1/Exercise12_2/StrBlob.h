#include<string>
#include<vector>
#include<memory>

class StrBlob
{
public:
	typedef std::vector<std::string>::size_type size_type;
	// ���캯��
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	// ��Ա����
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const std::string &t) { data->push_back(t); }
	void pop_back();
	std::string & front();
	std::string & back();

private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(std::string::size_type i, const std::string &msg) const;
};
StrBlob::StrBlob() :data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il) :data(std::make_shared<std::vector<std::string>>(il)) {}


void StrBlob::check(std::string::size_type i, const std::string &msg) const
{
	if (i >= data->size())
	{
		throw std::out_of_range(msg);
	}
}

std::string & StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

std::string & StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}