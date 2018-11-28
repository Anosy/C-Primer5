// 情况1
//namespace Exercise
//{
//	int ivar = 0;
//	double dvar = 0;
//	const int limit = 1000;
//}
//
//int ivar = 0;
//
////using Exercise::ivar; // 导致ival重复定义
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


// 情况2
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
//	//double dvar = 3.1416; // 导致dvar重复定义
//	int iboj = limit + 1; // Exercise::limit
//	++ivar; // Exercise::ivar
//	++::ivar; // 全局ivar
//
//	return 0;
//}


// 情况3
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
//	double dvar = 3.1416; // 屏蔽了外部的dvar
//	int iboj = limit + 1; // Exercise::limit
//	//++ivar; // 二义性
//	++::ivar; // 全局ival
//}


// 情况4
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
	double dvar = 3.1416;  // 屏蔽了Exercise::dvar
	int iboj = limit + 1;  // Exercise::limit
	//++ivar;   // 二义性
	++::ivar;  
}
