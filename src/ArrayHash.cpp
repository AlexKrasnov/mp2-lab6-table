#include "ArrayHash.h"

ArrayHash::ArrayHash(int s, int step) : HashTable()
{
	rec = new TabRecord*[s];
	for (int i=0; i<s; i++)
	{
		rec[i] = NULL;
	}
	tabsize = s;
	hashstep = step;
	mark = new TabRecord (string(""),NULL);
}

ArrayHash::~ArrayHash()
{
	for (int i=0;i<tabsize;i++)
	{
		if (rec[i]!=NULL && rec[i]!=mark)
			delete rec[i];
	}
	delete []rec;
	delete mark;
}

TabRecord* ArrayHash::Find(TKey k)
{
	TabRecord* tmp = NULL;
	freepos = -1;
	efficiency = 0;
	pos = HashFunc(k) % tabsize;
	for (int i=0;i<tabsize;i++)
	{
		efficiency++;
		if (rec[pos]==NULL) break; // свободная строка - конец поиска
		else if ((rec[pos] == mark) && (freepos == -1)) // пустая строка - запоминаем первую
			freepos = pos;
		if (rec[pos]->key==k) // нашли ключ
		{
			tmp = rec[pos];
			break;
		}
		pos = GetNextPos(pos); // открытое перемешивание
	}
	if (freepos != -1)
		pos = freepos;
	return tmp;
}

void ArrayHash::Ins(TKey k, TData *d)
{
	if (IsFull()) return;
	if (Find(k)==NULL /*&& freepos != -1*/)
	{
		//pos = freepos;
		rec[pos] = new TabRecord(k, d);
		count++;
		efficiency++;
	}

	/*
	if (!IsFull() && Find(k) == NULL && freepos != -1)
	{
	pos = freepos; 
	rec[pos] = new TabRecord(k, d);
	count++; 
	efficiency++;
	}
	*/

}

void ArrayHash::Del(TKey k)
{
	if (Find(k) == NULL)
		return;
	delete rec[pos];
	rec[pos] = mark;
	efficiency++;
	count--;
	/*
	if (Find(k)!= NULL) 
	{ 
	delete rec[pos];
	rec[pos] = mark; 
	count--;
	efficiency++;
	}
	*/
}

int ArrayHash::Reset()
{
	/*
	pos = 0;
	while (pos < tabsize && (rec[pos]->GetKey() == "&" || rec[pos]->GetKey() == ""))
	pos++;
	return IsTabEnded();
	*/

	pos = 0; 
	while (!IsTabEnded()) 
	{ 
		if(rec[pos]!=NULL && rec[pos]!=mark) 
			break; 
		else pos++; 
	} 
	return IsTabEnded();

}

int ArrayHash::IsTabEnded()
{
	return count==tabsize;
}

int ArrayHash::GoNext()
{
	/*
	pos++;
	while (pos < tabsize && (rec[pos]->GetKey() == "&" || rec[pos]->GetKey() == ""))
	pos++;
	return IsTabEnded();
	*/

	if (!IsTabEnded()) 
	{ 
		while (++pos < tabsize) 
		{ 
			if (rec[pos]!=NULL && rec[pos]!=mark) 
				break;
		} 
	} 
	return IsTabEnded();

}

