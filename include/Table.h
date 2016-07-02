#pragma once
#include <iostream>
#include <locale>
#include <string>

using namespace std;

typedef std::string TKey;
typedef char TData;

#define TabMaxSize 100

struct TabRecord
{
	TKey key;      // ключ записи
	TData *data;   // указатель на значение
	TabRecord(TKey k="",TData* d=NULL) : key(k), data(d){}
	TKey GetKey() { return key; }
	TData* GetData() { return data; }
	TabRecord& operator=(const TabRecord &t) { key = t.key; data = t.data; return *this; }
	bool operator==(const TabRecord &t) const { return key==t.key && data == t.data; }
};

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
	bool IsEmpty() const { return count == 0; }
	bool IsFull() const { return count == size; }
	// основные методы
	virtual TabRecord* Find (TKey) = 0;
	virtual void Ins (TKey, TData*) = 0;
	virtual void Del (TKey) = 0;
	// навигация
	virtual int Reset () 
	{ 
		pos = 0;
		return IsTabEnded();
	}
	virtual int IsTabEnded () const { return pos>=count; }
	virtual int GoNext ()
	{
		if (!IsTabEnded()) pos++;
		return IsTabEnded();
	}
};