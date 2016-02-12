//Kurt Lewis
//Feb 3 2016
//Implement a visual heap sorter because I need to learn this somehow and it seems pretty cool
#include <iostream>
#include <iomanip>
#include <math.h>
#include <time.h>
#include <stdlib.h>

void sortHeap(int array[], int arraySize, bool min);
int sortHeapStep(int array[], int arraySize, int sortedSize, bool min);
void printArray(int arraySize, int sortedSize, int array[]);

int main()
{
	bool min = false;
	const int arraySize = 31;
	int array[arraySize];
	srand((unsigned)time(0));
	for (int i = 0; i < arraySize; i++)
	{
		array[i] = rand() % arraySize + 1;
	}
	printArray(arraySize, 0, array);
	std::cin.ignore();
	system("cls");
	sortHeap(array, arraySize, min);

	char z;
	std::cin >> z;
	return 0;
}


//sort the heap for minimum of maximum value

void sortHeap(int array[], int arraySize, bool min)
{
	int status = 0;
	int sortedSize = 0;
	do
	{
		do
		{
			status = sortHeapStep(array, arraySize, sortedSize, min);
			printArray(arraySize, sortedSize, array);
			std::cin.ignore();
			system("cls");
		} while (status == 0);
		int temp = array[arraySize - 1 - sortedSize];
		array[arraySize - 1 - sortedSize] = array[0];
		array[0] = temp;
		sortedSize++;
	} while (arraySize - 1 != sortedSize);
	std::cout << "Sorting finished." << std::endl << std::endl;
	printArray(arraySize, sortedSize, array);
}

//completes one step of sorting the heap
// returns 1 for completed sort
//         0 for incomplete sort
int sortHeapStep(int array[], int arraySize, int sortedSize, bool min)
{
	for (int i = 0; i < arraySize - sortedSize; i++)
	{
		if (i * 2 + 1 < arraySize - sortedSize)
		{
			if (min)
			{
				if (array[i] > array[2 * i + 1])
				{
					int temp = array[i];
					array[i] = array[2 * i + 1];
					array[2 * i + 1] = temp;
					return 0;
				}
			}
			else
			{
				if (array[i] < array[2 * i + 1])
				{
					int temp = array[i];
					array[i] = array[2 * i + 1];
					array[2 * i + 1] = temp;
					return 0;
				}
			}
			if (i * 2 + 2 < arraySize - sortedSize)
			{
				if (min)
				{
					if (array[i] > array[2 * i + 2])
					{
						int temp = array[i];
						array[i] = array[2 * i + 2];
						array[2 * i + 2] = temp;
						return 0;
					}
				}
				else
				{
					if (array[i] < array[2 * i + 2])
					{
						int temp = array[i];
						array[i] = array[2 * i + 2];
						array[2 * i + 2] = temp;
						return 0;
					}
				}
			}
		}
	}

	return 1;
}


//print the array as a formatted heap
void printArray(int arraySize, int sortedSize, int array[])
{
	//for when I implement the arrows between rows of numbers
	int formatRows = ceil(log2((double)arraySize - sortedSize)) * 2 - 1;
	//temporary for no lines between numbers
	int rows = ceil(log2((double)arraySize - sortedSize));
	//The size of a cell is the number of digits in the largest number + 2
	int cellSize = ceil(log10((double)arraySize - sortedSize)) + 2;
	int cellsInBottom = pow(2, rows - 1);
	int lineSize = cellSize * cellsInBottom;
	int index = 0;

	if (sortedSize > 0)
	{
		std::cout << "Currently sorted: ";
			for (int i = arraySize - sortedSize; i < arraySize; i++)
			{
				std::cout << array[i] << " ";
			}
			std::cout << std::endl << std::endl;
	}

	for (int row = 0; row < formatRows; row++)
	{	
		if (row % 2 == 0)
		{
				// even rows are for numbers
				int pos = 1;
				for (int cell = 0; cell < cellsInBottom; cell++)
				{
					int nextCell = ((cellsInBottom / (pow(2, ceil((row + 1) / 2)))) * pos) - 1;
					if (cell == nextCell && index < arraySize - sortedSize) // its a cell I want
					{
						// I need to add one to the value of array[index], because log10(any multiple of 10)
						//will return a value that is one less than the actual number of digits
						for (int i = 1; i < cellSize - ceil(log10((double)array[index] + 1)); i++)
						{
							std::cout << " ";
						}
						std::cout << array[index] << " ";
						index++;
						pos++;
					}
					else
					{
						for (int i = 0; i < cellSize; i++)
						{
							std::cout << " ";
						}
					}
				}
		}
		else
		{
			// odd rows are for arrows
			int upPos, downPos, upNextCell, downNextCell;
			bool betweenParentAndChild = false;
			upPos = 1;
			downPos = 1;
			for (int cell = 0; cell < cellsInBottom; cell++)
			{
				upNextCell = ((cellsInBottom / (pow(2, ceil((row) / 2)))) * upPos) - 1;
				downNextCell = ((cellsInBottom / (pow(2, ceil((row + 2) / 2)))) * downPos) - 1;
				if (cell == upNextCell)
				{
					for (int i = 1; i < cellSize - ceil(log10(arraySize)); i++)
					{
						std::cout << "-";
					}
					std::cout << "/| ";
					betweenParentAndChild = false;
					upPos++;
					// Every other cell in the row below will match up with the cell of the row above it
					if (upNextCell == downNextCell)
					{
						downPos++;
					}
				}
				else if (cell == downNextCell)
				{
					for (int i = 0; i < cellSize - ceil(log10(arraySize)); i++)
					{
						std::cout << " ";
					}
					std::cout << "/-";
					betweenParentAndChild = true;
					downPos++;
				}
				else if (betweenParentAndChild)
				{
					for (int i = 0; i < cellSize; i++)
					{
						std::cout << "-";
					}
				}
				else
				{
					for (int i = 0; i < cellSize; i++)
					{
						std::cout << " ";
					}
				}
			}
			std::cout << std::endl;
		}

		
		std::cout << std::endl;
	}
}