#include<string>
#include<iostream>

class NoDefault
{

public:
	NoDefault(int i): val(i){}
	int val;
};

class C
{
public:
	NoDefault nd;
	C(int i=0):nd(i){}
};
