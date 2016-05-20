#include "SortTable.h"

void main()
{
	try
	{
		ScanTable *tab = new ScanTable(5);
		tab->Ins(2,"222");
		tab->Ins(1,"111");
	    tab->Ins(3,"333");
		tab->Ins(3,"444");
		cout << *tab;
	}
	catch (const char* error)
	{
		cout<<error<<endl;
	}
}