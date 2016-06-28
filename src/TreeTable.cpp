#include "TreeTable.h"

int TreeTable::isFull() const
{
	TreeNode *tmp = new TreeNode();
	int flag = tmp==NULL;
	delete tmp;
	return flag;
}

TabRecord* TreeTable::Find(TKey k)
{
	TreeNode* node = root;
	ref = &root;
	efficiency = 0;
	while (node != NULL)
	{
		efficiency++;
		if (node->key==k) break;
		if (node->key<k) ref = &node->right;
		else ref = &node->left;
		node = *ref;
	}
	if (node == NULL) return NULL;
	TabRecord* tmp = new TabRecord (node->key, node->data);
	return tmp;
}

void TreeTable::Ins(TKey k, TData *d)
{
	if (isFull()) return;
	if (Find(k) != NULL) 
	{
		TreeNode* node = *ref;
		node->data = d;
		return;
	}
	*ref = new TreeNode (k,d);
	count++;
	efficiency++;
}

void TreeTable::Del(TKey k)
{
	if (root==NULL) return;
	if (Find(k)!=NULL)
	{
		TreeNode *node = *ref;
		if ((*ref)->left != NULL || (*ref)->right != NULL)
		{
			if ((*ref)->left == NULL)
				*ref = (*ref)->right;
			else if ((*ref)->right == NULL)
				*ref = (*ref)->left;
			else
			{
				TreeNode **tmp = &((*ref)->left);
				node = *tmp;
				while ((*tmp)->right != NULL)
				{
					tmp = &((*tmp)->right);
					efficiency++;
					node = *tmp;
				}
				*tmp = (*tmp)->left;
			}
		}
		else
			*ref = NULL;
		delete node;
		count--;
	}
}

int TreeTable::Reset()
{
	TreeNode* node = cur = root;
	while (!st.empty()) st.pop();
	curpos = 0;
	while (node!=NULL)
	{
		st.push(node);
		cur = node;
		node = node->GetLeft();
	}
	return IsTabEnded();
}

int TreeTable::IsTabEnded()
{
	return curpos>=count;
}

int TreeTable::GoNext()
{
	if (cur != NULL)
	{
		pos++;
		cur = cur->right;
		while (cur != NULL)
		{
			st.push(cur);
			cur = cur->left;
		}
		if (!st.empty())
		{
			cur = st.top();
			st.pop();
		}
	}
	return IsTabEnded();
}

void TreeTable:: PrintTreeTab(TreeNode* node)
{
		if (node == NULL) return;
		cout << node->data << " ";
		PrintTreeTab(node->left);
		PrintTreeTab(node->right);
}