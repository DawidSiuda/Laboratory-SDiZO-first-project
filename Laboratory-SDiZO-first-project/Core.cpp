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
	Table *table = new Table;

	bool read_data = read_data_from_file_to_structure(table);
	system("cls");
	while (function_exit == false)
	{
		show_list_menu();

		int choice;

		cin >> choice;

		switch (choice)
		{
		case 1:
			list_menu_add(table);
			break;
		case 2:
			list_menu_delete(table);
			break;
		case 3:
			list_menu_find(table);
			break;
		case 4:
			list_menu_show(table);
			break;
		case 0:
			function_exit = true;
			break;
		}

		system("cls");
	}
}

bool read_data_from_file_to_structure(Table * tab, char * path)
{
	std::cout << "================================" << std::endl;
	std::cout << "READING DATA FROM FILE" << std::endl;
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

void show_list_menu()
{
	std::cout << "================================" << std::endl;
	std::cout << "SELECT OPTION" << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "1) Add" << std::endl;
	std::cout << "2) Delete" << std::endl;
	std::cout << "3) Find" << std::endl;
	std::cout << "4) Show" << std::endl;
	std::cout << endl;
	std::cout << "0) Back to main menu" << std::endl << std::endl;
}

void list_menu_add(Table *tab)
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

void list_menu_delete(Table *tab)
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

void list_menu_find(Table *tab)
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

void list_menu_show(Table *tab)
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
}

void run_heap_program()
{
}