#include<iostream>
#include "Chapter6.h"
using namespace std;

int fact()
{
	static int cnt = 0;
	++cnt;
	return cnt;
}

