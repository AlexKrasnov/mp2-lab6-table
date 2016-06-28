#pragma once
#include <iostream>
#include <locale>
#include <string>

typedef std::string TKey;
typedef char TData;

using namespace std;

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