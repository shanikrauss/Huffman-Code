#pragma once
#include "BTreeNode.h"


class HuffmanNode : public BTreeNode
{
public:
	HuffmanNode(Pair item, BTreeNode* left = nullptr, BTreeNode* right = nullptr);
	HuffmanNode();
	virtual ~HuffmanNode() {};
	HuffmanNode(const HuffmanNode& other);

	virtual int getHuffmanWeight(int h);
	virtual void printCode(Stack& code);
};

