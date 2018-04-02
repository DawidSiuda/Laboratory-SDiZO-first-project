#include "Heap.h"

//#include <stack>

void Heap::push(int element)
{

	bool parent_has_been_found = false;
	bool its_new_level = false;

	#ifdef LOG_HEAP
	//cout << "heap --> push() has been called" << endl;;
	#endif // LOG_HEAP

	if (root == NULL)
	{
		root = new Node(NULL, element);
		return;
	}

	Node *new_parent = root;
	do
	{
		if (new_parent->left == NULL)
		{
			parent_has_been_found = true;
		}
		else
			if (new_parent->right == NULL)
			{
				parent_has_been_found = true;
			}
			else
			{
				if (new_parent->right->length < new_parent->left->length)
				{
					new_parent = new_parent->right;
				}
				else
				{
					new_parent = new_parent->left;
					its_new_level = true;
				}
			}
	} while (parent_has_been_found != true);

	if (new_parent->left == NULL)
	{
		new_parent->left = new Node(new_parent, element);
	}
	else
		if (new_parent->right == NULL)
		{
			new_parent->right = new Node(new_parent, element);
		}
		else
		{
			#ifdef SHOW_LOGS
			cout << "LOG: heap: can't add new element to heap" << endl;
			#endif //SHOW_LOGS
			return;
		}

	if (its_new_level)
	{
		increment_lenhgt_of_parents(new_parent->left);
	}

	show();
	//increment_lenhgt_of_parents(new_parent->left);
	/////////////////////////////////////
	/*
	Node *new_parent = root;
	if (new_parent == NULL)
	{
	return NULL;
	}

	do
	{
	if (new_parent->left == NULL)
	{
	return new_parent;
	}
	else
	if (new_parent->right == NULL)
	{
	return new_parent;
	}
	else
	{
	if (new_parent->right->length < new_parent->left->length)
	{
	new_parent = new_parent->right;
	increment_lenhgt_of_parents(new_parent->right);
	}
	else
	{
	new_parent = new_parent->left;
	increment_lenhgt_of_parents(new_parent->left);
	}
	}

	} while (true);

	//return new_parent;
	*/
}

