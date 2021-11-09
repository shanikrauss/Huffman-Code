#pragma once
#include <iostream>
#include "structs.h"
#include "Stack.h"
using namespace std;



class BTreeNode
{
protected:
	Pair value;
	BTreeNode* left, * right;
	BTreeNode* copyTreeNodeRec(BTreeNode* root);
	
public:

	BTreeNode();
	BTreeNode(Pair item, BTreeNode* left=nullptr, BTreeNode* right=nullptr);
	virtual ~BTreeNode();

	BTreeNode(const BTreeNode& other);

	Pair getVal()const;
	char getKey()const;
	int getData()const;
	BTreeNode* getLeft();
	BTreeNode* getRight();

	bool setLeft(BTreeNode* node);
	bool setRight(BTreeNode* node);
	bool setVal(Pair val);
	bool addFrequency(int i = 1);
	bool isLeaf();

	void inorder();
	void preorder();
	void postorder();
	friend ostream& operator<<(ostream& os, const BTreeNode& data);
	BTreeNode& operator=(const BTreeNode& other);

};
 
