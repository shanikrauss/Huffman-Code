#pragma once
#include "HuffmanBTree.h"
#include "structs.h"



class PriorityQueue
{
private:

	HeapPair* data;
	int maxSize;
	int heapSize;
	int allocated;
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void fixHeap(int node);
public:
	PriorityQueue(int max);
	PriorityQueue(HeapPair* A, int n);
	~PriorityQueue();

	HeapPair min();
	HeapPair deleteMin();
	void insert(HeapPair item);
	void swap(int pl1, int pl2);
};


