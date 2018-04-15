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
//#include <stack>

//using namespace std;

void main()
{
	//run_main_program();
	
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
	
		int mn = 1;
		while (mn <= 10)
		{
			//std::cout << "add " << mn * (size_of_structure/10) << " values to the array in random pleaces" << std::endl;

			timer.start();

			for (int i = 0; i < mn * (size_of_structure/10); i++)
			{
				table.push_front(rand_data[i]);
			}

			auto time_span = timer.stop();

			//std::cout << "Operation took: " << time_span.count() << " seconds !!!" << std::endl;
			//std::cout << std::endl;

			//
			//delete elements to table
			//

			//std::cout << "delete " << mn * (size_of_structure/10) << " values to the table in random pleaces" << std::endl;

			timer.start();

			for (int i = 0; i < mn * (size_of_structure/10); i++)
			{
				table.pop_back();
			}


			time_span = timer.stop();

			//std::cout << "Operation took: " << time_span.count() << " seconds !!!" << std::endl;
			cout << time_span.count() << endl;;
			//std::cout << std::endl;

			mn++;
		}
		std::cout << std::endl;
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
		//add elements to table
		//

		int mn = 1;
		while (mn <= 10)
		{
			//std::cout << "add " << mn*(size_of_structure/10) << " values to the table in random pleaces" << std::endl;

			timer.start();

			for (int i = 0; i < mn*(size_of_structure/10); i++)
			{
				list.push_back(rand_data[i]);
			}


			auto time_span = timer.stop();
			//std::cout << "Operation took: " << time_span.count() << " seconds !!!" << std::endl;
			//std::cout << std::endl;

			//
			//delete elements to table
			//

			//std::cout << "delete " << mn*(size_of_structure/10) << " values to the table in random pleaces" << std::endl;

			timer.start();

			for (int i = 0; i < mn*(size_of_structure/10) ; i++)
			{
				list.pop_back();
			}


			time_span = timer.stop();
			//std::cout << "Operation took: " << time_span.count() << " seconds !!!" << std::endl;
			cout << time_span.count();
			std::cout << std::endl;

			mn++;
		}
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
		//add elements to table
		//

		int mn = 1;
		while (mn <= 10)
		{
			//std::cout << "add " <<mn*(size_of_structure/10)<< " values to the table in random pleaces" << std::endl;

			timer.start();

			for (int i = 0; i <mn*(size_of_structure/10); i++)
			{
				heap.push(rand_data[i]);
			}

			auto time_span = timer.stop();
			//std::cout << "Operation took: " << mn*(size_of_structure/10) << " seconds !!!" << std::endl;
			//cout << time_span.count() << endl;
			//std::cout << std::endl;

			//
			//delete elements to table
			//

			timer.start();

			for (int i = 0; i < mn*(size_of_structure/10); i++)
			{
				heap.pop(rand_data[i]);
			}

			time_span = timer.stop();
			//std::cout << "Operation took: " << time_span.count() << " seconds !!!" << std::endl;
			cout << time_span.count();
			std::cout << std::endl;

			mn++;
		}
	}
	#endif // RUN_TEST_HEAP

	
	system("pause");
	return;
}

