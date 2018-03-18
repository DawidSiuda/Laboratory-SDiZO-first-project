#include "Flags.h"

#include "List.h"

#include <iostream>
#include <Windows.h>



using namespace std;

void main()
{

	List<int> list;


	for (int i = 0; i < 150; i+=17)
	{
		//list.push_front(static_cast<char>(i));
		list.push_front(i);
	}

	list.show();

	list.pop_front();
	list.pop_front();

	list.show();

	system("pause");




	//List<char> list;


	
	return;

}