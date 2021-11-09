#pragma once
#include "BTreeNode.h"

class HuffmanBTree
{
private:
	HuffmanNode* root;

public:
	HuffmanBTree();
	HuffmanBTree(HuffmanNode* node);
	~HuffmanBTree();
	HuffmanBTree(const HuffmanBTree& other);
	HuffmanNode* getRoot();
	bool setRoot(HuffmanNode* node);
	void inorder();
	void preorder();
	void postorder();
	HuffmanBTree& operator=(const HuffmanBTree& other);

	void printCode();
	int getHuffmanWeight();
	void printHuffmanWeight();
};

