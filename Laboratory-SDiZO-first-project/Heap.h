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
	void push(int value);
	void pop(int value);
	void show();
	bool find_value(int value);

	Heap();
	~Heap();

private:

	Node *root;
	Node *last_node;
	int number_of_elements;
	List<int> *path_to_last_node;

private:
	
	void change_values(Node *node1, Node *node2);

	void back_last_node();

	void set_node_in_tree(Node *const(node));

	void set_node_in_tree_reverse(Node *const(node));

	bool find_value(int value, Node *root);

	Node *find_pointer_to_value(int value, Node *root);
};