void Heap::show()
{
	#ifdef LOG_HEAP
	cout << "heap --> show_heap() has been called" << endl << endl;
	#endif // LOG_HEAP
	
	char next_arrow[] = { 196,194,196,196,196,196,196,196,196,196,0};
	char pipe[] = { 32,32,32,32,32,32,179, 32, 32, 32,0 }; 
	char turn[] = { 32,32,32,32,32,32,192,196,196,196,0 };
	char line[] = { 196,196,196,196,196,196,196,196,196,0 };

	 
	//char pipe[] = { 32,32,32,32,32,32,179,32,32,32,0 };

	
	int hight = root->length;
	int level = hight;
	int direction = LEFT;

	int *tab_of_pipes = new int[hight];

	for (int i = 0; i <hight; i++)
	{
		tab_of_pipes[i] = 0;
	}


	//stack<int> stack_of_direction;
	List<int>  stack_of_direction;

	int  cont = 5; //number of loops

	Node *current_node = root;
	Node *last_parent = NULL;

	if (current_node == NULL)
	{
		#ifdef SHOW_LOGS
		cout << "LOG: heap: can't draw empty heap" << endl;
		#endif //SHOW_LOGS
		return;
	}

	//cout <<hight <<"======================================"<< endl;

	while (true)
	{
		//node line 
		//if (hight - level == 0)
		//{
		//	//cout << turn;
		//}
		//else
		//{
		//	//cout << "          ";
		//}
		if (level != hight )
		{
			cout << "          ";
		}
		
		for (int i = hight - level; i > 0; i--)
		{
			//cout << pipe;
		}

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

		cout << turn;

		while (true)
		{
			//draw path
			if (direction == RIGHT)
			{
				last_parent = current_node;
				current_node = current_node->right;
				stack_of_direction.push_back(RIGHT);
				level--;
				direction = LEFT;

			}

			if (current_node == NULL)
			{
				//tab_of_pipes[hight - level] = 1;
				cout << " null";

				//current_node = last_parent;
				current_node = last_parent;
				level++;
				stack_of_direction.pop_back();
			
					while (stack_of_direction.top() == RIGHT)
					{
						current_node = current_node->up;
						level++;
						stack_of_direction.pop_back();

						if (stack_of_direction.empty() == true)
						{
							#ifdef SHOW_LOGS
							//cout << "LOG: heap: stack is empyt" << endl;
							#endif //SHOW_LOGS
							delete[] tab_of_pipes;

							cout << endl;
							return;
						}
					}


					current_node = current_node->up;
					level++;
					stack_of_direction.pop_back();
				
				

				direction = RIGHT;
				


				if (current_node == NULL)
				{
					#ifdef SHOW_LOGS
					cout << "LOG: heap: show: return ERROR " << endl;
					#endif //SHOW_LOGS
				}

				break;
			}
			//show lenght
			string node_as_string = to_string(current_node->value) +  " " += to_string(current_node->length) + line;
			//string node_as_string = to_string(current_node->value) + " " + line;


			node_as_string = node_as_string.substr(0, 4);
			node_as_string = " " + node_as_string  + next_arrow;
			//string node_as_string = to_string(level) + " " + to_string(current_node->value) + next_arrow;
			node_as_string = node_as_string.substr(0, 10);
			//string substr(size_t pos = 0, size_t len = npos) const;
			//cout << std::setw(10) << node_as_string;
			cout << node_as_string;

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
			
			if (current_node == NULL )
			{
				if (direction ==LEFT)
				{
					cout << " NULL"; 

					current_node = last_parent;
					stack_of_direction.pop_back();
					level++;
					direction = RIGHT;
					//current_node = current_node->up;
					//level++;
					//current_node = current_node->right;
					//if(current_node==NULL)

					
				}
				else
				if (direction == RIGHT)
				{
					cout << " NULL";

					current_node = last_parent;
					stack_of_direction.pop_back();
					level++;
					current_node = current_node->up;
					stack_of_direction.pop_back();
					level++;

					direction = RIGHT;

				}
				//cout << " NULL";

				//direction = RIGHT;
				//current_node = current_node->up;
				break;
			}
		}
		//cout << "                    LEVEL: " << level << "    value: " << current_node->value << endl;
		cout << endl;
		/*
		stack<int> kopia;

		while (stack_of_direction.empty() != true)
		{
			kopia.push(stack_of_direction.top());
				cout << " " << stack_of_direction.top();
				stack_of_direction.pop_back();
		}
		cout << endl;
		while (kopia.empty() != true)
		{
			stack_of_direction.push_back(kopia.top());
			kopia.pop();
		}
		/*cout << stack_of_direction.top();
		stack_of_direction.pop();
		cout << "  " << stack_of_direction.top();
		stack_of_direction.pop();
		cout << "  " << stack_of_direction.top();
		stack_of_direction.pop();
		cout << "  " << stack_of_direction.top();
		stack_of_direction.pop();
		cout << "  ";
		*/
		cout << "          ";
		//empty line 

		
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
		cout << pipe;



		//while (1)
		//{
		//	string node_as_string = pipe;
		//		//+ to_string(current_node->value) + next_arrow;
		//	//string substr(size_t pos = 0, size_t len = npos) const;
		//	//cout << std::setw(10) << node_as_string;
		//	cout << node_as_string;
		//	current_node = current_node->left;

		//	if (current_node == NULL)
		//	{
		//		current_node = root;
		//		break;
		//	}
		//	//<< " DAWID" << std::endl;
		//}
		cout << endl;

		if (level == hight && stack_of_direction.empty() == true)
		{
			cout << "          ";
		}
	}
	//cout << "======================================" << endl;

	

}

Heap::Heap()
{
	root = NULL; 
}


Heap::~Heap()
{
	
}

void Heap::increment_lenhgt_of_parents(Node * node)
{
	#ifdef LOG_HEAP
	cout << "heap -->increment_length_of_parents() has been called" << endl;	
	#endif // LOG_HEAP
	
	if (node->up != NULL)
	{
		node = node->up;
	}

	while (node != NULL)
	{
		node->length++;
		node = node->up;
	}
}
