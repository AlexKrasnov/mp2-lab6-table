#pragma once
#include <iostream>
#include "Table.h"
#include "HashTable.h"

using namespace std;

#define TabHashStep 5

class ArrayHash : public HashTable
{
protected:
	TabRecord **rec;    // ������ ��� ������� �������
	int tabsize;        // ����. ��������� ���-�� �������
	int freepos;        // ������ ����. ������, ������������ ��� ������
	int hashstep;       // ��� ���������� �������������
	TabRecord *mark;    // ������ ��� ��������� ����� � ��������� ��������
	// ������� ��������� �������������
	int GetNextPos(int pos) { return (pos + hashstep) % tabsize; } 
public:
	ArrayHash(int s = TabMaxSize, int step = TabHashStep);
	~ArrayHash();
	// �������������� ���� 
	virtual int isFull() const { return count>=tabsize; }
	// �������� ������
	virtual TabRecord* Find(TKey);
	virtual void Ins(TKey, TData*);
	virtual void Del(TKey);
	// ���������
	virtual int Reset ();
	virtual int IsTabEnded ();
	virtual int GoNext ();
	friend ostream& operator<< (ostream &os, ArrayHash &tab)
	{
		setlocale(LC_ALL,"Rus");
		os << "������ �������: " <<endl;
		os<<"+----------------------------------------------------"<<endl;
		for (tab.Reset();!tab.IsTabEnded(); tab.GoNext())
		{
			os << "|\t����: " << tab.rec[tab.pos]->GetKey() 
			   <<" ������: " << tab.rec[tab.pos]->GetData(); os << endl;
		}
		os<<"+----------------------------------------------------"<<endl<<endl;
		return os;
	}
};