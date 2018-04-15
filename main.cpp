#include "Flags.h"

#include "List.h"
#include "Heap.h"
#include "Array.h"

#include "Core.h"
#include "Timer.h"

#include <iostream>
#include <Windows.h>
#include <chrono>

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

void main()
{
	run_main_program();
	
	//
	//TEST ARRAY
	//
	#ifdef RUN_TEST_ARRAY
	{
		//
		//create source array
		//

		const int size_of_structure = 100000;
		//const int size_of_structure = 100;
		int rand_data[size_of_structure];
		std::srand(time(NULL));
		for (int i = 0; i < size_of_structure; i++)
		{
			rand_data[i] = rand();
		}

		Timer timer;

		std::cout << "===================================" << std::endl;
		std::cout << "TEST ARRAY" << std::endl;
		std::cout << "===================================" << std::endl;

		Array table;

		//
		//add elements to table
		//

	}
	#endif //RUN_TEST_ARRAY

	//
	//TEST LIST
	//
	#ifdef RUN_TEST_LIST
	{
		//
		//create source array
		//
		
		const int size_of_structure = 100000;
		//const int size_of_structure = 100;
		int rand_data[size_of_structure];
		std::srand(time(NULL));
		for (int i = 0; i < size_of_structure; i++)
		{
			rand_data[i] = rand();
		}

		Timer timer;

		std::cout << "===================================" << std::endl;
		std::cout << "TEST LIST" << std::endl;
		std::cout << "===================================" << std::endl;
		List<int> list;


		//
		//add elements to list
		//

	}
	#endif //RUN_TEST_LIST

	//
	//TEST HEAP
	//
	#ifdef RUN_TEST_HEAP
	{
		//
		//create source array
		//

		const int size_of_structure = 100000;
		//const int size_of_structure = 100;
		int rand_data[size_of_structure];
		std::srand(time(NULL));
		for (int i = 0; i < size_of_structure; i++)
		{
			rand_data[i] = rand();
		}

		Timer timer;

		std::cout << "===================================" << std::endl;
		std::cout << "TEST HEAP" << std::endl;
		std::cout << "===================================" << std::endl;

		Heap heap;


		//
		//add elements to heap
		//

		
	}
	#endif // RUN_TEST_HEAP

	
	system("pause");
	return;
}

