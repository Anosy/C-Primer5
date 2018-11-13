#include<vector>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

class StrLenIs
{
public:
	StrLenIs(size_t n) :sz(n) {}
	bool operator()(const string &s)
	{
		return s.size() == sz;
	}

private:
	size_t sz;
};

