#pragma once

#include "Flags.h"
//#include "Logs.h"

#include <iostream>
#include <iomanip>      // std::setw
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

template <typename Type>
class List
{
public:

	void show() const;				// Function show all elements from list in console.
	void show_back() const;			// Function show all elements from list in console.
	bool empty() const;
	int get_size();
	Type top() const;

	Type get_value_at(int index);
	
	void push_front(Type value);
	void push_back(Type value);
	void push_random_place(Type value);
	void push_at(const unsigned int index, Type value);

	void pop_front();
	void pop_back();
	void pop_random_place();

	List<Type>();
	~List<Type>();

private:
	class element
	{
	public:
		element *next;
		element *previous;
		Type value;

		element(element *previousElement, element *nextElement, Type valueOfElement)
		{
			next = nextElement;
			previous = previousElement;
			value = valueOfElement;
		}
		element()
		{
			next = NULL;
			previous = NULL;
		}
	};	
	bool isEmpty;		// flag set when list is empty 
	unsigned int size;
	element *first;		// pointer on the first element
	element *last;		// pointer on the first element
};

template<typename Type>
	inline void List<Type>::show() const
	{
		int counter = 0;
		element *ptr;
		ptr = first;

		while (ptr != NULL)
		{
			std::cout << std::setw(5) << counter << " -->  " << ptr->value << std::endl;
			ptr = ptr->next;
			counter++;
		}
	}

	template<typename Type>
	inline void List<Type>::show_back() const
	{
		int counter = size-1;
		element *ptr;
		ptr = last;

		while (ptr != NULL)
		{
			std::cout << std::setw(5) << counter << " -->  " << ptr->value << std::endl;
			ptr = ptr->previous;
			counter--;
		}
	}

	template<typename Type>
	inline bool List<Type>::empty() const
	{
		if (first == NULL)
			return true;
		else
			return false;
	}

	template<typename Type>
	inline int List<Type>::get_size()
	{
		int counter = 0;

		element *ptr = first;
		while (ptr != NULL)
		{
			counter++;
			ptr = ptr->next;
		}
		return counter;
	}

	template<typename Type>
	inline Type List<Type>::top() const
	{
		if (empty() == true)
		{
			cout << "LOG: list: function \"top\" return NUll as 0" << endl;
			return 0;
		}

		return last->value;
	}



	template<typename Type>
	inline void List<Type>::push_front(Type newElement)
	{
		#ifdef LOG_LIST
			cout << "--> push_front(" << newElement << ") has been called" << endl;
		#endif // LOG_LIST

		if (first == NULL)
		{
			first = new element(NULL, NULL, newElement);
			last = first;
		}
		else
		{
			element *temp = first;
			first = new element(NULL, temp, newElement);
			temp->previous = first;

		}

		size++;
	}

template<typename Type>
	inline void List<Type>::push_back(Type value)
	{
		#ifdef LOG_LIST
			cout << "--> push_back(" << value << ") has been called" << endl;
		#endif // LOG_LIST

		if (last == NULL)
		{
			last = new element(NULL, NULL, value);
			first = last;
		}
		else
		{
			element *temp = last;
			last = new element(temp, NULL, value);
			last->next = NULL;
			last->previous = temp;
			last->value = value;

			temp->next = last;
		}
		size++;
	}

template<typename Type>
	inline void List<Type>::push_random_place(Type value)
	{
		#ifdef LOG_LIST
			cout << "--> push_random_place(" <<value << ") has been called" << endl;
		#endif // LOG_LIST

		if (size == 0)
		{
			push_front(value);
			return;
		}

		int index = rand() % size;

		cout << "          ROUND: " << index << endl;

		if (index == 0)
		{
			push_front(value);
			return;
		}else
		if (index == size - 1)
		{
			push_back(value);
			return;
		}
		else
		{
			push_at(index, value);
			return;
		}

	}

