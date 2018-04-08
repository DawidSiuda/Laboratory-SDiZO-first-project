#include "Array.h"



void Array::show()
{
	#ifdef LOG_TAB
	cout << "--> Table::show() has been called" << endl;
	#endif // LOG_TAB

	for(int i = 0; i<size; i++)
	{
		std::cout << std::setw(5) << i << " -->  " <<  first[i] << std::endl;
	}
}

bool Array::empty()
{
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Array::find(int value)
{
	for (int i = 0; i < size; i++)
	{
		if (first[i] == value)
		{
			return true;
		}
	}
	return false;
}

void Array::push_front(int value)
{
	#ifdef LOG_TAB
	cout << "--> Table::push_front(" << value << ") has been called" << endl;
	#endif // LOG_TAB
	
	push_at(0, value);
}

void Array::push_back(int value)
{
	#ifdef LOG_TAB
	cout << "--> Table::push_back(" << value << ") has been called" << endl;
	#endif // LOG_TAB

	push_at(size, value);
}

void Array::push_random_place(int value)
{
	#ifdef LOG_TAB
	cout << "--> Table::push_random_place(" << value << ") has been called" << endl;
	#endif // LOG_TAB

	if (size == 0)
	{
		push_at(0, value);
	}
	else
	{
		int index = rand() % size;
		push_at(index, value);
	}
	
}

void Array::push_at(unsigned int index, int value)
{
	#ifdef LOG_TAB
	cout << "--> Table::push_at(" << index << "," << value << ") has been called" << endl;
	#endif // LOG_TAB

	if (first == NULL)
	{
		first = new int[1];
		first[0] = value;
		size++;
		return;
	}

	if (index > size)
	{
		index = size;
	}

	int *temp = first;
	first = new int[size + 1];

	int j = 0;

	for (int i = 0; i <= size + 1; i++)
	{

		if (i == index)
		{
			first[i] = value;
		}
		else
		{
			first[i] = temp[j];
			j++;
		}
	}

	size++;
	delete[] temp;
}

void Array::pop_front()
{
	#ifdef LOG_TAB
	cout << "--> Table::pop_front() has been called" << endl;
	#endif // LOG_TAB

	pop_at(0);
}

void Array::pop_back()
{
	#ifdef LOG_TAB
	cout << "--> Table::pop_back() has been called" << endl;
	#endif // LOG_TAB

	pop_at(size-1);
}

void Array::pop_random_place()
{
	#ifdef LOG_TAB
	cout << "--> Table::pop_random_place() has been called" << endl;
	#endif // LOG_TAB

	if (size == 0)
	{
		#ifdef LOG_TAB
		cout << "--> ERROR: Table::pop_random_place(): table is empty" << endl;
		#endif // LOG_TAB
		return;
	}

	int index = rand() % size;
	pop_at(index);
}

void Array::pop_at(unsigned int index)
{
	#ifdef LOG_TAB
	cout << "--> Table::pop_at(" << index << ") has been called" << endl;
	#endif // LOG_TAB

	if (empty() == true)
	{
		#ifdef LOG_TAB
		cout << "--> ERROR: Table::pop_at(" << index << "): table is empty" << endl;
		#endif // LOG_TAB

		return;
	}

	if (index < 0 && index > size)
	{
		#ifdef LOG_TAB
		cout << "--> ERROR: Table::pop_at(" << index << "):  index is out of table" << endl;
		#endif // LOG_TAB

		return;
	}

	int *temp = first;
	first = new int[size-1];

	for (int i = 0, j = 0; i < size; i++)
	{

		if (i == index)
		{
			continue;
		}
		else
		{
			first[j] = temp[i];
			j++;
		}
	}

	size--;
	delete[] temp;
}

Array::Array()
{
	size = 0;
	first = NULL;
	srand(time(NULL));
}


Array::~Array()
{
	delete[] first;
}
