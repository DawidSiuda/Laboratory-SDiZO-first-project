#pragma once
#include "Structs.h"
#include "Flags.h"
#include "List.h"

#include <iostream>
#include <iomanip>	
#include <string>

using namespace std;

class Heap
{
public:
	void push(int element);
	void show();

	Heap();
	~Heap();

//private:

	Node *root;
	//int height;
private:
	//Node *get_new_parent();
	void increment_lenhgt_of_parents(Node *node);
};

