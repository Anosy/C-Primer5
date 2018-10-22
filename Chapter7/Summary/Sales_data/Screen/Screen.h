#include<iostream>
#include<string>
#include<vector>

class Screen
{
private:
	unsigned height = 0, width = 0, curror = 0;
	std::string contents;
public:
	Screen() = default;
	Screen(unsigned h, unsigned w, char ch) :height(h), width(w), contents(h*w, ch){}
	Screen(unsigned h, unsigned w) : Screen(h, w, '#'){}
	Screen &move(unsigned r, unsigned c);
	Screen &set(char ch);
	Screen &set(unsigned r, unsigned c, char ch);
	Screen display(std::ostream &os)
	{
		os << contents;
		return *this;
	}
	
};
inline Screen & Screen::move(unsigned r, unsigned c)
{
	curror = r * width + c;
	return *this;
}
inline Screen &Screen::set(char ch)
{
	contents[curror] = ch;
	return *this;
}
inline Screen &Screen::set(unsigned r, unsigned c, char ch)
{
	contents[r * width + c] = ch;
	return *this;
}


