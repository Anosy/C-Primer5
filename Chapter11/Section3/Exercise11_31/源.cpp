#include<map>
#include<string>
#include<iostream>

using namespace std;

void remove(multimap<string, string> &author_books, const string &s)
{
	auto pos = author_books.equal_range(s);
	if (pos.first == pos.second)
	{
		cout << "没有该作者" << endl;
	}
	else
	{
		author_books.erase(pos.first, pos.second);
	}
}

void print(multimap<string, string> &author_books)
{
	cout << "当前有的书为：" << endl;
	for (const auto &b : author_books)
	{
		cout << b.first << "：《" << b.second << "》" << endl;
	}
	cout << endl;
}


int main()
{
	multimap<string, string> author_books;
	author_books.insert({ "金庸", "射雕英雄传" });
	author_books.insert({ "金庸", "倚天屠龙记" });
	author_books.insert({ "赵四", "乡村爱情故事1" });
	author_books.insert({ "赵四", "乡村爱情故事2" });
	
	print(author_books);

	remove(author_books, "赵四");
	
	print(author_books);

	system("pause");
	return 0;
}