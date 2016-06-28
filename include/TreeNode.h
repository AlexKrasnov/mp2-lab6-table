#pragma once
#include <iostream>
#include "TabRecord.h"

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