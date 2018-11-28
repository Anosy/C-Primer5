#include<iostream>
#include<stdexcept>
#include<memory>
#include<vector>
#include<fstream>

using namespace std;

// 第一种,try_catch方法
//void expercise(int *b, int *e)
//{
//	vector<int> v(b, e);
//	int *p = new int[v.size()];
//	try
//	{
//		ifstream in("ints");
//		// 此处发生异常
//	}
//	catch (const std::exception&)
//	{
//		delete p;
//	}
//}

// 第二种，定义一个类
class Resource 
{
public:
	Resource(size_t sz) :r(new int[sz]) {}
	~Resource()
	{ 
		if (r)
		{
			delete r;
		}
	}
private:
	int *r;
};

void expercise(int *b, int *e)
{
	vector<int> v(b, e);
	Resource p(v.size());
	ifstream in("ints");
	// 此处发生异常
}

int main()
{
	return 0;
}