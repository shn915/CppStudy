#include "intHashTable.h"





int intHashTable::keyOf(int key)
{
	return key % length;
}

intHashTable::intHashTable(int length)
{
	this->length = length;
	buffer = new hashNode*[length];
	count = 0;
}


intHashTable::~intHashTable()
{
	delete[] buffer;
}

bool intHashTable::add(int key, void * Node)
{
	int idx;
	idx = keyOf(key);
	hashNode *P = new hashNode;
	P->key = key;
	P->Value = Node;
	buffer[idx] = P;
	++count;
	return false;
}

bool intHashTable::remove(int key)
{
	int idx;
	idx = keyOf(key);
	if (buffer[idx] != nullptr) {
		//delete buffer[idx]->Value;
		delete buffer[idx];
		buffer[idx] = nullptr;
		--count;
		return true;
	}
	return false;
}

void *intHashTable::find(int key)
{
	int idx;
	idx = keyOf(key);
	if (buffer[idx] != nullptr) {
		return buffer[idx]->Value;
	}
	return nullptr;
}
