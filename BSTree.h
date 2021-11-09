#pragma once
#include "BTreeNode.h"

class BSTree
{
private:
	BTreeNode* root;

public:
	BSTree():root(nullptr) {}
	~BSTree();
	BSTree(const BSTree& other);

	BTreeNode* getMin(BTreeNode* from);
	BTreeNode* getMax(BTreeNode* from);
	bool isEmpty() const;
	void makeEmpty();
	BTreeNode* Find(char item);
	void Insert(Pair item);
	void Delete(char item);
	void PrintTree();

	BTreeNode* getRoot();
	BSTree& operator=(const BSTree& other);
};
