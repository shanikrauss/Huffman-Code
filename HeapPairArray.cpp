#include "HeapPairArray.h"


HeapPairArray::HeapPairArray() : arr(new HeapPair[1]), logSize(0), phySize(1)
{}


HeapPairArray::HeapPairArray(int size) : arr(new HeapPair[size]), logSize(0), phySize(size)
{}


HeapPairArray::~HeapPairArray()
{
	delete[] arr;
}


HeapPairArray::HeapPairArray(HeapPair* array, int length)
	: arr(new HeapPair[length]), logSize(length), phySize(length)
{
	for (int i = 0; i < length; i++)
	{
		arr[i] = array[i];
	}
}


HeapPairArray::HeapPairArray(const HeapPairArray& other) :
	HeapPairArray(other.arr, other.logSize)
{
}


HeapPairArray HeapPairArray::operator=(const HeapPairArray& other)
{
	delete[] this->arr;

	this->logSize = other.getLogSize();
	this->phySize = other.getPhySize();

	this->arr = new HeapPair[other.getPhySize()];

	for (int i = 0; i < logSize; i++)
	{
		arr[i] = other.arr[i];
	}
	return *this;
}


HeapPair HeapPairArray::getPair(int idx) const
{
	return arr[idx];
}


void HeapPairArray::set(int idx, HeapPair pair)
{
	arr[idx] = pair;
}


int HeapPairArray::getPhySize() const
{
	return phySize;
}


int HeapPairArray::getLogSize() const
{
	return logSize;
}


void HeapPairArray::resize(int size)
{
	HeapPair* tmp = new HeapPair[size];

	for (int i = 0; i < logSize; ++i)
	{
		tmp[i] = arr[i];
	}

	delete[] arr;

	arr = tmp;
	this->phySize = size;
}


void HeapPairArray::setLogSize(int size)
{
	resize(size);
}


void HeapPairArray::add(HeapPair pair)
{
	// resize array if needed
	if (logSize == phySize) {
		resize(phySize * 2 + 1);
	}

	// add new value
	arr[logSize] = pair;
	++logSize;
}


HeapPair* HeapPairArray::getArr()
{
	return this->arr;
}