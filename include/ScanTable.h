#pragma once
#include "Table.h"

class ScanTable : public Table
{
protected:
	TabRecord **rec;
public:
	ScanTable(int size = TabMaxSize);
	ScanTable(const ScanTable&);
	virtual ~ScanTable();
	virtual TabRecord* Find (TKey);
	virtual void Ins (TKey, TData*);
	virtual void Del (TKey);
	friend ostream& operator<< (ostream &os, ScanTable &tab)
	{
		setlocale(LC_ALL,"Rus");
		os << "Печать таблицы: " <<endl;
		os<<"+----------------------------------------------------"<<endl;
		for (tab.Reset();!tab.IsTabEnded(); tab.GoNext())
		{
			os << "|\tКлюч: " << tab.rec[tab.pos]->GetKey() 
			   <<" Данные: " << tab.rec[tab.pos]->GetData(); os << endl;
		}
		os<<"+----------------------------------------------------"<<endl<<endl;
		return os;
	}
	friend class SortTable;
};