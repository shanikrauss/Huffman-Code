#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <string>
#include <ostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include "BSTree.h"
#include "HuffmanBTree.h"
#include "BTreeNode.h"
#include "PriorityQueue.h"
#include "HeapPairArray.h"
#include "HuffmanNode.h"


#define rcastcc reinterpret_cast<const char*>
#define rcastc reinterpret_cast<char*>

using namespace std;

//The function creates a binary search tree that the nodes are pairs of: 
// key: the char from the file
// data: the frequency of the char in the file
BSTree& createBSTreeFromFile(ifstream& file)
{
	BSTree* tree = new BSTree; 
	BTreeNode* node;
	char ch;
	
	file >> noskipws; // avoid skipping spaces
	file >> ch;
	while (!file.eof())
	{
		if (!file.good())
		{
			cout << "invalid input." << endl;
			file.close();
			exit(1);
		}
		node = tree->Find(ch); //finding the node that it's key is ch
		if (node) // if the node exists we update the frequency
		{
			node->addFrequency();
		}
		else // else we create the node by the ch
		{
			Pair p;
			p.ch = ch;
			p.frequency = 1;
			tree->Insert(p);
		}
	
		file >> ch;
	}
	return *tree;
}




template <class T>
void treeToArrRec(T& arr, BTreeNode* t)
{
	if (t->getLeft() != nullptr)
	{
		treeToArrRec(arr, t->getLeft());
	}

	HuffmanNode* newNode = new HuffmanNode(t->getVal()); // new leaf 218
	HeapPair newPair = { t->getData(), newNode };
	
	arr.add(newPair); //	arr.push_back(t->getVal());

	if (t->getRight() != nullptr)
	{
		treeToArrRec(arr, t->getRight());
	}
}


//The function uses Huffman's algorimthem, using the input binary search tree to create a Huffman's tree.
HuffmanBTree* Huffman(BSTree& t)
{
	int freq;
	HeapPairArray heapPairArr;
	if (t.getRoot() == nullptr)
	{
		return nullptr;
	}
	treeToArrRec(heapPairArr, t.getRoot()); // building the heap pair array

	PriorityQueue Q(heapPairArr.getArr(), heapPairArr.getLogSize());  //creating the Heap
	HuffmanNode* node;

	for (int i = 1; i < heapPairArr.getLogSize(); i++) //  building Huffman Tree accoring the arr
	{
		node = new HuffmanNode;
		node->setLeft(Q.deleteMin().t);
		node->setRight(Q.deleteMin().t);
		freq = node->getLeft()->getData() + node->getRight()->getData();
		node->addFrequency(freq);

		HeapPair hp = { freq, node };

		Q.insert(hp);
	}

	HuffmanBTree* res = new HuffmanBTree(Q.deleteMin().t);
	return res;
}


int main()
{
	string fileName;

	getline(cin, fileName); //getting file's name

	ifstream infile(fileName);
	if (!infile)
	{
		cout << "invalid input." << endl;
		exit(1);
	}

	BSTree& FreqBSTreeFromFile = createBSTreeFromFile(infile);

	HuffmanBTree* huffmanTree = Huffman(FreqBSTreeFromFile);
	if (huffmanTree != nullptr) //if file not empty
	{
		huffmanTree->printCode();
		huffmanTree->printHuffmanWeight();
	}

	delete& FreqBSTreeFromFile;
	delete huffmanTree;
	infile.close();
}