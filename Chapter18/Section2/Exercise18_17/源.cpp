// ���1
//namespace Exercise
//{
//	int ivar = 0;
//	double dvar = 0;
//	const int limit = 1000;
//}
//
//int ivar = 0;
//
////using Exercise::ivar; // ����ival�ظ�����
//using Exercise::dvar;
//using Exercise::limit;
//
//int main()
//{
//
//	double dvar = 3.1416; // Exercise::dvar
//	int iboj = limit + 1; // Exercise::limit
//	++ivar;
//	++::ivar;
//
//	return 0;
//}


// ���2
//namespace Exercise
//{
//	int ivar = 0;
//	double dvar = 0;
//	const int limit = 1000;
//}
//
//int ivar = 0;
//
//int main()
//{
//	using Exercise::ivar; 
//	using Exercise::dvar;
//	using Exercise::limit;
//
//	//double dvar = 3.1416; // ����dvar�ظ�����
//	int iboj = limit + 1; // Exercise::limit
//	++ivar; // Exercise::ivar
//	++::ivar; // ȫ��ivar
//
//	return 0;
//}


// ���3
//namespace Exercise
//{
//	int ivar = 0;
//	double dvar = 0;
//	const int limit = 1000;
//}
//
//int ivar = 0;
//using namespace Exercise;
//
//int main()
//{
//	double dvar = 3.1416; // �������ⲿ��dvar
//	int iboj = limit + 1; // Exercise::limit
//	//++ivar; // ������
//	++::ivar; // ȫ��ival
//}


// ���4
namespace Exercise
{
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}

int ivar = 0;

int main()
{
	using namespace Exercise;
	double dvar = 3.1416;  // ������Exercise::dvar
	int iboj = limit + 1;  // Exercise::limit
	//++ivar;   // ������
	++::ivar;  
}
