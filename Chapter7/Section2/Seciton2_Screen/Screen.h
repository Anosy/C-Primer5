#include<string>
#include<iostream>
#include<vector>

class Screen {
public:
	typedef std::string::size_type pos;
	friend class Window_mgr;
private:
	pos currsor = 0;
	pos height = 0, width = 0;
	std::string contents;
	void do_display(std::ostream &os) const { os << contents; }
public:
	Screen() = default; // 因为下面一句提供了构造函数，所以编译器不能提供默认构造函数
	Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht * wd, c){} // 构造函数
	char get() const { return contents[currsor]; } // 读取光标处的字符,函数定义在内部，因此是隐式内联
	inline char get(pos r, pos c) const; // 显式内联，get重载函数的声明
	Screen &move(pos r, pos c); // 移动后得到的新位置
	Screen &set(char);
	Screen &set(pos, pos, char);
	Screen &display(std::ostream &os)
	{
		do_display(os);
		return *this;
	}
	const Screen &display(std::ostream &os) const
	{
		do_display(os);
		return *this;
	}
};
 inline Screen &Screen::move(pos r, pos c)
{
	pos row = r * width; // 计算行的位置
	currsor = row + c; // 在行内将光标移动到指定的列
	return *this; 
}
 inline char Screen::get(pos r, pos c) const
 {
	 pos row = r * width; // 计算行的位置
	 return contents[row + c];
 }
 inline Screen & Screen::set(char c)
 {
	 contents[currsor] = c;
	 return *this;
 }
 inline Screen &Screen::set(pos r, pos c, char ch)
 {
	 contents[r*width + c] = ch;
	 return *this;
 }


 // 窗口管理类
 class Window_mgr
 {
 public:
	 // 窗口中每个屏幕的编号
	 using ScreenIndex = std::vector<Screen>::size_type;
	 // 按照编号将指定
	 void clear(ScreenIndex);
 private:
	 std::vector<Screen> screens{ Screen(24, 80, ' ') }; // 类内初始值使用=或者{}
 };
 void Window_mgr::clear(ScreenIndex i)
 {
	 // s是一个Screen的引用，指向我们想清空的屏幕
	 Screen &s = screens[i];
	 // 将那个选定的Screen重置为空白
	 s.contents = std::string(s.height * s.width, ' ');
 }