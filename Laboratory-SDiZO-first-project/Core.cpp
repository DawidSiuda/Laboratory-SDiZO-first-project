#include "Core.h"

void run_main_program()
{
	system("cls");

	bool function_exit = false;

	while(function_exit == false)
	{
		show_main_menu();
		int choice;
		cin >> choice;

		switch (choice)
		{
			case 1:
				run_table_program();
				break;
			case 2:
				run_list_program();
				break;
			case 3:
				run_heap_program();
				break;
			case 0:
				function_exit = true;
				break;
		}
		system("cls");
	}
}

void show_main_menu()
{
	std::cout << "================================" << std::endl;
	std::cout << "SELECT STRUCTURE" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "1) Table" << std::endl;
	std::cout << "2) List" << std::endl;
	std::cout << "3) Heap" << std::endl;
	std::cout << std::endl;
	std::cout << "0) Exit" << std::endl << std::endl;
}



void run_table_program()
{
	system("cls");
	bool function_exit = false;
	Array *my_array = new Array;

	while (function_exit == false)
	{
		show_array_menu();

		int choice;

		cin >> choice;

		switch (choice)
		{
		case 1:
			read_data_from_file_to_tab(my_array);
			break;
		case 2:
			array_menu_add(my_array);
			break;
		case 3:
			array_menu_delete(my_array);
			break;
		case 4:
			array_menu_find(my_array);
			break;
		case 5:
			array_menu_show(my_array);
			break;
		case 0:
			function_exit = true;
			break;
		}

		system("cls");
	}
}

bool read_data_from_file_to_tab(Array * tab, char * path)
{
	system("cls");

	std::cout << "================================" << std::endl;
	std::cout << "READING DATA FROM FILE" << std::endl;
	std::cout << "Path: " << path << endl;
	std::cout << "================================" << std::endl << std::endl;

	string line;
	ifstream myfile(path);
	bool first_value = true;

	if (myfile.is_open())
	{
		try
		{
			while (getline(myfile, line))
			{
				if (first_value == true)
				{
					cout << "Value at frst line: " <<  line << endl;
					first_value = false;
					continue;
				}
				cout << line << endl;
				int value = std::stoi(line, nullptr, 0);
				tab->push_back(value);
			}
		}
		catch (const std::exception& e) 
		{
			std::cout << "ERROR: can't push all values " << path << std::endl << std::endl;
		}
		myfile.close();
	}
	else
	{
		std::cout << "Unable to read data from file "<< path << std::endl << std::endl;
	}

	system("pause");

	return false;
}

void show_array_menu()
{
	std::cout << "================================" << std::endl;
	std::cout << "SELECT OPTION" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "1) Read form file" << std::endl;
	std::cout << "2) Add" << std::endl;
	std::cout << "3) Delete" << std::endl;
	std::cout << "4) Find" << std::endl;
	std::cout << "5) Show" << std::endl;
	std::cout << endl;
	std::cout << "0) Back to main menu" << std::endl << std::endl;
}

void array_menu_add(Array *tab)
{
	system("cls");

	int index;
	int value;

	std::cout << "================================" << std::endl;
	std::cout << "ADD" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << endl;
	std::cout << "Enter the index: " << std::endl;
	std::cin >> index;
	std::cout << "Enter the value: " << std::endl;
	std::cin >> value;
	std::cout << std::endl;

	tab->push_at(index, value);

	system("pause");
}

void array_menu_delete(Array *tab)
{
	system("cls");

	int index;

	std::cout << "================================" << std::endl;
	std::cout << "DELETE" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << std::endl;
	std::cout << "Enter the index: " << std::endl;
	std::cin >> index;
	std::cout << std::endl;

	tab->pop_at(index);

	system("pause");
}

void array_menu_find(Array *tab)
{

	system("cls");

	int value;

	std::cout << "================================" << std::endl;
	std::cout << "FIND" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << std::endl;
	std::cout << "Enter the value: " << std::endl;
	std::cin >> value;
	std::cout << std::endl;

	if (tab->find(value) == true)
	{
		std::cout << "SUCCES: Value " << value << " was found " << std::endl;
	}
	else
	{
		std::cout << "FAILURE: Can't find value " << value << std::endl;
	}

	system("pause");
}

