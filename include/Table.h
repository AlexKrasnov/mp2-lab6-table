#pragma once
#include "TabRecord.h"

#define TabMaxSize 100

class Table
{
protected:
	int size;        // размер
	int count;       // к-во записей
	int pos;         // позиция
	int efficiency;  // эффективность
public:
	Table(int s = TabMaxSize): count(0), pos(0), efficiency(0), size(s) {}
	virtual ~Table() {}
    // информационные методы
	bool IsEmpty() const;
	bool IsFull() const;
	// основные методы
	virtual TabRecord* Find (TKey) = 0;
	virtual void Ins (TKey, TData*) = 0;
	virtual void Del (TKey) = 0;
	// навигация
	virtual int Reset ();
	virtual int IsTabEnded () const;
	virtual int GoNext ();
};