#include<iostream>
#include<stdexcept>
#include<memory>
#include<vector>
#include<fstream>

using namespace std;

// ��һ��,try_catch����
//void expercise(int *b, int *e)
//{
//	vector<int> v(b, e);
//	int *p = new int[v.size()];
//	try
//	{
//		ifstream in("ints");
//		// �˴������쳣
//	}
//	catch (const std::exception&)
//	{
//		delete p;
//	}
//}

// �ڶ��֣�����һ����
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
	// �˴������쳣
}

int main()
{
	return 0;
}