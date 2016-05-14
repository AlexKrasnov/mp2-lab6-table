#pragma once
#include <iostream>
#include <locale>
#include "TabRecord.h"

using namespace std;

class Table : public TabRecord
{
protected:
	int size;        // ������
	int count;       // �-�� �������
	int pos;         // �������
	int efficiency;  // �������������
public:
	Table(): count(0), pos(0), efficiency(0) {}
	Table(int);
    // �������������� ������
	int GetSize() const;
	int GetCount() const;
	int GetPos() const;
	int GetEfficiency() const;
	bool IsEmpty(void) const;
	bool IsFull(void) const;
	// �������� ������
	virtual TabRecord Find (KeyType) = 0;
	virtual void Ins (KeyType, DataType*) = 0;
	virtual void Del (KeyType) = 0;
	// ���������
	virtual int Reset () = 0;
	virtual int IsTabEnded () const = 0;
	virtual int GoNext () = 0;
	// ������
	virtual KeyType GetKey() const = 0;
	virtual DataType* GetData() const = 0;
	// ������ ������� 
	friend ostream& operator<< (ostream &os, Table &tab)
	{
		setlocale(LC_ALL,"Rus");
		cout << "������ �������" <<endl;
		for (tab.Reset();tab.IsTabEnded(); tab.GoNext())
		{
			os << "����: " << tab.GetKey() 
			   << "������: " << tab.GetData(); os << endl;
		}
		return os;
	}
};