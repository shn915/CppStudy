#include "intHashTable.h"





int intHashTable::keyOf(int key)
{
	return key % length;
}

hashNode * intHashTable::find(int key)
{
	int idx, beginIdx;
	beginIdx = keyOf(key);
	idx = beginIdx;
	while (buffer[idx] != nullptr) {
		//key equal, return item
		if (buffer[idx]->key = key) {
			return buffer[idx];
		} else {
			++idx;
			//circulation
			if (idx == length) {
				idx = 0;
			}

			//run to begin, exit
			if (idx == beginIdx)
				break;
		}
	}
	return nullptr;

}

intHashTable::intHashTable(int length)
{
	this->length = length;
	buffer = new hashNode*[length];
	//init buffer pointer null
	memset(buffer, 0, sizeof(hashNode*) * length);
	count = 0;
}


intHashTable::~intHashTable()
{
	clear();
	delete[] buffer;
}

bool intHashTable::add(int key, void * Node)
{
	int idx, beginIdx;
	beginIdx = keyOf(key);
	idx = beginIdx;
	hashNode *P = new hashNode;
	P->key = key;
	P->Value = Node;
	while (buffer[idx] != nullptr) 
	{
		if (buffer[idx]->key == key) 
		{
			//Exist key, return
			delete P;
			return false;
		}

		++idx;
		if (idx == length) 
		{
			//circulation buffer
			idx = 0;
		}

		if (idx == beginIdx) 
		{
			//run to begin, clear memory and exit
			delete P;
			return false;
		}
	}
	buffer[idx] = P;

	++count;
	return false;
}

bool intHashTable::remove(int key)
{
	int idx, beginIdx;
	beginIdx = keyOf(key);
	idx = beginIdx;
	while (buffer[idx] != nullptr)
	{
		if (buffer[idx]->key == key)
		{
			delete buffer[idx];
			buffer[idx] = nullptr;
			--count;
			return true;
		}
		else
		{
			++idx;

			if (idx == length)
			{
				//circulation buffer
				idx = 0;
			}

			if (idx == beginIdx)
			{
				//run to begin, exit
				return false;
			}
		}
	}
	return false;
}

void *intHashTable::get(int key)
{
	hashNode *node;
	node = find(key);
	if (node != nullptr)
	{
		return node->Value;
	} 
	else 
	{
		return nullptr;
	}
}

void intHashTable::clear()
{
	int i;
	hashNode *node;
	for (i = 0; i < length; ++i) 
	{
		node = buffer[i];
		if (node != nullptr) 
		{
			delete node;
			buffer[i] = nullptr;
		}
	}
	count = 0;
}

bool intHashTable::modify(int key, void * Node)
{
	hashNode *P;
	P = find(key);
	if (P != nullptr)
	{
		P->Value = Node;
		return true;
	}
	return false;
}
