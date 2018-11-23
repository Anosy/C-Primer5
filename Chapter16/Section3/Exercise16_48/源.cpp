#include<iostream>
#include<string>
#include<sstream>

using namespace std;

template <typename T> string debug_rep(const T &t);
template <typename T> string debug_rep(T *p);


template <typename T> string debug_rep(const T &t)
{
	cout << "���õ���debug_rep(const T &t)�汾" << endl;
	ostringstream ret;
	ret << t;
	return ret.str();
}

template <typename T> string debug_rep(T *p)
{
	cout << "���õ���debug_rep(T *p)�汾" << endl;
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
//	cout << "���õ��Ƿ�ģ�庯��" << endl;
//	return '"' + s + '"';
//}

int main()
{
	// ��һ�ֵ���,ֻ�е�һ��ģ�������
	string s("hi");
	cout << debug_rep(s) << endl;
	cout << endl;

	// �ڶ��ֵ��ã�����ģ�庯�������У����ǵ�һ��ģ����Ҫ����ͨ��ָ���ת��Ϊ����ָ��
	cout << debug_rep(&s) << endl;
	cout << endl;

	// �����ֵ��ã�����ģ�庯�������У����ǵڶ���ģ����ӵ�����
	const string s2("hello");
	cout << debug_rep(&s2) << endl;
	cout << endl;

	// �����ֵ��ã�����ģ�庯�������У����ǵڶ���ģ����ӵ�����
	cout << debug_rep("good") << endl;
	cout << endl;

	system("pause");
	return 0;
}