#pragma once
#include "ScanTable.h"

class SortTable : public ScanTable
{
public:
	void SortData();
public:
	SortTable(int tabsize = TabMaxSize) : ScanTable(tabsize){}
	SortTable(const ScanTable *);
	virtual TabRecord* Find (KeyType);
	virtual void Ins (KeyType, DataType*);
	virtual void Del (KeyType);
};