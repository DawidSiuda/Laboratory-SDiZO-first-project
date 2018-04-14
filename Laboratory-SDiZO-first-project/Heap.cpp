#include "Heap.h"

void Heap::push(int value)
{
	if (find(value) == true)
	{	
		#ifdef SHOW_LOGS
		cout << "LOG: HEAP: can't add existing value to the heap" << endl;
		#endif // SHOW_LOGS

		return;
	}

	//
	//create path to new node
	//

	if (root == NULL)
	{
		root = new Node(NULL, value);
		last_node = root;
		return;
	}

	if (path_to_last_node == NULL)
	{
		path_to_last_node = new List<int>;
		path_to_last_node->push_back(LEFT);
	}
	else
	{

		bool path_is_complete = false;

		//
		//check if level is complete 
		//

		bool tree_is_complete = true;

		for (int i = 0; i < path_to_last_node->get_size(); i++)
		{
			if (path_to_last_node->get_value_at(i) == LEFT)
			{
				tree_is_complete = false;
			}

		}

		if (tree_is_complete == true)
		{
			for (int i = 0; i < path_to_last_node->get_size(); i++)
			{
				path_to_last_node->edit_value_at(i,LEFT);
			}

			path_to_last_node->push_front(LEFT);
			path_is_complete = true;
		}


		//
		//if last direction was LEFT
		//

		if (path_is_complete == false)
		{
			if (path_to_last_node->top() == LEFT)
			{
				path_to_last_node->pop_back();
				path_to_last_node->push_back(RIGHT);
				path_is_complete = true;
			}
		}

		//
		//if last direction was RIGHT
		//

		if (path_is_complete == false)
		{
			for (int i = path_to_last_node->get_size()-1; i >=0 ; i--)
			{
				if (path_to_last_node->get_value_at(i) == LEFT)
				{
					path_to_last_node->edit_value_at(i, RIGHT);
					i = -1;
				}
				else
				{
					path_to_last_node->edit_value_at(i, LEFT);
				}

			}
		}
	}

	//
	//create new node
	//

	Node *new_element = root;

	for (int i = 0; i < path_to_last_node->get_size()-1; i++)
	{
		if (path_to_last_node->get_value_at(i) == LEFT)
		{
			new_element = new_element->left;
		}
		else
		if (path_to_last_node->get_value_at(i) == RIGHT)
		{
			new_element = new_element->right;
		}
	}

	if (path_to_last_node->top() == LEFT)
	{
		new_element->left = new Node(new_element, value);
		last_node = new_element->left;
		number_of_elements++;
	}
	else
	if (path_to_last_node->top() == RIGHT)
	{
		new_element->right = new Node(new_element, value);
		last_node = new_element->right;
		number_of_elements++;
	}

	//
	//set node on correct position in tree 
	//

	set_node_in_tree(last_node);
}

void Heap::pop(int value)
{
	
	#ifdef LOG_HEAP
	cout << "heap --> pop() has been called" << endl << endl;
	#endif // LOG_HEAP

	Node *del_element = find_pointer_to_value(value, root);

	if (del_element == NULL)
	{
		#ifdef SHOW_LOGS
		cout << "LOG: heap: can't pop value, value not found" << endl;
		#endif //SHOW_LOGS

		return;
	}

	if (del_element == last_node)
	{		
		if (number_of_elements == 0)
		{
			delete last_node;
			root = NULL;
			last_node = NULL;
			number_of_elements--;
			return;
		}
		else
		{
			if (last_node->up != NULL)
			{
				if (path_to_last_node->top() == RIGHT)
				{
					last_node->up->right = NULL;
				}
				else
				if (path_to_last_node->top() == LEFT)
				{
					last_node->up->left = NULL;
				}
			}

			delete last_node;
			back_last_node();
			number_of_elements--;
			return;
		}
		
	}

	del_element->value = last_node->value;

	//
	//set null on parent pointer to last_lode
	//

	if (last_node->up != NULL)
	{
		if (path_to_last_node->top() == RIGHT)
		{
			last_node->up->right = NULL;
		}else
		if (path_to_last_node->top() == LEFT)
		{
			last_node->up->left = NULL;
		}
	}
	delete last_node;
	number_of_elements--;

	back_last_node();
	//cout << "LSAT_NODE: "<<last_node->value  << endl;
	set_node_in_tree_reverse(del_element);

	return;
}

