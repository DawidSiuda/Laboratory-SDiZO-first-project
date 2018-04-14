#pragma once

#include "Structs.h"
#include "Flags.h"
#include "List.h"

#include <iostream>
#include <iomanip>	
#include <string>
#include <Windows.h>

using namespace std;

class TreeRB
{
public:
	void push(int value);
	void pop(int value);
	void show();
	bool find(int value);

	TreeRB();
	~TreeRB();

private:

	NodeRB *root;
	//NodeRB *last_node;
	NodeRB *nil;

	int number_of_elements;

	List<int> *path_to_last_node;

	HANDLE  hConsole;

	

private:

	int set_value_in_tree(NodeRB *node);

	int set_color_in_tree(NodeRB *new_node);
	
	int rr(NodeRB *root);
	int rl(NodeRB *root);
	int lr(NodeRB *root);
	int ll(NodeRB *root);

	int check_direction(NodeRB *root);


	//void change_values(NodeRB *node1, Node *node2);
	//void back_last_node();
	//void set_node_in_tree(Node *const(node));
	//void set_node_in_tree_reverse(Node *const(node));
	//bool find_value(int value, Node *root);
	//Node *find_pointer_to_value(int value, Node *root);
};

