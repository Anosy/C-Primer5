// ��cpp��Ҫ���ܵ���vector�ĳ�ʼ������
#include<vector>
#include<string>
using std::vector;
using std::string;


int main()
{
	vector<int> v1; // v1��һ���յ�vector����Ǳ�ڵ�Ԫ����int�͵ģ�ִ��Ĭ�ϳ�ʼ��Ϊ0
	vector<string> v2 = { "a", "b", "c" }; // v2��string �͵�vector��ʹ�õ����б��ʼ��������"a", "b", "c"����Ԫ�أ�ע��ʹ�û�����{}
	vector<int> v3(10, -1); // v3�а���10��Ԫ�أ�ÿ��Ԫ�ض���-1
	vector<string> v4(10, "hi"); // v4����10��Ԫ�أ�ÿ��Ԫ�ض���"hi"
	vector<int> v5(10); // v5����10��Ԫ�أ�ÿ��Ԫ�ض���Ĭ�ϳ�ʼ��Ϊ0
	vector<string> v6(10); // v6����10��Ԫ�أ�ÿ��Ԫ�ض��ǿ��ַ���
	vector<int> v7{ 10 }; //v7����һ��Ԫ��,ֵΪ10
	// �������
	vector<string> v8{ 10, "hi" }; // ��Ȼ����ʹ�õ���{}�����ǲ���ʹ��intֵ����ʼ��string���󣬱�����Ĭ�Ͻ�����Ϊ()
}