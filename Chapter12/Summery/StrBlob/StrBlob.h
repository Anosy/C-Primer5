#include<map>
#include<string>
#include<memory>
#include<iostream>
#include<vector>
#include<initializer_list>

using namespace std;

class StrBlob
{
public:
	typedef vector<string>::size_type size_type;
	StrBlob() : data(make_shared<vector<string>>()) {};
	StrBlob(initializer_list<string> il) : data(make_shared<vector<string>> (il)) {};
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string &s) { data->push_back(s); }
	void pop_back();
	string & back();
	string & front();

private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const;
};

inline void StrBlob::check(size_type i, const string &msg) const
{
	if (i >= msg.size())
	{
		throw out_of_range(msg);
	}
}

inline string &StrBlob::front()
{
	check(0, "front error");
	return data->front();
}

inline string &StrBlob::back()
{
	check(0, "back error");
	return data->back();
}

inline void StrBlob::pop_back()
{
	check(0, "pop_back error");
	return data->pop_back();
}