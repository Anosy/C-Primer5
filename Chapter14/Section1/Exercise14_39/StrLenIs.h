#include<vector>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

class StrLenIs
{
public:
	StrLenIs(size_t min, size_t max) :minLen(min), maxLen(max) {}
	bool operator()(const string &s)
	{
		return s.size() >= minLen && s.size() < maxLen;
	}

private:
	size_t minLen;
	size_t maxLen;

};


class StrLenLonger
{
public:
	StrLenLonger(size_t min) :minLen(min) {}

	bool operator()(const string &str)
	{
		return str.size() >= minLen;
	}

private:
	size_t minLen;
};


