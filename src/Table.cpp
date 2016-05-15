#include "Table.h"

bool Table::IsEmpty() const
{
	if (count == 0) return true;
	return false;
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

int Table::Reset()
{
	pos = 0;
	return IsTabEnded();
}

int Table::IsTabEnded() const
{
	return pos>=count;
}

int Table::GoNext()
{
	if (!IsTabEnded()) pos++;
	return IsTabEnded();
}