#include "TabRecord.h"

KeyType TabRecord::GetKey()
{
	return key;
}

DataType* TabRecord::GetData()
{
	return data;
}

TabRecord& TabRecord:: operator=(const TabRecord& tab)
{
	key=tab.key;
	data=tab.data;
	return *this;
}