#ifndef SCREEN_H
#define SCREEN_H

#include<string>
#include<iostream>

using namespace std;

template <int H, int W> class Screen;

template <int H, int W>
ostream & operator <<(ostream &os, const Screen<H, W> & sc);
template <int H, int W>
istream & operator >>(istream &is, Screen<H, W> &sc);


template <int H, int W>
class Screen
{
	friend istream & operator>> <H, W>(istream &is, Screen<H, W> & sc);
	friend ostream & operator<< <H, W>(ostream &os, const Screen<H, W> & sc);

public:
	Screen() :contents(H*W, ' ') { }
	Screen(char c) : contents(H*W, c) {}
	char get() const
	{
		return contents[cursor];
	}
	char get(int, int) const;
	Screen &clear(char c = bkground);
	Screen &move(int r, int c);
	Screen &set(char);
	Screen &set(int, int, char);
	Screen &display(ostream &os)
	{
		do_display(os);
		return *this;
	}
	const Screen &display(ostream &os) const
	{
		do_display(os);
		return *this;
	}

private:
	static const char bkground = ' ';
	void do_display(ostream &os) const { os << contents; }
	int cursor = 0;
	string contents;
};

template <int H, int W>
Screen<H, W>& Screen<H, W>::clear(char c)
{
	contents = string(H*W, c);
	return *this;
}

template <int H, int W>
inline Screen<H, W>& Screen<H, W>::move(int r, int c)
{
	int row = r * W;
	cursor = row + c;
	return *this;
}

template <int H, int W>
inline char Screen<H, W>::get(int r, int c) const
{
	int row = r * W;
	cursor = row + c;
	return contents[cursor];
}

template <int H, int W>
inline Screen<H, W>& Screen<H, W>::set(char c)
{
	contents[cursor] = c;
	return *this;
}

template <int H, int W>
inline Screen<H, W>& Screen<H, W>::set(int r, int c, char ch)
{
	int row = r * W;
	cursor = row + c;
	contents[cursor] = ch;
	return *this;
}

template <int H, int W>
ostream & operator << (ostream &os, const Screen<H, W> & sc)
{
	os << sc.contents;
	return os;
}

template <int H, int W>
istream & operator >> (istream &is, Screen<H, W> & sc)
{
	string t;
	is >> t;
	sc.contents = t.substr(0, H * W);
	return is;
}

#endif // !SCREEN_H
