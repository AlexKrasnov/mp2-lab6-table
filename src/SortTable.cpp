#include "SortTable.h"
#include "Table.h"

SortTable::SortTable(const ScanTable& tab)
{
	size = tab.size;
	count = tab.count;
	pos = 0;
	rec = new TabRecord*[size];
	for (int i = 0; i < count; i++)
		rec[i] = new TabRecord(tab.rec[i]->GetKey(), tab.rec[i]->GetData());
	SortData();
}

TabRecord * SortTable::Find(TKey key)
{
	int i = 0, i1 = 0, i2 = count-1;
	efficiency = 0;
	TabRecord *rez = NULL;
	while (i1 <= i2) 
	{ 
		i = (i1 + i2) / 2; 
		if (rec[i]->key==key) 
		{ 
			i1 = i + 1;
			i2 = i; 
			rez = rec[i];
		} 
		else if (key > rec[i]->key) 
		{ 
			i1 = i + 1;
		}
		else
		{
			i2 = i-1; 
		} 
		efficiency++;
	} 
	pos = i; 
	return rez;
}


void SortTable::Ins(TKey k, TData *d)
{
	if (IsFull())
		return;
	Find(k);
	for (int i = count; i > pos; i--)
		rec[i] = rec[i - 1];
	count++;
	efficiency++;
	rec[pos] = new TabRecord(k, d);
	SortData();
}

void SortTable::Del(TKey k)
{
	if (!IsEmpty()) 
	{ 
		Find(k); 
		if (rec != NULL) 
		{ 
			delete rec[pos]; 
			for (int i = pos; i < count - 1; i++) 
			{ 
				rec[i] = rec[i + 1]; 
				efficiency++;
			} 
			count--; 
		} 
	}
}

void SortTable::SortData()
{
	for (int i = 0; i < count; i++)
		for (int j = i + 1; j < count; j++)
			if (rec[i]->GetKey() > rec[j]->GetKey())
				swap(rec[i],rec[j]);

}
