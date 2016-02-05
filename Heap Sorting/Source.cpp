//Kurt Lewis
//Feb 3 2016
//Implement a visual heap sorter because I need to learn this somehow and it seems pretty cool
#include <iostream>
#include <iomanip>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void sortHeap(int array[], int arraySize, bool min);
int sortHeapStep(int array[], int arraySize, bool min);
void printArray(int arraySize, int array[]);

int main()
{
	bool min = true;
	const int arraySize = 20;
	int array[] = { 10, 4, 9, 2, 6, 7, 1, 0, 3, 5, 8, 12, 18, 16, 11, 14, 17, 13, 15, 19};
	/*for (int i = 0; i < arraySize; i++)
	{
		time_t seconds;
		time(&seconds);
		srand((unsigned int)seconds);
		array[i] = rand() % arraySize + 1;
	}*/
	printArray(arraySize, array);


	char z;
	std::cin >> z;
	return 0;
}


//sort the heap for minimum of maximum value

void sortHeap(int array[], int arraySize, bool min)
{

}

//completes one step of sorting the heap
// returns 1 for completed sort
//         0 for incomplete sort
int sortHeapStep(int array[], int arraySize, bool min)
{

	return 0;
}


//print the array as a formatted heap
void printArray(int arraySize, int array[])
{
	//for when I implement the arrows between rows of numbers
	//int rows = ceil(log2((double)arraySize)) * 2 - 1;
	//temporary for no lines between numbers
	int rows = ceil(log2((double)arraySize));
	//The size of a cell is the number of digits in the largest number + 2
	int cellSize = ceil(log((double)arraySize)) + 2;
	int cellsInBottom = pow(2, (rows / 2) - 1);

	for (int row = 0; row < rows; row++)
	{
		for (int i = pow(2, row) - 1; i < 2 * pow(2, row) - 1; i++)
		{
			std::cout << array[i] << " ";
			if (i > arraySize - 2)
			{
				break;
			}
		}
		/*for (int cell = 0; cell < cellsInBottom; cell++)
		{
			if (false) // its a cell I want
			{

			}
			else
			{
				for (int i = 0; i < cellSize; i++)
				{
					std::cout << " ";
				}
			}
		}*/
		std::cout << std::endl;
	}
}