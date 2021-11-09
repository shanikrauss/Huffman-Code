#include "Stack.h"

void Stack::makeEmpty()
{
	lst.clear();
}


bool Stack::isEmpty() const
{
	return lst.empty();
}


void Stack::push(int bit)
{
	lst.push_front(bit);
}


int Stack::pop()
{
	int val = lst.front();
	lst.pop_front();
	return(val);
}


//The method prints the stack in reverse
void Stack::print()
{
	Stack tmp;
	int size = lst.size();
	for (int i = 0; i < size; i++)
	{
		tmp.push(pop()); //coping the stack in reverse to the tmp stack
	}

	for (int i = 0; i < size; i++)
	{
		int bit = tmp.pop();
		cout << bit; // printing the tmp stack , bit by bit
		push(bit); // pushing the bits back to the original stack
	}
}