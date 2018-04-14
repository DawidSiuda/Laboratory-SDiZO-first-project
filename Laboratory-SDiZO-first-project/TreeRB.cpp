#include "TreeRB.h"

void TreeRB::push(int value)
{
	if (root == NULL)
	{
		root = new NodeRB(NULL, value, BLACK);
		root->left = NULL;
		root->right = NULL;

		return;
	}

	NodeRB *node = new NodeRB(NULL, value, RED);

	if (set_value_in_tree(node) != 0)
	{
		return;
	}

	cout << " set color rtturned: "<< set_color_in_tree(node)<<endl;

}

void TreeRB::pop(int value)
{
}

void TreeRB::show()
{
	#ifdef LOG_TRE
	cout << "treeRB --> show_heap() has been called" << endl << endl;
	#endif // LOG_TRE

	if (root == NULL)
	{
		#ifdef LOG_TRE
		cout << "LOG: treeRB: can't draw empty tree" << endl;
		#endif //LOG_TRE

		return;
	}

	char next_arrow[] = { 196,194,196,196,196,196,196,196,196,196,0 };
	char pipe[] = { 32,32,32,32,32,32,179, 32, 32, 32,0 };
	char turn[] = { 32,32,32,32,32,32,192,196,196,196,0 };
	char line[] = { 196,196,196,196,196,196,196,196,196,0 };

	int hight = root->length;
	int level = hight;
	int direction = LEFT;

	int *tab_of_pipes = new int[hight];

	List<int>  stack_of_direction;

	NodeRB *current_node = root;
	NodeRB *last_parent = NULL;

	bool end_main_loop = false;

	//set table of positions to draw pipes on console 
	for (int i = 0; i <hight; i++)
	{
		//tab_of_pipes[i] = 0;
	}

	if (current_node == NULL)
	{
		#ifdef LOG_TRE
		cout << "LOG: treeRB: can't draw empty tree" << endl;
		#endif //LOG_TRE

		return;
	}

	while (end_main_loop == false)
	{
		//////////////////////////////////////////////
		//draw branch 
		for (int i = 0; i < stack_of_direction.get_size(); i++)
		{

			if (stack_of_direction.get_value_at(i) == LEFT)
			{
				cout << pipe;
			}
			else
				if (stack_of_direction.get_value_at(i) == RIGHT)
				{
					cout << "          ";
				}
		}

		while (true)
		{
			//go to next value "on the same level in console"
			//if it's not a root
			if (last_parent != NULL)
			{
				if (direction == LEFT)
				{
					last_parent = current_node;
					current_node = current_node->left;
					stack_of_direction.push_back(LEFT);
					level--;
				}
				else
					if (direction == RIGHT)
					{
						last_parent = current_node;
						current_node = current_node->right;
						stack_of_direction.push_back(RIGHT);
						level--;
						direction = LEFT;
					}

			}

			//if it's end let's do something
			if (current_node == NULL)
			{
				//
				//check exit
				//

				for (int i = 0; i < stack_of_direction.get_size(); i++)
				{
					if (stack_of_direction.get_value_at(i) == LEFT)
					{
						break;
					}

					if (i == stack_of_direction.get_size() - 1)
					{
						delete[] tab_of_pipes;

						end_main_loop = true;
					}
				}

				//
				//check direction of branch
				//

				if (stack_of_direction.top() == LEFT)
				{
					cout << " nil";
				}
				else
					if (stack_of_direction.top() == RIGHT)
					{
						cout << turn << " nil";
					}

				current_node = last_parent;
				level++;
				direction = stack_of_direction.top();
				stack_of_direction.pop_back();

				if (direction == LEFT)
				{
					direction = RIGHT;
				}
				else
					if (direction == RIGHT)
					{
						current_node = current_node->up;
						level++;
						direction = stack_of_direction.top();
						stack_of_direction.pop_back();

						while (direction == RIGHT)
						{
							current_node = current_node->up;
							level++;
							direction = stack_of_direction.top();
							stack_of_direction.pop_back();
						}
						direction = RIGHT;
					}

				break;
			}
			else
			{
				//draw branch
				if (stack_of_direction.top() == LEFT)
				{
					if (current_node->color == RED)
					{
						string node_as_string = to_string(current_node->value);

						cout << " ";

						SetConsoleTextAttribute(hConsole, 79);

						cout << node_as_string;

						SetConsoleTextAttribute(hConsole, 15);
						cout << " ";

						int temp_lenght = node_as_string.length() + 2;

						temp_lenght = 5 - temp_lenght;
						for (int i = temp_lenght; i > 0; i--)
						{
							cout << static_cast<char>(196);
						}

						node_as_string = next_arrow;
						node_as_string = node_as_string.substr(0, 5);
						cout << node_as_string;
					}else
					if (current_node->color == BLACK)
					{
						string node_as_string = to_string(current_node->value) + " " + line;
						node_as_string = node_as_string.substr(0, 4);

						node_as_string = " " + node_as_string + next_arrow;
						node_as_string = node_as_string.substr(0, 10);
						cout << node_as_string;
					}
					else
					{
						#ifdef LOG_TRE
						cout << "LOG: treeRB: can't draw unknown color" << endl;
						#endif //LOG_TRE
					}
				}
				else
				if (stack_of_direction.top() == RIGHT)
				{
					if (current_node->color == RED)
					{
						cout << turn;

						string node_as_string = to_string(current_node->value);

						cout << " ";

						SetConsoleTextAttribute(hConsole, 79);

						cout << node_as_string;

						SetConsoleTextAttribute(hConsole, 15);

						cout << " ";

						int temp_lenght = node_as_string.length() + 2;

						temp_lenght = 5 - temp_lenght;
						for (int i = temp_lenght; i > 0; i--)
						{
							cout << static_cast<char>(196);
						}

						node_as_string = next_arrow;

						node_as_string = node_as_string.substr(0, 5);

						cout << node_as_string;
					}
					else
					if (current_node->color == BLACK)
					{
						cout << turn;

						string node_as_string = to_string(current_node->value) + " " + line;

						node_as_string = node_as_string.substr(0, 4);

						node_as_string = " " + node_as_string + next_arrow;

						node_as_string = node_as_string.substr(0, 10);

						cout << node_as_string;
					}
				}
			}

			//to do if current_node is root
			if (last_parent == NULL)
			{
				last_parent = current_node;
			}
		}

		cout << endl;

		//
		//draw empty spaces betwen branch
		//

		for (int i = 0; i < stack_of_direction.get_size(); i++)
		{

			if (stack_of_direction.get_value_at(i) == LEFT)
			{
				cout << pipe;
			}
			else
				if (stack_of_direction.get_value_at(i) == RIGHT)
				{
					cout << "          ";
				}
		}
		if (end_main_loop == false)
		{
			cout << pipe << endl;
		}
	}
	cout << endl;

	return;
}

