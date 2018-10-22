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
	Screen() = default; // ��Ϊ����һ���ṩ�˹��캯�������Ա����������ṩĬ�Ϲ��캯��
	Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht * wd, c){} // ���캯��
	char get() const { return contents[currsor]; } // ��ȡ��괦���ַ�,�����������ڲ����������ʽ����
	inline char get(pos r, pos c) const; // ��ʽ������get���غ���������
	Screen &move(pos r, pos c); // �ƶ���õ�����λ��
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
	pos row = r * width; // �����е�λ��
	currsor = row + c; // �����ڽ�����ƶ���ָ������
	return *this; 
}
 inline char Screen::get(pos r, pos c) const
 {
	 pos row = r * width; // �����е�λ��
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


 // ���ڹ�����
 class Window_mgr
 {
 public:
	 // ������ÿ����Ļ�ı��
	 using ScreenIndex = std::vector<Screen>::size_type;
	 // ���ձ�Ž�ָ��
	 void clear(ScreenIndex);
 private:
	 std::vector<Screen> screens{ Screen(24, 80, ' ') }; // ���ڳ�ʼֵʹ��=����{}
 };
 void Window_mgr::clear(ScreenIndex i)
 {
	 // s��һ��Screen�����ã�ָ����������յ���Ļ
	 Screen &s = screens[i];
	 // ���Ǹ�ѡ����Screen����Ϊ�հ�
	 s.contents = std::string(s.height * s.width, ' ');
 }