#include<iostream>
#include<string>

class Screen
{
private:
	unsigned height = 0, width = 0;
	unsigned cursor = 0;
	std::string contents;
public:
	Screen() = default;
	Screen(unsigned ht, unsigned wh):height(ht), width(wh),contents(ht * wh, ' '){}
	Screen(unsigned ht, unsigned wh, char c):height(ht), width(wh), contents(ht *wh, c){}
};