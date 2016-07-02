#pragma once
#include <iostream>
#include "Table.h"

using namespace std;

#define TabHashStep 5

class HashTable : public Table
{
protected:
	virtual unsigned long HashFunc(const TKey key);
public:
	HashTable():Table() {}
};

class ArrayHash : public HashTable
{
protected:
	TabRecord **rec;    // память для записей таблицы
	int tabsize;        // макс. возможное кол-во записей
	int freepos;        // первая своб. строка, обнаруженная при поиске
	int hashstep;       // шаг вторичного перемешивания
	TabRecord *mark;    // маркер для индикации строк с удалёнными записями
	// функция открытого перемешивания
	int GetNextPos(int pos) { return (pos + hashstep) % tabsize; } 
public:
	ArrayHash(int s = TabMaxSize, int step = TabHashStep);
	~ArrayHash();
	// информационное поле 
	virtual int isFull() const { return count>=tabsize; }
	// основные методы
	virtual TabRecord* Find(TKey);
	virtual void Ins(TKey, TData*);
	virtual void Del(TKey);
	// навигация
	virtual int Reset ();
	virtual int IsTabEnded ();
	virtual int GoNext ();
	friend ostream& operator<< (ostream &os, ArrayHash &tab)
	{
		setlocale(LC_ALL,"Rus");
		os << "Печать таблицы: " <<endl;
		os<<"+----------------------------------------------------"<<endl;
		for (tab.Reset();!tab.IsTabEnded(); tab.GoNext())
		{
			os << "|\tКлюч: " << tab.rec[tab.pos]->GetKey() 
			   <<" Данные: " << tab.rec[tab.pos]->GetData(); os << endl;
		}
		os<<"+----------------------------------------------------"<<endl<<endl;
		return os;
	}
};