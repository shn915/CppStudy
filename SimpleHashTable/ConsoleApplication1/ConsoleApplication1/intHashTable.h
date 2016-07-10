#pragma once
#include <cstring>
#include "hashCommon.h"

class intHashTable
{
private:
	hashNode **buffer;
	int count;
	int length;
	
	int keyOf(int key);
	hashNode *find(int key);
public:
	intHashTable(int Length = 256);
	~intHashTable();

	bool add(int key, void *Node);
	bool remove(int key);
	void *get(int key);
	void clear();
	bool modify(int key, void *Node);
};

