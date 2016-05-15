#include "ScanTable.h"

ScanTable:: ScanTable(int size): Table(size)
{
	rec = new TabRecord*[size];
}

ScanTable:: ScanTable(const ScanTable& tab)
{
	size = tab.GetSize();
	count = tab.GetCount();
	pos = tab.GetCount();
	efficiency = tab.GetEfficiency();
	rec = new TabRecord*[size];
	for (int i=0; i<count; i++)
	{
		rec[i]=tab.rec[i];
	}
}

ScanTable::~ScanTable()
{
	delete[] rec;
}

TabRecord* ScanTable::Find(KeyType k)
{
	int i;
	for (i=0; i<count; i++)
		if (k==rec[i]->GetKey())
		{
			pos = i;
			return rec[i];
		}
	efficiency = i;
	return NULL;
}

void ScanTable::Ins(KeyType k, DataType* d)
{
	if (Find(k)!=NULL) 
	{
		TabRecord *tab = new TabRecord(k,d);
		rec[pos]=tab;
		return;
	}
	if (IsFull()) throw "tab full";
	rec[count++] = new TabRecord(k,d);
}

void ScanTable::Del(KeyType k)
{
	if (IsEmpty()) throw "tab empty";
	if (Find(k)!=NULL)
	{
		TabRecord *tab = Find(k);
		swap(rec[pos],rec[count-1]);
        delete rec[count-1];
		rec[count-1]=NULL;
		count--;
	}
}