void Heap::show()
{
	#ifdef LOG_HEAP
	cout << "heap --> show_heap() has been called" << endl << endl;
	#endif // LOG_HEAP
	
	if (root == NULL)
	{
		#ifdef SHOW_LOGS
		cout << "LOG: heap: can't draw empty heap" << endl;
		#endif //SHOW_LOGS

		return;
	}

	char next_arrow[] = { 196,194,196,196,196,196,196,196,196,196,0};
	char pipe[] = { 32,32,32,32,32,32,179, 32, 32, 32,0 }; 
	char turn[] = { 32,32,32,32,32,32,192,196,196,196,0 };
	char line[] = { 196,196,196,196,196,196,196,196,196,0 };
	
	int hight = root->length;
	int level = hight;
	int direction = LEFT;

	int *tab_of_pipes = new int[hight];

	List<int>  stack_of_direction;
	
	Node *current_node = root;
	Node *last_parent = NULL;

	bool end_main_loop = false;

	//set table of positions to draw pipes on console 
	for (int i = 0; i <hight; i++)
	{
		//tab_of_pipes[i] = 0;
	}

	if (current_node == NULL)
	{
		#ifdef SHOW_LOGS
		cout << "LOG: heap: can't draw empty heap" << endl;
		#endif //SHOW_LOGS

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
					//string node_as_string  = to_string(current_node->length) + " " + to_string(current_node->value) + " " + line;
					string node_as_string = to_string(current_node->value) + " " + line;
					node_as_string = node_as_string.substr(0, 4);

					node_as_string = " " + node_as_string + next_arrow;
					node_as_string = node_as_string.substr(0, 10);
					cout << node_as_string;
				}
				else
				if (stack_of_direction.top() == RIGHT)
				{
					cout << turn;
					//string node_as_string = to_string(current_node->length) + " " + to_string(current_node->value) + " " + line;
					string node_as_string = to_string(current_node->value) + " " + line;
					node_as_string = node_as_string.substr(0, 4);

					node_as_string = " " + node_as_string + next_arrow;
					node_as_string = node_as_string.substr(0, 10);
					cout << node_as_string;
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

bool Heap::find(int value)
{
	#ifdef LOG_HEAP
	cout << "heap --> find_value() has been called" << endl << endl;
	#endif // LOG_HEAP

	return find_value(value, root);
}

bool Heap::find_value(int value, Node *root)
{
	if (root == NULL);
	{
		return false;
	}

	if (root->value == value)
	{
		return true;
	}

	if (root->left != NULL)
	{
		if (find_value(value, root->left) == true)
		{
			return true;
		}
	}

	if (root->right != NULL)
	{
		if (find_value(value, root->right) == true)
		{
			return true;
		}
	}

	return false;
}

Node * Heap::find_pointer_to_value(int value, Node * root)
{
	if (root->value == value)
	{
		return root;
	}

	if (root->left != NULL)
	{
		Node *temp = find_pointer_to_value(value, root->left);
		if ( temp != NULL)
		{
			return temp;
		}
	}

	if (root->right != NULL)
	{
		Node *temp = find_pointer_to_value(value, root->right);
		if (temp != NULL)
		{
			return temp;
		}
	}

	return false;
}

Heap::Heap()
{
	root = NULL; 
	last_node = NULL;
	number_of_elements = 0;
	//path_to_last_node = new List<int>;
}

Heap::~Heap()
{
	while (root != NULL)
	{
		pop(root->value);
	}
}

void Heap::set_node_in_tree(Node *const(node))
{
	Node *temp = node;

	if (temp->up != NULL)
	{
		while (temp->up != NULL && temp->up->value < temp->value)
		{
			change_values(temp, temp->up);
			temp = temp->up;
		}
	}
}

void Heap::set_node_in_tree_reverse(Node * const(node))
{
	#ifdef LOG_HEAP
	cout << "heap --> find_value() has been called" << endl << endl;
	#endif // LOG_HEAP

	Node *temp = node;

	if (temp->left != NULL)
	{
		if (temp->right != NULL)
		{
			if (temp->value < temp->left->value)
			{

				if (temp->value < temp->right->value)
				{
					if (temp->left->value > temp->right->value)
					{
						change_values(temp, temp->left);
						set_node_in_tree_reverse(temp->left);
					}
					else
					{
						change_values(temp, temp->right);
						set_node_in_tree_reverse(temp->right);
					}
				}
				else
				{
					change_values(temp, temp->left);
					set_node_in_tree_reverse(temp->left);
				}
			}else
			if (temp->right != NULL)
			{
				if (temp->value > temp->right->value)
				{
					change_values(temp, temp->right);
					set_node_in_tree_reverse(temp->right);
				}
			}

		}else
		if (temp->value < temp->left->value)
		{
			change_values(temp, temp->left);
			set_node_in_tree_reverse(temp->left);
		}
	}
	return;
}

void Heap::change_values( Node * node1, Node * node2)
{
	int temp;
	temp = node1->value;
	node1->value = node2->value;
	node2->value = temp;
}

void Heap::back_last_node()
{
	if (root == NULL)
	{
		last_node = NULL;
		return;
	}

	if (path_to_last_node->empty() == true)
	{
		last_node = root;
		return;
	}
	else
	{
		
		bool path_is_complete = false;

		//
		//check if level is complete 
		//

		bool its_alone_element_on_level = true;

		for (int i = 0; i < path_to_last_node->get_size(); i++)
		{
			if (path_to_last_node->get_value_at(i) == RIGHT)
			{
				its_alone_element_on_level = false;
			}
		}


		if (its_alone_element_on_level == true)
		{
			for (int i = 0; i < path_to_last_node->get_size(); i++)
			{
				path_to_last_node->edit_value_at(i, RIGHT);
			}

			path_to_last_node->pop_back();
			path_is_complete = true;
		}


		//
		//if last direction was RIGHT
		//

		if (path_is_complete == false)
		{
			if (path_to_last_node->top() == RIGHT)
			{
				path_to_last_node->pop_back();
				path_to_last_node->push_back(LEFT);
				path_is_complete = true;
			}
		}

		//
		//if last direction was LEFT
		//

	

		if (path_is_complete == false)
		{
			for (int i = path_to_last_node->get_size() - 1; i >= 0; i--)
			{
				if (path_to_last_node->get_value_at(i) == RIGHT)
				{
					path_to_last_node->edit_value_at(i, LEFT);
					i = -1;
				}
				else
				{
					path_to_last_node->edit_value_at(i,	RIGHT);
				}

			}
		}
	
	}

	last_node = root;
	for (int i = 0; i < path_to_last_node->get_size(); i++)
	{

		if (path_to_last_node->get_value_at(i) == RIGHT)
		{			
			last_node = last_node->right;
		}
		else
		if (path_to_last_node->get_value_at(i) ==LEFT)
		{
			last_node = last_node->left;
		}
	}
}

