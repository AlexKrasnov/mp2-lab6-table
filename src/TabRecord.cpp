#include "TabRecord.h"

TabRecord::TabRecord(KeyType _key, DataType* _data)
{
	key=_key;
	data=_data;
}

KeyType TabRecord::GetKey() const
{
	return key;
}

DataType* TabRecord::GetData() const
{
	return data;
}

TabRecord& TabRecord:: operator=(const TabRecord& tab)
{
	key=tab.GetKey();
	data=tab.GetData();
	return *this;
}

bool TabRecord:: operator==(const TabRecord& tab) const
{
	return key==tab.GetKey();
}

bool TabRecord:: operator!=(const TabRecord& tab) const
{
	return key!=tab.GetKey();
}

bool TabRecord:: operator>=(const TabRecord& tab) const
{
	return key>=tab.GetKey();
}

bool TabRecord:: operator<=(const TabRecord& tab) const
{
	return key<=tab.GetKey();
}

bool TabRecord:: operator>(const TabRecord& tab) const
{
	return key>tab.GetKey();
}

bool TabRecord:: operator<(const TabRecord& tab) const
{
	return key<tab.GetKey();
}