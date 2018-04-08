#pragma once

#include "List.h"
#include "Heap.h"
#include "Array.h"

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

//using namespace std::;

void run_main_program();
void show_main_menu();

void run_table_program();
bool read_data_from_file_to_tab(Array *tab, char *path = "data.txt");
void show_array_menu();
void array_menu_add(Array *tab);
void array_menu_delete(Array *tab);
void array_menu_find(Array *tab);
void array_menu_show(Array *tab);

void run_list_program();
bool read_data_from_file_to_list(List<int> *list, char *path = "data.txt");
void show_list_menu();
void list_menu_add(List<int> *list);
void list_menu_delete(List<int> *list);
void list_menu_find(List<int> *list);
void list_menu_show(List<int> *list);


void run_heap_program();
bool read_data_from_file_to_heap(Heap *heap, char *path = "data.txt");
void show_heap_menu();
void heap_menu_add(Heap *heap);
void heap_menu_delete(Heap *heap);
void heap_menu_find(Heap *heap);
void heap_menu_show(Heap *heap);