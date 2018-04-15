#pragma once

#include "List.h"
#include "Heap.h"
#include "Array.h"

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

//
//main menu
//

void run_main_program();
void show_main_menu();

//
//array menu
//

void run_array_program();
bool read_data_from_file_to_arr(Array *arr, char *path = "data.txt");
void show_array_menu();
void array_menu_add(Array *arr);
void array_menu_delete(Array *arr);
void array_menu_find(Array *arr);
void array_menu_show(Array *arr);

//
//list menu
//

void run_list_program();
bool read_data_from_file_to_list(List<int> *list, char *path = "data.txt");
void show_list_menu();
void list_menu_add(List<int> *list);
void list_menu_delete(List<int> *list);
void list_menu_find(List<int> *list);
void list_menu_show(List<int> *list);

//
//heap menu
//

void run_heap_program();
bool read_data_from_file_to_heap(Heap *heap, char *path = "data.txt");
void show_heap_menu();
void heap_menu_add(Heap *heap);
void heap_menu_delete(Heap *heap);
void heap_menu_find(Heap *heap);
void heap_menu_show(Heap *heap);