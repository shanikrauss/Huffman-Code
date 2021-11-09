#include "HuffmanNode.h"


HuffmanNode::HuffmanNode(Pair item, BTreeNode* left, BTreeNode* right) : BTreeNode(item,left,right)
{
}


HuffmanNode::HuffmanNode() :BTreeNode({ '\0',0 }, nullptr, nullptr)
{}


HuffmanNode::HuffmanNode(const HuffmanNode& other) : BTreeNode(other)
{}




//The recursive method travel on the Huffman tree and calculate the binary code of each key.
//when we get to a leaf we print the  binary code of the key.
// int BTreeNode::getHuffmanWeight(int h)
int HuffmanNode::getHuffmanWeight(int h)
{
	int weightLeft = 0, weightRight = 0;

	if (isLeaf())
	{
		return(getData() * h);
	}
	if (left != nullptr)
	{
		HuffmanNode* tmp = dynamic_cast<HuffmanNode*>(left);
		weightLeft = tmp->getHuffmanWeight(h + 1);
	}

	if (right != nullptr)
	{
		HuffmanNode* tmp = dynamic_cast<HuffmanNode*>(right);
		weightRight = tmp->getHuffmanWeight(h + 1);
	}
	return (weightLeft + weightRight);
}


//The recursive method travel on the Huffman tree and calculate the binary code of each key.
//when we get to a leaf we print the  binary code of the key.
//void BTreeNode::printCode(Stack& code)
void HuffmanNode::printCode(Stack& code)
{
	char ch = '\0';

	if (isLeaf())
	{
		ch = getKey();
		if (ch == '\n') {
			cout << "'" << "\\n" << "'" << " - ";//printing special key
		}
		else if (ch == '\t') {
			cout << "'" << "\\t" << "'" << " - ";//printing special key
		}
		else {
			cout << "'" << ch << "'" << " - ";//printing not special key
		}
		code.print(); // printing key's binary code
		cout << endl;
		return;
	}
	if (left != nullptr)
	{
		code.push(0);
		dynamic_cast<HuffmanNode*>(left)->printCode(code);
	}
	code.pop();
	if (right != nullptr)
	{
		code.push(1);
		dynamic_cast<HuffmanNode*>(right)->printCode(code);
	}
	code.pop();
}