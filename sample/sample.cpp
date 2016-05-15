#include "ScanTable.h"

void main()
{
	try
	{
		ScanTable s(10);
		s.Ins(1,"111");
		s.Ins(2,"abc");
		s.Ins(2,"abc");
		s.Ins(3,"333333333");
		s.Ins(3,"5555");
		s.Ins(4,"ffffff");
		s.Ins(7,"00000000000");
		cout << s;
		s.Del(2);
		cout << s;
	}
	catch (const char* error)
	{
		cout<<error<<endl;
	}
}