bool TreeRB::find(int value)
{
	return false;
}

TreeRB::TreeRB()
{
	root      = NULL;

	number_of_elements = 0;

	nil = new NodeRB(NULL, 0, BLACK);

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	FlushConsoleInputBuffer(hConsole);

}


TreeRB::~TreeRB()
{
}

int TreeRB::set_value_in_tree(NodeRB *node)
{
	NodeRB *current_node = root;
	NodeRB *last_node = NULL;
	int last_direction = -1;

	while(true)
	{
		//std::cout << " petla" << endl;
		if (current_node == NULL)
		{
			if (last_node != NULL)
			{
				if (last_direction == LEFT)
				{
					node->up = last_node;

					last_node->left = node;

					node->left = NULL;
					node->right = NULL;
				}

				if (last_direction == RIGHT)
				{
					node->up = last_node;

					last_node->right = node;

					node->left = NULL;
					node->right = NULL;
				}
				
			}
			else
			{
				if (root != NULL)
				{
					#ifdef LOG_TRE
					std::cout << "ERROR: can't add second root to treeRB" <<endl;
					#endif
					return 1;
				}
				
				root = node;
				node->left = NULL;
				node->right = NULL;
			}

			return 0;
		}

		if (current_node->value == node->value)
		{
			#ifdef LOG_TRE
			std::cout << "ERROR: can't add existing value to treeRB"<<endl;
			#endif
			return 1;
		}
		
		if (current_node->value > node->value)
		{
			last_node = current_node;

			current_node = current_node->left;

			last_direction = LEFT;
		}else
		if (current_node->value < node->value)
		{
			last_node = current_node;

			current_node = current_node->right;

			last_direction = RIGHT;
		}
	}

	return 0;
}

