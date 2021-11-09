#include "BSTree.h"
#include "BTreeNode.h"
#include <iostream>
using namespace std;


BSTree::~BSTree()
{
	if (root != nullptr)
	{
		delete root;
	}
	root = nullptr;
}


BSTree::BSTree(const BSTree& other)
{
	root = new BTreeNode;
	*this = other;
}


bool BSTree::isEmpty() const
{
	if (root == nullptr)
	{
		return true;
	}
	return false;
}


void BSTree::makeEmpty()
{
	root = nullptr;
}



BTreeNode* BSTree::Find(char item)
{
	BTreeNode* tmp = root;
	while (tmp != nullptr)
	{
		if (item == (tmp->getVal()).ch)
		{
			return tmp;
		}
		else if (item < (tmp->getVal()).ch)
		{
			tmp = tmp->getLeft();
		}
		else
		{
			tmp = tmp->getRight();
		}
	}
	return nullptr;
}



void BSTree::Insert(Pair item)
{
	if (Find(item.ch) != nullptr)
	{
		cout << "The item already exist." << endl;
		return;
	}

	BTreeNode* tmp = root;
	BTreeNode* parent = nullptr;
	BTreeNode* newNode;

	while (tmp != nullptr) //find parent of new node
	{
		parent = tmp;
		if (item.ch < (tmp->getKey()))
		{
			tmp = tmp->getLeft();
		}
		else
		{
			tmp = tmp->getRight();
		}
	}

	newNode = new BTreeNode(item, nullptr, nullptr);
	if (parent == nullptr) //empty tree
	{
		root = newNode;
	}
	else if (item.ch < (parent->getKey()))
	{
		parent->setLeft(newNode);
	}
	else
	{
		parent->setRight(newNode);
	}
}


void BSTree::Delete(char item)
{
	bool found = false;
	BTreeNode* tmp1 = root;
	BTreeNode* tmp2 = nullptr;
	BTreeNode* parent = nullptr;
	BTreeNode* maxParent = nullptr;
	BTreeNode* save = nullptr;
	BTreeNode* max = nullptr;

	while (!found && tmp1 != nullptr) //find parent of tmp that need to be deleted
	{
		if (item == (tmp1->getKey()))
		{
			found = true;
		}
		else if (item < (tmp1->getKey()))
		{
			parent = tmp1;
			tmp1 = tmp1->getLeft();
		}
		else
		{
			parent = tmp1;
			tmp1 = tmp1->getRight();
		}
	}
	if(!found) //item doesn't exist in the tree
	{
		cout << "The item wasn't found." << endl;
	}
	else
	{
		if (tmp1 == root)
		{
			this->makeEmpty();
		}
		if ((tmp1->getLeft() == nullptr || tmp1->getRight() == nullptr)) // tmp has one child or no children at all
		{
			if (tmp1->getLeft() != nullptr)//saving tmp's child
			{
				save = tmp1->getLeft();
			}
			else
			{
				save = tmp1->getRight();
			}
			if (tmp1 == parent->getLeft()) //tmp is the left child
			{
				parent->setLeft(save);
			}
			else // tmp is the right child
			{
				parent->setRight(save);
			}
			delete tmp1;
		}
		else // tmp has two children
		{
			max = getMax(tmp1->getLeft());//item
			tmp1->setVal(max->getVal());
			tmp2 = tmp1->getLeft();

			found = false;
			while (!found && tmp2 != nullptr) //find maxParent of tmp2 that need to be deleted
			{
				if (max->getKey() == (tmp2->getKey()))
				{
					found = true;
				}
				else if (max->getKey()< (tmp2->getKey()))
				{
					maxParent = tmp2;
					tmp2 = tmp2->getLeft();
				}
				else
				{
					maxParent = tmp2;
					tmp2 = tmp2->getRight();
				}
			}

			if (tmp2->getLeft() != nullptr)//saving tmp2's child
			{
				save = tmp2->getLeft();
			}
			else
			{
				save = tmp2->getRight();
			}
			if (tmp2 == maxParent->getLeft()) //tmp2 is the left child of maxParent
			{
				maxParent->setLeft(save);
			}
			else //tmp2 is the right child of maxParent
			{
				maxParent->setRight(save);
			}
			delete tmp2;

		}
	}

}



BTreeNode* BSTree::getMin(BTreeNode* from)
{
	BTreeNode* tmp = from;
	BTreeNode* parent = nullptr;

	if (isEmpty())
	{
		return nullptr;
	}
	while (tmp != nullptr && tmp->getLeft())
	{
		parent = tmp;
		tmp = tmp->getLeft();
	}
	if (tmp == from)
	{
		return from;
	}
	return tmp;
}


BTreeNode* BSTree::getMax(BTreeNode* from)
{
	BTreeNode* tmp = from;
	BTreeNode* parent = nullptr;

	if (isEmpty())
	{
		return nullptr;
	}
	while (tmp != nullptr && tmp->getRight())
	{
		parent = tmp;
		tmp = tmp->getRight();
	}
	if (tmp == from)
	{
		return from;
	}
	return tmp;
}


//printing the tree in order
void BSTree::PrintTree()
{
	if (root != nullptr)
	{
		root->inorder();
	}
}


BTreeNode* BSTree::getRoot()
{
	return this->root;
}


BSTree& BSTree::operator=(const BSTree& other)
{
	if (this != &other)
	{
		*(this->root) = *(other.root);
	}
	return* this;
}