template<typename Type>
	inline void List<Type>::push_at(const unsigned int index, Type value)
	{
		#ifdef LOG_LIST
		cout << "--> push_at(" << index << "," << value << ") has been called" << endl;
		#endif // LOG_LIST

		if (size == 0)
		{
			push_front(value);
			return;
		}else
		if (index >= size)
		{
			push_back(value);
			return;
		}
		else
		if (index == 0)
		{
			push_front(value);
			return;
		}
		else
		if (index == size - 1)
		{
			push_back(value);
			return;
		}
		else
		{
			element* ptr = first;
			for (int i = 0; i < index; i++)
			{
				ptr = ptr->next;
			}

			element *temp = new element();
			
			temp->next = ptr;
			temp->previous = ptr->previous;

			
			ptr->previous = temp;
			temp->previous->next = temp;
			
			temp->value = value;

			size++;
			return;
		}


	}

template<typename Type>
	inline void List<Type>::pop_front()
	{
		#ifdef LOG_LIST
			cout << "--> pop_front() has been called" << endl;
		#endif // LOG_LIST

		if (first != NULL)
		{
			if (last == first)
			{
				delete first;
				first = NULL;
				last = NULL;
			}
			else
			{
				element *temp = first;
				first = first->next;
				first->previous = NULL;
				delete temp;
			}
			size--;
		}
		else
		{
			cout << "LOG: list: can't call pop() on list. List is empty" << endl;
		}
	}



template<typename Type>
	inline void List<Type>::pop_back()
	{
		#ifdef LOG_LIST
			cout << "--> pop_back() has been called" << endl;
		#endif // LOG_LIST

		if (last != NULL)
		{
			if (last == first)
			{
				delete first;
				first = NULL;
				last = NULL;
			}
			else
			{
				element *temp = last;
				last = last->previous;
				last->next = NULL;
				delete temp;
			}
			size--;
		}
		else
		{
			cout << "LOG: list: can't call pop() on list. List is empty" << endl;
		}
		
	}

template<typename Type>
	inline void List<Type>::pop_random_place()
	{
		#ifdef LOG_LIST
			cout << "--> pop_random_place() has been called" << endl;
		#endif // LOG_LIS

		if (empty() == false)
		{
			int index = 255;
			if (size != 0)
			{
				index = rand() % (size);
			}	

			#ifdef LOG_LIST
				cout << "\tsize: " << size << endl;
				cout << "\t pop from index nr: " << index << endl;
			#endif // LOG_LIS

			if (last == first)
			{
				delete first;
				first = NULL;
				last = NULL;
				size--;
			}
			else
			{
				
				element *temp = first;
				while (index != 0 && --index)
				{
					temp = temp->next;
				}

				if (temp->next == NULL)
				{
					pop_back();
				}else
				if (temp->previous == NULL)
				{
					pop_front();
				}
				else
				{
					temp->next->previous = temp->previous;
					temp->previous->next = temp->next;
					delete temp;
					size--;
				}
			}

			
		}
		else
		{
			cout << "LOG: list: can't call pop() on list. List is empty" << endl;
		}
	}

template<typename Type>
	inline Type List<Type>::get_value_at(int index)
	{
		element *ptr = first;
		for (int i = 0; ptr !=NULL && i < index; i++)
		{
			ptr = ptr->next;
		}

		if (ptr == NULL)
		{
			#ifdef LOG_LIST
			cout << "ERROR: Linia  " << __LINE__ << " List.h" << endl;
			#endif // LOG_LIST

			cout << "LOG: list: function \"get_value_at\" return NUll as 0" << endl;
			return 0;
		}
		return ptr->value;
	}

	
template<typename Type>
	inline List<Type>::List()
	{
		isEmpty = true;
		first = NULL;
		last = NULL;
		size = 0;

		//
		//initialize random seed
		//It is unign guring push and pop value in random pleace in struct
		//
		srand(time(NULL));
	}

template<typename Type>
	inline List<Type>::~List()
	{
		int counter = 0;
		while (first != NULL)
		{
			pop_front();
			cout << "delete counter " << counter++ << endl;
		}
	}