int TreeRB::set_color_in_tree(NodeRB *new_node)
{
	if (new_node == root)
	{
		if (new_node->color != BLACK)
		{
			new_node->color = BLACK;
		}

		return 0;
	}

	if (new_node->up == NULL)
	{
		#ifdef LOG_TRE
		cout << "treeRB --> ERROR code 21 value: " << new_node->value << endl;
		#endif // LOG_TRE

		return -1;
	}

	if (new_node->color != RED)
	{
		#ifdef LOG_TRE
		cout << "treeRB --> ERROR code 22 value: " << new_node->value << endl;
		#endif // LOG_TRE

		return 1;
	}

	int my_direction = -1;

	if (new_node->up->left == new_node)
	{
		my_direction = LEFT;
	}
	else
		if (new_node->up->right == new_node)
		{
			my_direction = RIGHT;
		}
		else
		{
			#ifdef LOG_TRE
			cout << "treeRB --> ERROR code 23 value: " << new_node->value << endl;
			#endif // LOG_TRE
			return -1;
		}

	//
	//wher father are BLACK
	//

	if (new_node->up->color == BLACK)
	{
		#ifdef LOG_TRE
		cout << "treeRB --> ERROR code 24 value: " << new_node->value << endl;
		#endif // LOG_TRE

		return 0;
	}

	//
	//wher father and a uncle are RED 
	//

	if (new_node->up->color == RED)
	if (my_direction == LEFT)
	if (check_direction(new_node->up) != -1)
	if (check_direction(new_node->up) == RIGHT)
	{
		if (new_node->up->up->left->color == RED)
		{
			new_node->up->color = BLACK;
			new_node->up->up->color = RED;
			new_node->up->up->left->color = BLACK;

			root->color = BLACK;

			#ifdef LOG_TRE
			cout << "treeRB --> LOG code 31 value: " << new_node->value << endl;
			#endif // LOG_TRE

			return 0;
		}
	}
	else
	if (check_direction(new_node->up) == LEFT)
	{
		if (new_node->up->up->right->color == RED)
		{
			new_node->up->color = BLACK;
			new_node->up->up->color = RED;
			new_node->up->up->right->color = BLACK;

			root->color = BLACK;

			#ifdef LOG_TRE
			cout << "treeRB --> LOG code 32 value: " << new_node->value << endl;
			#endif // LOG_TRE

			return 0;
		}
	}

	//
	//wher father and a uncle are RED 
	//
	return 10;
}

int TreeRB::rr(NodeRB *root)
{
	if (root == NULL)
	{
		#ifdef LOG_TRE
		cout << "treeRB --> ERROR code 11" << endl << endl;
		#endif // LOG_TRE
		return -1;
	}

	if (root->up != NULL)
	{
		NodeRB *temp = root->up;

		if (temp->left == root)
		{
			temp->left = root->right;
		}else
		if (temp->right == root)
		{
			temp->right = root->right;
		}

		root->
	}

	return 0;
}

int TreeRB::rl(NodeRB *root)
{
	return 0;
}

int TreeRB::lr(NodeRB *root)
{
	return 0;
}

int TreeRB::ll(NodeRB *root)
{
	return 0;
}

int TreeRB::check_direction(NodeRB * root)
{
	if (root->up == NULL)
	{
		return -1;
	}
		
	if (root->up->left == root)
	{
		return LEFT;
	}

	if (root->up->right == root)
	{
		return RIGHT;
	}

	return -1;
}