void array_menu_show(Array *tab)
{
	system("cls");

	std::cout << "================================" << std::endl;
	std::cout << "STRUCTURE" << std::endl;
	std::cout << "================================" << std::endl;

	tab->show();

	std::cout << std::endl;

	system("pause");
}




void run_list_program()
{
	system("cls");
	bool function_exit = false;
	List<int> *list = new List<int>;

	while (function_exit == false)
	{
		show_array_menu();

		int choice;

		cin >> choice;

		switch (choice)
		{
		case 1:
			read_data_from_file_to_list(list);
			break;
		case 2:
			list_menu_add(list);
			break;
		case 3:
			list_menu_delete(list);
			break;
		case 4:
			list_menu_find(list);
			break;
		case 5:
			list_menu_show(list);
			break;
		case 0:
			function_exit = true;
			break;
		}

		system("cls");
	}
}

bool read_data_from_file_to_list(List<int>* list, char * path)
{
	system("cls");
	std::cout << "================================" << std::endl;
	std::cout << "READING DATA FROM FILE" << std::endl;
	std::cout << "Path: " << path << endl;
	std::cout << "================================" << std::endl << std::endl;
	string line;
	ifstream myfile(path);
	bool first_value = true;
	if (myfile.is_open())
	{
		try
		{
			while (getline(myfile, line))
			{
				if (first_value == true)
				{
					cout << "Value at frst line: " << line << endl;
					first_value = false;
					continue;
				}
				cout << line << endl;
				int value = std::stoi(line, nullptr, 0);
				list->push_back(value);
			}
		}
		catch (const std::exception& e)
		{
			std::cout << "ERROR: can't push all values " << path << std::endl << std::endl;
		}
		myfile.close();
	}
	else
	{
		std::cout << "Unable to read data from file " << path << std::endl << std::endl;
	}

	system("pause");

	return false;
}

void show_list_menu()
{
	std::cout << "================================" << std::endl;
	std::cout << "SELECT OPTION" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "1) Read form file" << std::endl;
	std::cout << "2) Add" << std::endl;
	std::cout << "3) Delete" << std::endl;
	std::cout << "4) Find" << std::endl;
	std::cout << "5) Show" << std::endl;
	std::cout << endl;
	std::cout << "0) Back to main menu" << std::endl << std::endl;
}

void list_menu_add(List<int>* list)
{
	system("cls");

	int value1;
	int value2;

	std::cout << "================================" << std::endl;
	std::cout << "ADD" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << endl;
	std::cout << "Enter the first value: " << std::endl;
	std::cin >> value1;
	std::cout << "Enter the second value: " << std::endl;
	std::cin >> value2;
	std::cout << std::endl;

	int index = list->find_index_of_value(value1);
	if (index == -1)
	{
		list->push_front(value2);
		cout << "can't find first value in list" << endl;
		cout << "value has beed added on first index" << endl;
		cout << endl; 
		system("pause");
		return;
		
	}
	if (index == list->get_size() - 1)
	{
		list->push_back(value2);

		system("pause");
		return;
	}

	index += 1;
	list->push_at(index, value2);

	system("pause");
}

void list_menu_delete(List<int>* list)
{
	system("cls");

	int index;

	std::cout << "================================" << std::endl;
	std::cout << "DELETE" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << std::endl;
	std::cout << "Enter the value: " << std::endl;
	std::cin >> index;
	std::cout << std::endl;

	list->pop_at(index);

	system("pause");
}

void list_menu_find(List<int>* list)
{
	system("cls");

	int value;

	std::cout << "================================" << std::endl;
	std::cout << "FIND" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << std::endl;
	std::cout << "Enter the value: " << std::endl;
	std::cin >> value;
	std::cout << std::endl;

	if (list->find(value) == true)
	{
		std::cout << "SUCCES: Value " << value << " was found " << std::endl;
	}
	else
	{
		std::cout << "FAILURE: Can't find value " << value << std::endl;
	}

	system("pause");
}

