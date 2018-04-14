#pragma once
#include "List.h"

#include <iostream>
#include <iomanip>	
#include <string>

using namespace std;

class Heap
{
public:
	void push(int value);
	int  pop(int value);
	void show();
	bool find(int value);

	Heap();
	~Heap();

private:
	void set_tree(int index);
	void revers_set_tree(int index);
	void replace(int index1, int index2);

	int *arrayHeap;
	int size;

};

