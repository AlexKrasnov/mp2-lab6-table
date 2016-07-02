#pragma once
#include "ScanTable.h"

class SortTable : public ScanTable
{
public:
	void SortData();
public:
	SortTable(int tabsize = TabMaxSize) : ScanTable(tabsize) {}
	SortTable(const ScanTable&);
	virtual TabRecord* Find (TKey);
	virtual void Ins (TKey, TData*);
	virtual void Del (TKey);
};