void list_menu_show(List<int>* list)
{
	system("cls");

	std::cout << "================================" << std::endl;
	std::cout << "STRUCTURE" << std::endl;
	std::cout << "================================" << std::endl;

	list->show();

	std::cout << std::endl;

	system("pause");
}



void run_heap_program()
{
	system("cls");
	bool function_exit = false;
	Heap *heap = new Heap;

	while (function_exit == false)
	{
		show_heap_menu();

		int choice;

		cin >> choice;

		switch (choice)
		{
		case 1:
			read_data_from_file_to_heap(heap);
			break;
		case 2:
			heap_menu_add(heap);
			break;
		case 3:
			heap_menu_delete(heap);
			break;
		case 4:
			heap_menu_find(heap);
			break;
		case 5:
			heap_menu_show(heap);
			break;
		case 0:
			function_exit = true;
			break;
		}

		system("cls");
	}
}

bool read_data_from_file_to_heap(Heap * heap, char * path)
{
	system("cls");

	std::cout << "================================" << std::endl;
	std::cout << "READING DATA FROM FILE" << std::endl;
	std::cout << "Path: " << path << endl;
	std::cout << "================================" << std::endl << std::endl;

	string line;
	ifstream myfile(path);
	bool first_value = true;

	if (myfile.is_open())
	{
		try
		{
			while (getline(myfile, line))
			{
				if (first_value == true)
				{
					cout << "Value at frst line: " << line << endl;
					first_value = false;
					continue;
				}
				cout << line << endl;
				int value = std::stoi(line, nullptr, 0);
				heap->push(value);
			}
		}
		catch (const std::exception& e)
		{
			std::cout << "ERROR: can't push all values " << path << std::endl << std::endl;
		}
		myfile.close();
	}
	else
	{
		std::cout << "Unable to read data from file " << path << std::endl << std::endl;
	}

	system("pause");

	return false;
}

void show_heap_menu()
{
	std::cout << "================================" << std::endl;
	std::cout << "SELECT OPTION" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "1) Read form file" << std::endl;
	std::cout << "2) Add" << std::endl;
	std::cout << "3) Delete" << std::endl;
	std::cout << "4) Find" << std::endl;
	std::cout << "5) Show" << std::endl;
	std::cout << endl;
	std::cout << "0) Back to main menu" << std::endl << std::endl;
}

void heap_menu_add(Heap * heap)
{
	system("cls");

	int value;

	std::cout << "================================" << std::endl;
	std::cout << "ADD" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << endl;

	std::cout << "Enter the value: " << std::endl;
	std::cin >> value;
	std::cout << std::endl;

	heap->push(value);

	system("pause");
}

void heap_menu_delete(Heap * heap)
{
	system("cls");

	int value;

	std::cout << "================================" << std::endl;
	std::cout << "DELETE" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << std::endl;
	std::cout << "Enter the value: " << std::endl;
	std::cin >> value;
	std::cout << std::endl;

	heap->pop(value);

	system("pause");
}

void heap_menu_find(Heap * heap)
{
	system("cls");

	int value;

	std::cout << "================================" << std::endl;
	std::cout << "FIND" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << std::endl;
	std::cout << "Enter the value: " << std::endl;
	std::cin >> value;
	std::cout << std::endl;

	if (heap->find(value) == true)
	{
		std::cout << "SUCCES: Value " << value << " was found " << std::endl;
	}
	else
	{
		std::cout << "FAILURE: Can't find value " << value << std::endl;
	}

	system("pause");
}

void heap_menu_show(Heap * heap)
{
	system("cls");

	std::cout << "================================" << std::endl;
	std::cout << "STRUCTURE" << std::endl;
	std::cout << "================================" << std::endl;

	heap->show();

	std::cout << std::endl;

	system("pause");
}
