
#include "BTreeNode.h"



BTreeNode::BTreeNode(Pair item, BTreeNode* left, BTreeNode* right)
{
	this->value = item;
	this->left = left;
	this->right = right;
}


BTreeNode::BTreeNode() :BTreeNode({ '\0',0 }, nullptr, nullptr) // ?value
{}


BTreeNode::~BTreeNode()
{
	if (left != nullptr)
	{
		delete left;
	}
	if (right != nullptr)
	{
		delete right;
	}
}

BTreeNode::BTreeNode(const BTreeNode& other)
{

	*this = other;
}


Pair BTreeNode::getVal() const
{
	return value;
}


char BTreeNode::getKey()const
{
	return getVal().ch;
}


int BTreeNode::getData()const
{
	return getVal().frequency;
}


BTreeNode* BTreeNode::getLeft()
{
	return left;
}


BTreeNode* BTreeNode::getRight()
{
	return right;
}


bool BTreeNode::setLeft(BTreeNode* node)
{
	this->left = node;
	return true;
}


bool BTreeNode::setRight(BTreeNode* node)
{
	this->right = node;
	return true;
}


bool BTreeNode::setVal(Pair val)
{
	this->value = val;
	return true;
}


bool BTreeNode::addFrequency(int i)
{
	this->value.frequency += i;
	return true;
}


bool BTreeNode::isLeaf()
{
	return (left == nullptr && right == nullptr);
}


void BTreeNode::inorder()
{
	if (left != nullptr)
	{
		left->inorder();
	}
	
	cout << "(" << this->value.ch << "," << this->value.frequency << ")" << endl;
	if (right != nullptr)
	{
		right->inorder();
	}
}


void BTreeNode::preorder()
{
	cout << this;
	if (left != nullptr)
	{
		left->preorder();
	}
	if (right != nullptr)
	{
		right->preorder();
	}
}


void BTreeNode::postorder()
{
	if (left != nullptr)
	{
		left->postorder();
	}
	if (right != nullptr)
	{
		right->postorder();
	}
	
	cout << this;
}


ostream& operator<<(ostream& os, const BTreeNode& node)
{
	os << node.value.ch << ' ' << node.value.frequency << endl;
	return os;
}


 BTreeNode& BTreeNode::operator=(const BTreeNode& other)
{
	 if (this != &other)
	 {
		if (this->left != nullptr)
		{
			delete left;
		}
		if (this->right != nullptr)
		{
			delete right;
		}
		
		 this->left = copyTreeNodeRec(other.left);

		 this->right = copyTreeNodeRec(other.right);

		 this->value = other.value;
	 }
	 return *this;
}


 //The recursive method allocates and copy the node
 BTreeNode* BTreeNode::copyTreeNodeRec(BTreeNode* root)
 {
	 if (root == nullptr)
	 {
		 return nullptr;
	 }
	 else
	 {
		 BTreeNode* newNode = new BTreeNode;
		 newNode->left= copyTreeNodeRec(root->left);
		 
		 newNode->right= copyTreeNodeRec(root->right);

		 newNode->value = root->value;

		 return newNode;
	 }
 }


