#include "Flags.h"

#include "List.h"
#include "Heap.h"
#include "Table.h"

#include "Core.h"

#include <iostream>
#include <Windows.h>

#include <stack>


using namespace std;

void main()
{
	run_main_program();
	/*
	Table tab;
	
	for (int i = 0; i < 20; i++)
	{
		tab.push_random_place(i);
	}
	tab.show();

	for (int i = 0; i < 60; i++)
	{
		tab.pop_random_place();
		cout << "--------------------------" << endl;
		
	}

	tab.show();
	*/
	/*
	
	Heap heap;

	for (int i = 1; i < 11; i++)
	{
		
		cout << "--------------------------" << endl;
		heap.push(i);
		//cout << endl;
		//list.show_back();
		cout << "--------------------------" << endl;
	}

	//Node *ptr = heap.root->left->left;
	Node *ptr = heap.root->right->left->left->left;

	if (ptr != NULL)
	{
		cout << "======================================" << endl << endl;
		cout << ptr->value;
		cout << endl << "======================================" << endl;

	}
	else
	{
		cout << "======================================" << endl << endl;
		cout << "ptr is NULL " << endl;
		cout << endl << "======================================" << endl;

	}
	cout << endl;
	heap.show();
	*/
	/*
	List<int> list;


	for (int i = 0; i < 10; i++)
	{
		list.push_random_place(i);
		cout << "--------------------------" << endl;
		list.show();
		cout << endl;
		list.show_back();
		cout << "--------------------------" << endl;
	}


	for (int i = 0; i < 20; i++)
	{
		list.pop_random_place();
		cout << "------------DELETE "<<i<<"--------------" << endl;
		list.show();
		cout << endl;
		list.show_back();
		cout << "--------------------------" << endl;
	}
*/

	//list.show();

	//cout << "-----------------------------------" << endl;
	//cout << "--> usuwamy z 2 razy przodu" << endl;

	//list.pop_front();
	//list.pop_front();
	//cout << "--> wyswietlamy list at 4" << endl;
	//cout << "list[4]: " << list.get_value_at(12) << endl;

	//cout << "-----------------------------------" << endl;
	//list.pop_front();
	//list.pop_front();

	//list.show();

//#ifdef TEST
//#line linenume
//	cout << "ERROR: Linia" << lineume << " List.h" << endl;
//#endif // TEST
//
	system("pause");




	//List<char> list;


	
	return;

}