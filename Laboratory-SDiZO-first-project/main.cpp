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
#ifdef SHOW_LOGS
	cout << " defined SHOW_LOGS" << endl;
#endif // SHOW_LOGS


	//List<int>sdget;
	//List<string> iiduhiew;
	//run_main_program();
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
	
	
	Heap heap;

	for (int i = 1; i < 15; i++)
	{
		
		heap.push(i);
	}

	/*heap.pop(1);
	heap.pop(14);
	heap.show();
	heap.push(50);
	heap.show();*/

	heap.~Heap();

	cout << endl;
	//heap.show();
	system("pause");
	return;
	/*
	cout << "find: " << heap.find_value(1) << endl;
	cout << "find: " << heap.find_value(3) << endl;
	cout << "find: " << heap.find_value(0) << endl;
	cout << "find: " << heap.find_value(50) << endl;
	cout << "find: " << heap.find_value(5) << endl;
	*/

	//int dupa = heap.root->left->left->value;
	//cout << "dupa: " << dupa << endl;

	//Node *ptr = heap.root->left->left;
	/*
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




	//List<char> list;


	
	

}