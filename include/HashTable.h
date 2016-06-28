#pragma once
#include <iostream>
#include "Table.h"

using namespace std;

class HashTable : public Table
{
protected:
	virtual unsigned long HashFunc(const TKey key);
public:
	HashTable():Table() {}
};