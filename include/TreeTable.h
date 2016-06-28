#pragma once
#include "TreeNode.h"
#include <stack>
#include "Table.h"

class TreeTable : public Table 
{
public:
	TreeNode* root;   // ��������� �� ������ ������
	TreeNode** ref;   // ����� ��������� �� �������-���������� � Find
	TreeNode* cur;    // ��������� �� ������� �������
	int curpos;      // ����� ������� �������
	stack<TreeNode*> st;  // ���� ��� ���������
	void PrintTreeTab (TreeNode* node);
public:
	TreeTable() : Table() { curpos = 0; root = cur = NULL; ref = NULL;}
	~TreeTable() {}
	virtual int isFull() const;
	//  �������� ������
	virtual TabRecord* Find (TKey);
	virtual void Ins (TKey, TData*);
	virtual void Del (TKey);
	// ���������
	virtual int Reset ();
	virtual int IsTabEnded ();
	virtual int GoNext ();
	// ������ �������
	friend ostream& operator<< (ostream &os, TreeTable &tab);

};
