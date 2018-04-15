#pragma once

#include "Flags.h"

#include <iostream>
#include <iomanip>      // std::setw

template <typename Type>
class List
{
public:
	
	
	void push_front(Type value);
	void pop_front();
	void show() const;				// Function show all elements from list in console.
	bool empty() const;

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
	};	
	bool isEmpty;		// flag set when list is empty 
	element *first;		// pointer on the first element
	element *last;		// pointer on the first element
};

//template<typename Type>
//	inline class List<Type>::element
//	{
//		element *next;
//		element *previous;
//		Type *value;
//
//		element(element *previous, element *next, Type *value)
//		{
//			this.next = next;
//			this.previous = previous;
//			this.value = value
//		}
//	};

template<typename Type>
	inline bool List<Type>::empty() const
	{
		return isEmpty;
	}

template<typename Type>
	inline void List<Type>::push_front(Type newElement)
	{
		if (first == NULL)
		{
			first = new element(NULL, NULL, newElement);
			last = first;
		}
		else
		{
			element *temp = first;
			first = new element(NULL, temp, newElement);

		}
	}

template<typename Type>
	inline void List<Type>::pop_front()
	{
		element *temp = first;
		first = first->next;
		first->previous = NULL;
		delete temp;
	}
	
template<typename Type>
	inline void List<Type>::show() const
	{
		int counter = 0;
		element *ptr;
		ptr = first;
		
		while (ptr != NULL)
		{
			std::cout << std::setw(5) << counter << " -->  "<< ptr->value << std::endl;
			ptr = ptr->next;
			counter++;
		}
	}
	
template<typename Type>
	inline List<Type>::List()
	{
		isEmpty = true;
		first = NULL;
		last = NULL;
	}

template<typename Type>
	inline List<Type>::~List()
	{
	}