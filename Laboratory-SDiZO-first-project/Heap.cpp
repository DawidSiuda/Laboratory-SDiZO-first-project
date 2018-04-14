#include "Heap.h"

#include <math.h>

void Heap::push(int value)
{
	#ifdef LOG_HEAP
	cout << "heap --> push() has been called" << endl << endl;
	#endif // LOG_HEAP

	//
	//creating first element if its necessary
	//

	if (arrayHeap == NULL)
	{
		arrayHeap = new int[1];

		arrayHeap[0] = value;

		size++;

		return;
	}

	//
	//create new array
	//

	int *temp = new int[size+1];

	for (int i = 0; i < size; i++)
	{
		temp[i] = arrayHeap[i];
	}

	temp[size] = value;

	delete[] arrayHeap;

	arrayHeap = temp;

	size++;

	//
	//seting a tree 
	//

	set_tree(size-1);
}

int Heap::pop(int value)
{
	#ifdef LOG_HEAP
	cout << "heap --> pop() has been called" << endl << endl;
	#endif // LOG_HEAP

	//
	//finding index 
	//

	int index = -1;

	for (int i = 0; i < size; i++)
	{
		if (arrayHeap[i] == value)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		#ifdef LOG_HEAP
		cout << "heap --> pop() can't find value" << endl;
		#endif // LOG_HEAP

		return -1;
	}

	//
	//creating new array wthout the deleted value
	//

	int *temp = new int[size - 1];

	for (int i = 0; i < size-1; i++)
	{
		if (i == index)
		{
			cout << "DUPA " << endl;
			temp[i] = arrayHeap[size-1];
			continue;
		}

		temp[i] = arrayHeap[i];
	}

	delete[] arrayHeap;

	arrayHeap = temp;
	
	size--;

	//
	//seting a tree 
	//

	revers_set_tree(index);

}

void Heap::show()
{
	#ifdef LOG_HEAP
	cout << "heap --> show_heap() has been called" << endl << endl;
	#endif // LOG_HEAP
	
	if (arrayHeap == NULL)
	{
		#ifdef SHOW_LOGS
		cout << "LOG: heap: can't draw empty heap" << endl;
		#endif //SHOW_LOGS

		return;
	}

	char next_arrow[]  = { 196,194,196,196,196,196,196,196,196,196,0};
	char pipe[]		   = { 32,32,32,32,32,32,179, 32, 32, 32,0 }; 
	char turn[]        = { 32,32,32,32,32,32,192,196,196,196,0 };
	char line[]        = { 196,196,196,196,196,196,196,196,196,0 };

	int hight = ceil(log2(size));
	int direction = LEFT;
	int current_step = 0;
	int *last_parent = NULL;

	int *tab_of_pipes = new int[hight];

	List<int>  stack_of_direction;
	
	bool its_root = true;
	bool end_main_loop = false;

	while (end_main_loop == false)
	{
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

		int step = 0;
		bool end_level = false;
		bool lastnode_was_empty = false;

		//
		//draw nodes in one line in console
		//

		while (end_level == false)
		{
			if (its_root== true)
			{
				string node_as_string = to_string(arrayHeap[current_step]) + " " + line;
				node_as_string = node_as_string.substr(0, 4);

				node_as_string = " " + node_as_string + next_arrow;
				node_as_string = node_as_string.substr(0, 10);
				cout << node_as_string;

				its_root = false;

				continue;
			}
		
			if (lastnode_was_empty != true)
			{
				if (direction == LEFT)
				{
					current_step = (2 * current_step) + 1;

					stack_of_direction.push_back(LEFT);
				}
				else
				if (direction == RIGHT)
				{
					current_step = (2 * current_step) + 2;

					stack_of_direction.push_back(RIGHT);

					direction = LEFT;
				}
			}
			
			if (current_step >= size)
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

				current_step = (current_step - 1) / 2;
				direction = stack_of_direction.top();
				stack_of_direction.pop_back();

				if (direction == LEFT)
				{
					direction = RIGHT;
				}
				else
				if (direction == RIGHT)
				{
					current_step = (current_step - 1) / 2;
					direction = stack_of_direction.top();
					stack_of_direction.pop_back();

					while (direction == RIGHT)
					{
						current_step = (current_step - 1) / 2;
						direction = stack_of_direction.top();
						stack_of_direction.pop_back();
					}
					direction = RIGHT;
				}

				lastnode_was_empty = true;

				break;
			}
			else
			{
				if (stack_of_direction.top() == LEFT)
				{
					string node_as_string = to_string(arrayHeap[current_step]) + " " + line;
					node_as_string = node_as_string.substr(0, 4);
					node_as_string = " " + node_as_string + next_arrow;
					node_as_string = node_as_string.substr(0, 10);
					cout << node_as_string;
				}
				else
				if (stack_of_direction.top() == RIGHT)
				{
					cout << turn;
				
					string node_as_string = to_string(arrayHeap[current_step]) + " " + line;
					node_as_string = node_as_string.substr(0, 4);
					node_as_string = " " + node_as_string + next_arrow;
					node_as_string = node_as_string.substr(0, 10);
					cout << node_as_string;
				}
			}

			lastnode_was_empty = false;

			step++;
		}

		cout << endl;

		//
		// draw space under branch
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
}

