#pragma once

#include "List.h"
#include "Heap.h"
#include "Table.h"

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

//using namespace std::;

void run_main_program();
void show_main_menu();

void run_table_program();
bool read_data_from_file_to_structure(Table *tab, char *path = "data.txt");
void show_list_menu();
void list_menu_add(Table *tab);
void list_menu_delete(Table *tab);
void list_menu_find(Table *tab);
void list_menu_show(Table *tab);

void run_list_program();
void run_heap_program();