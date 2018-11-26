#include<fstream>
#include<iostream>
#include<string>

using namespace std;

int main()
{
	fstream inOut("data\\mydata.txt", fstream::ate | fstream::in | fstream::out);
	if (!inOut)
	{
		cout << "文件不存在！" << endl;
	}
	auto end_mark = inOut.tellg();  // 读取当前文件的末尾
	inOut.seekg(0, fstream::beg);  // 移动到当前文件的开始
	size_t cnt = 0;
	string line;
	while (inOut && inOut.tellg() != end_mark && getline(inOut, line)) // 如果还没到文件末尾则读取一行
	{
		cnt += line.size() + 1; //+1表示换行符
		auto mark = inOut.tellg(); // 保留当前读取位置
		inOut.seekp(0, fstream::end);  // 将写的位置给移动到文件的末尾
		inOut << cnt;		// 写入
		if (mark != end_mark) // 如果还没到文件的结尾就添加上空格
		{
			inOut << " ";
		}
		inOut.seekg(mark); // 再次移动回之前的读取位置		
	}
	inOut.seekp(0, fstream::end); // 移动到文件的结尾
}