bool Heap::find(int value)
{
	#ifdef LOG_HEAP
	cout << "heap --> find() has been called" << endl << endl;
	#endif // LOG_HEAP

	for (int i = 0; i < size; i++)
	{
		if (value == arrayHeap[i])
		{
			return true;
		}
	}

	return false;
}

Heap::Heap()
{
	arrayHeap = NULL;

	size = 0;

}

Heap::~Heap()
{
	delete[] arrayHeap;
}

void Heap::set_tree(int index)
{
	#ifdef LOG_HEAP
	cout << "heap --> set_tree() has been called" << endl << endl;
	#endif // LOG_HEAP

	while (index != 0)
	{
		if (arrayHeap[(index - 1) / 2] < arrayHeap[index])
		{
			replace((index - 1) / 2, index);
			index = (index - 1) / 2;
			continue;
		}
		break;
	}

}

void Heap::revers_set_tree(int index)
{
	#ifdef LOG_HEAP
	cout << "heap --> revers_set_tree() has been called" << endl << endl;
	#endif // LOG_HEAP

	while (true)
	{
		int left_son = (2 * index) + 1;
		int right_son = (2 * index) + 2;

		bool left_is_bigger = true;
		bool right_is_bigger = true;

		//
		//check which are bigger 
		// 

		if (left_son >= size)
		{
			left_is_bigger = false;
		}

		if (right_son >= size)
		{
			right_is_bigger = false;
		}

		if (left_is_bigger != false && arrayHeap[left_son] < arrayHeap[index])
		{
			left_is_bigger = false;
		}

		if (right_is_bigger != false && arrayHeap[right_son] < arrayHeap[index])
		{
			right_is_bigger = false;
		}

		//
		//return if replace isn't necessary
		//

		if (right_is_bigger == false && left_is_bigger == false)
		{
			return;
		}

		//
		//replace values 
		//

		if (right_is_bigger == true && left_is_bigger == true)
		{
			if (arrayHeap[right_son] > arrayHeap[left_son])
			{
				replace(index, right_son);

				index = right_son;
			}
			else
			{
				replace(index, left_son);

				index = left_son;
			}

			continue;
		}

		if (right_is_bigger == true && left_is_bigger == false)
		{
			replace(index, right_son);

			index = right_son;

			continue;
		}

		if (right_is_bigger == false && left_is_bigger == true)
		{
			replace(index, left_son);

			index = left_son;

			continue;
		}

	}
}

void Heap::replace(int index1, int index2)
{
	#ifdef LOG_HEAP
	cout << "heap --> replace() has been called" << endl << endl;
	#endif // LOG_HEAP

	int temp = arrayHeap[index1];

	arrayHeap[index1] = arrayHeap[index2];

	arrayHeap[index2] = temp;
}
