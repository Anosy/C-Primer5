#include<iostream>
#include<string>
#include<sstream>

using namespace std;

template <typename T> string debug_rep(const T &t);
template <typename T> string debug_rep(T *p);


template <typename T> string debug_rep(const T &t)
{
	cout << "调用的是debug_rep(const T &t)版本" << endl;
	ostringstream ret;
	ret << t;
	return ret.str();
}

template <typename T> string debug_rep(T *p)
{
	cout << "调用的是debug_rep(T *p)版本" << endl;
	ostringstream ret;
	ret << "pointer: " << p;
	if (p)
	{
		ret << " " << debug_rep(*p);
	}
	else
	{
		ret << "null pointer";
	}
	return ret.str();
}

//string debug_rep(const string &s)
//{
//	cout << "调用的是非模板函数" << endl;
//	return '"' + s + '"';
//}

int main()
{
	// 第一种调用,只有第一个模板类可行
	string s("hi");
	cout << debug_rep(s) << endl;
	cout << endl;

	// 第二种调用，两个模板函数都可行，但是第一个模板需要将普通的指针给转换为常量指针
	cout << debug_rep(&s) << endl;
	cout << endl;

	// 第三种调用，两个模板函数都可行，但是第二个模板更加的特例
	const string s2("hello");
	cout << debug_rep(&s2) << endl;
	cout << endl;

	// 第四种调用，两个模板函数都可行，但是第二个模板更加的特例
	cout << debug_rep("good") << endl;
	cout << endl;

	system("pause");
	return 0;
}