#pragma once
#include <iostream>
#include <stack>
#include "Table.h"

using namespace std;

class TreeNode : public TabRecord
{
public:
	TreeNode *left, *right;
public:
	TreeNode(TKey k="", TData *d = NULL, TreeNode *l = NULL, TreeNode *r = NULL)
		: TabRecord(k,d), left(l), right(r) {}
	~TreeNode() {}
	TreeNode* GetLeft() const { return left; }
	TreeNode* GetRight() const { return right; }
	friend class TreeTable;
};

class TreeTable : public Table 
{
public:
	TreeNode* root;   // указатель на корень дерева
	TreeNode** ref;   // адрес указателя на вершину-результата в Find
	TreeNode* cur;    // указатель на текущую вершину
	int curpos;      // номер текущей вершины
	stack<TreeNode*> st;  // стек для итератора
	void PrintTreeTab (TreeNode* node);
public:
	TreeTable() : Table() { curpos = 0; root = cur = NULL; ref = NULL;}
	~TreeTable() {}
	virtual int isFull() const;
	//  основные методы
	virtual TabRecord* Find (TKey);
	virtual void Ins (TKey, TData*);
	virtual void Del (TKey);
	// навигация
	virtual int Reset ();
	virtual int IsTabEnded ();
	virtual int GoNext ();
	// печать таблицы
	friend ostream& operator<< (ostream &os, TreeTable &tab);
};
