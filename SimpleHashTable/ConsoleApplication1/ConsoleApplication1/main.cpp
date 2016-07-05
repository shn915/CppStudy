#include "intHashTable.h";
#include <iostream>

int main() {
	intHashTable testHT;

	int *i1, *i2, *i3;

	i1 = new int;
	*i1 = 1;

	i2 = new int;
	*i2 = 2;

	i3 = new int;
	*i3 = 3;

	testHT.add(*i1, i1);
	testHT.add(*i2, i2);
	testHT.add(*i3, i3);

	int I;
	int *P;
	for (I = 0; I <= 2; ++I) {
		P = (int *)testHT.find(I + 1);
		std::cout << *P << std::endl;
		testHT.remove(I + 1);
		delete P;
	}

}