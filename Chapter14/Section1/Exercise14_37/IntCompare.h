#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

class IntCampare
{
public:
	IntCampare(int v) :val(v) {}
	bool operator()(int v) { return val == v; }

private:
	int val;
};
