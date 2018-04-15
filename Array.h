#pragma once
#include "Flags.h"

#include <iostream>
#include <iomanip>      /* std::setw */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

class Array
{
public:
	void show();
	bool empty();
	bool find(int value);

	void push_front(int value);
	void push_back(int value);
	void push_random_place(int value);
	void push_at(unsigned int index, int value);

	void pop_front();
	void pop_back();
	void pop_random_place();
	void pop_at(unsigned int index);

	Array();
	~Array();

private:
	int *first;
	int size;
};

