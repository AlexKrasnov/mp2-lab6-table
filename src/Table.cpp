#include "Table.h"

bool Table::IsEmpty() const
{
	if (count == 0) return false;
	return true;
}

bool Table::IsFull() const
{
	if (count == size) return true;
	return false;
}

int Table::GetCount() const
{
	return count;
}

int Table::GetPos() const
{
	return pos;
}

int Table::GetSize() const
{
	return size;
}

int Table::GetEfficiency() const
{
	return efficiency;
}