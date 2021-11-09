#include "PriorityQueue.h"


PriorityQueue::PriorityQueue(int max)
{
	data = new HeapPair[max];
	maxSize = max;
	heapSize = 0;
	allocated = 1;
}


PriorityQueue::PriorityQueue(HeapPair* A, int n)
{
	maxSize = n;
	heapSize = n;
	allocated = 0;
	data = A; 

	for (int i = n / 2 - 1; i >= 0; i--)
	{
		fixHeap(i);
	}
}


PriorityQueue::~PriorityQueue()
{
	if (allocated)
	{
		delete[] data;
	}
	data = nullptr;
}


int PriorityQueue::Left(int node)
{
	return (2 * node + 1);
}


int PriorityQueue::Right(int node)
{
	return (2 * node + 2);
}


int PriorityQueue::Parent(int node)
{
	return ((node - 1) / 2);
}


HeapPair PriorityQueue::min()
{
	return data[0];
}


HeapPair PriorityQueue::deleteMin()
{
	if (heapSize < 1)
	{
		cout << "Error, min doesn't exist." << endl;
		return{ '\0', nullptr };
	}
	HeapPair min = data[0];
	heapSize--;
	data[0] = data[heapSize];
	fixHeap(0);
	return min;
}


void PriorityQueue::insert(HeapPair item)
{
	if (heapSize == maxSize)// if data full
	{
		cout << "Error, the data array is full." << endl;
		return;
	}
	int i = heapSize;
	heapSize++;

	while (i > 0 && data[Parent(i)].priority > item.priority)
	{
		data[i] = data[Parent(i)];

		i = Parent(i);
	}
	data[i] = item;

}


void PriorityQueue::fixHeap(int node)
{
	int min;
	int left = Left(node);
	int right = Right(node);

	if (left<heapSize && data[left].priority<data[node].priority)
	{
		min = left;
	}
	else
	{
		min = node;
	}
	if (right<heapSize && data[right].priority<data[min].priority)
	{
		min = right;
	}

	//swaping between the node and the max
	if (min != node)
	{
		swap(node, min);
		fixHeap(min);
	}
}


void PriorityQueue::swap(int pl1, int pl2)
{
	HeapPair save = data[pl1];
	data[pl1] = data[pl2];
	data[pl2] = save;
}