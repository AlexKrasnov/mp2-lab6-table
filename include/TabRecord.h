#pragma once
#include <iostream>
#include <locale>
typedef int KeyType;
typedef char DataType;

using namespace std;

class TabRecord
{
protected:
	KeyType key;
	DataType *data;
public:
	TabRecord(){};
	TabRecord(KeyType k,DataType* d) : key(k), data(d){};
	KeyType GetKey() const;
	char* GetData() const;
	TabRecord& operator=(const TabRecord&);
};