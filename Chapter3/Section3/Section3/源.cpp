// 本cpp主要介绍的是vector的初始化问题
#include<vector>
#include<string>
using std::vector;
using std::string;


int main()
{
	vector<int> v1; // v1是一个空的vector，它潜在的元素是int型的，执行默认初始化为0
	vector<string> v2 = { "a", "b", "c" }; // v2是string 型的vector，使用的是列表初始化，包含"a", "b", "c"三个元素；注意使用花括号{}
	vector<int> v3(10, -1); // v3中包含10个元素，每个元素都是-1
	vector<string> v4(10, "hi"); // v4包含10个元素，每个元素都是"hi"
	vector<int> v5(10); // v5包含10个元素，每个元素都是默认初始化为0
	vector<string> v6(10); // v6包含10个元素，每个元素都是空字符串
	vector<int> v7{ 10 }; //v7包含一个元素,值为10
	// 特殊情况
	vector<string> v8{ 10, "hi" }; // 虽然这里使用的是{}，但是不能使用int值来初始化string对象，编译器默认将其视为()
}