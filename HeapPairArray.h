#pragma once
#include "structs.h"


class HeapPairArray
{
private:
	HeapPair* arr;
	int logSize;
	int phySize;
	void resize(int size); 
	HeapPairArray(HeapPair* array, int length);

public:

	HeapPairArray();
	~HeapPairArray();
	HeapPairArray(int size);
	HeapPairArray(const HeapPairArray&);

	HeapPair getPair(int idx) const;
	HeapPair* getArr();
	void setLogSize(int size);
	int getPhySize() const;
	int getLogSize() const;

	void add(HeapPair pair);
	void set(int idx, HeapPair pair);
	HeapPairArray operator=(const HeapPairArray&);
};

