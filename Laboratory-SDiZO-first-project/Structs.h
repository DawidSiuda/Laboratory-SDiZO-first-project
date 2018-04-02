#pragma once

#include "Flags.h"

struct Node
{
	Node(Node *parent, int new_value);

	int value;

	Node *left;
	Node *right;
	Node *up;

	unsigned int length;
 };

inline Node::Node(Node *parent, int new_value)
{
	value = new_value;

	left = NULL;
	right = NULL;
	up = parent;

	length = 0;
}