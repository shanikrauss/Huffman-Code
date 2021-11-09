#include "HuffmanBTree.h"
#include "Stack.h"
#include "HuffmanNode.h"

HuffmanBTree::HuffmanBTree()
{
	root = nullptr;
}

HuffmanBTree::HuffmanBTree(HuffmanNode* node) : root(node)
{}


HuffmanBTree::HuffmanBTree(const HuffmanBTree& other)
{
	root = new HuffmanNode;
	*this = other;
}



HuffmanBTree::~HuffmanBTree()
{
	if (root != nullptr)
	{
		delete root;
	}
	root = nullptr;
}


bool HuffmanBTree::setRoot(HuffmanNode* node)
{
	root = node;
	return true;
}

void HuffmanBTree::inorder()
{
	if (root != nullptr)
	{
		root->inorder();
	}
}


void HuffmanBTree::preorder()
{
	if (root != nullptr)
	{
		root->preorder();
	}
}


void HuffmanBTree::postorder()
{
	if (root != nullptr)
	{
		root->postorder();
	}
}

HuffmanNode* HuffmanBTree::getRoot()
{
	return this->root;
}


HuffmanBTree& HuffmanBTree::operator=(const HuffmanBTree& other)
{
	if (this != &other)
	{
		*(this->root) = *(other.root);
	}
	return*this;
}

//The method prints the binary codes of each key in Huffman tree
void HuffmanBTree::printCode()
{
	Stack stck;
	cout << "Character encoding :" << endl;
	if (root->isLeaf())
	{
		stck.push(1);
	}
	root->printCode(stck);
}


//The method get the Huffman tree weight 
int HuffmanBTree::getHuffmanWeight()
{
	int h = 0;
	if (root->isLeaf())
	{
		h = 1;
	}
	return(root->getHuffmanWeight(h));
}


//The method prints the Huffman tree weight 
void HuffmanBTree::printHuffmanWeight()
{
	cout << "Encoded file weight: " << getHuffmanWeight() << " bits" << endl;
}
