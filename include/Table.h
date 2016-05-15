#pragma once
#include "TabRecord.h"

class Table : public TabRecord
{
protected:
	int size;        // ������
	int count;       // �-�� �������
	int pos;         // �������
	int efficiency;  // �������������
public:
	Table(int s =10): count(0), pos(0), efficiency(0), size(s){};
    // �������������� ������
	int GetSize() const;
	int GetCount() const;
	int GetPos() const;
	int GetEfficiency() const;
	bool IsEmpty(void) const;
	bool IsFull(void) const;
	// �������� ������
	virtual TabRecord* Find (KeyType) = 0;
	virtual void Ins (KeyType, DataType*) = 0;
	virtual void Del (KeyType) = 0;
	// ���������
	virtual int Reset ();
	virtual int IsTabEnded () const;
	virtual int GoNext ();
};