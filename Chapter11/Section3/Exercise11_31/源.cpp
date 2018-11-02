#include<map>
#include<string>
#include<iostream>

using namespace std;

void remove(multimap<string, string> &author_books, const string &s)
{
	auto pos = author_books.equal_range(s);
	if (pos.first == pos.second)
	{
		cout << "û�и�����" << endl;
	}
	else
	{
		author_books.erase(pos.first, pos.second);
	}
}

void print(multimap<string, string> &author_books)
{
	cout << "��ǰ�е���Ϊ��" << endl;
	for (const auto &b : author_books)
	{
		cout << b.first << "����" << b.second << "��" << endl;
	}
	cout << endl;
}


int main()
{
	multimap<string, string> author_books;
	author_books.insert({ "��ӹ", "���Ӣ�۴�" });
	author_books.insert({ "��ӹ", "����������" });
	author_books.insert({ "����", "��尮�����1" });
	author_books.insert({ "����", "��尮�����2" });
	
	print(author_books);

	remove(author_books, "����");
	
	print(author_books);

	system("pause");
	return 0;
}