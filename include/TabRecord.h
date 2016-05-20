#pragma once
#include <iostream>
#include <locale>
typedef int KeyType;
typedef char DataType;

using namespace std;

class TabRecord
{
public:
	KeyType key;
	DataType *data;
	TabRecord(){};
	TabRecord(KeyType k,DataType* d) : key(k), data(d){};
	KeyType GetKey();
	DataType* GetData();
	TabRecord& operator=(const TabRecord&);
};