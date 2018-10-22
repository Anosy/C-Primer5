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
	Screen(unsigned ht, unsigned wh) :height(ht), width(wh), contents(ht * wh, ' ') {}
	Screen(unsigned ht, unsigned wh, char c) :height(ht), width(wh), contents(ht *wh, c) {}
	Screen & move(unsigned r, unsigned c)
	{
		unsigned row = r * width;
		cursor = row + c;
		return *this;
	}
	Screen &set(char ch)
	{
		contents[cursor] = ch;
		return *this;
	}
	Screen &set(unsigned r, unsigned c, char ch)
	{
		contents[r*width + c] = ch;
		return *this;
	}
	Screen &display(std::ostream &os)
	{
		os << contents;
		return *this;
	}
};