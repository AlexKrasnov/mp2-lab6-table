#include "TabRecord.h"

KeyType TabRecord::GetKey() const
{
	return this->key;
}

char* TabRecord::GetData() const
{
	return this->data;
}

TabRecord& TabRecord:: operator=(const TabRecord& tab)
{
	this->key=tab.GetKey();
	this->data=tab.GetData();
	return *this;
}