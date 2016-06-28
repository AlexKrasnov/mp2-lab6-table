#pragma once
#include <iostream>
#include "Table.h"
#include "HashTable.h"

using namespace std;

class ArrayHashTable : public HashTable
{
protected:
	TabRecord **recs;
	int freepos;
	int hashstep;
	TabRecord *mark;
	int GetNextPos(int, int) const;
public:
	ArrayHashTable(int size, int hashstep) : HashTable(size)
	{
		this->hashstep = hashstep;
		recs = new TabRecord *[size];
		for (int i = 0; i < size; i++)
			recs[i] = 0;
		mark = new TabRecord(-1, 0);
	}
	virtual TabRecord* Find(KeyType);
	virtual void Ins(KeyType, DataType*);
	virtual void Del(KeyType);
	virtual int Reset();
	//virtual int IsTabEnded () const;
	virtual int GetNext();
	friend ostream& operator<< (ostream &os, ArrayHashTable &tab)
	{
		setlocale(LC_ALL,"Rus");
		os << "Печать таблицы: " <<endl;
		os<<"+----------------------------------------------------"<<endl;
		for (tab.Reset();!tab.IsTabEnded(); tab.GoNext())
		{
			os << "|\tКлюч: " << tab.recs[tab.pos]->GetKey() 
			   <<" Данные: " << tab.recs[tab.pos]->GetData(); os << endl;
		}
		os<<"+----------------------------------------------------"<<endl<<endl;
		return os;
	}
};