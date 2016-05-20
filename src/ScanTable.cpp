#include "ScanTable.h"

ScanTable:: ScanTable(int size): Table(size)
{
	rec = new TabRecord*[size];
}

ScanTable:: ScanTable(const ScanTable& tab)
{
	size = tab.size;
	count = tab.count;
	pos = tab.pos;
	efficiency = tab.efficiency;
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
		if (rec[i]->GetKey()==k)
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
		Find(k)->data = d;
		return;
	}
	if (!IsFull())
	{
		rec[count++] = new TabRecord(k, d);
		efficiency++;
	}
}

void ScanTable::Del(KeyType k)
{
	if (!IsEmpty()) 
	{ 
		if (Find(k) != NULL) 
		{ 
			delete rec[pos]; 
			rec[pos] = rec[--count]; 
			efficiency++;
		} 
	}
}
