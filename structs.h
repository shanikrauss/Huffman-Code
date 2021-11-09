#pragma once
class HuffmanNode;

struct Pair {
	char ch;//key
	int frequency;//data
}; 

struct HeapPair {
	int priority; //key
	HuffmanNode* t; //data
};
