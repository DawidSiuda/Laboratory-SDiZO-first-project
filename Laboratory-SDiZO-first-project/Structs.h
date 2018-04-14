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

struct NodeRB
{
	NodeRB(NodeRB *parent, int new_value, int color = RED);

	int value;
	int color;

	NodeRB *left;
	NodeRB *right;
	NodeRB *up;

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

inline NodeRB::NodeRB(NodeRB *parent, int new_value, int new_color)
{
	value = new_value;
	color = new_color;

	left = NULL;
	right = NULL;
	up = parent;

	length = 0;
}
