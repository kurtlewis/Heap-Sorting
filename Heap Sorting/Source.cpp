//Kurt Lewis
//Feb 3 2016
//Implement a visual heap sorter because I need to learn this somehow and it seems pretty cool
#include <iostream>
#include <iomanip>
#include <math.h>

void printArray(int arraySize, int array[]);


int main()
{
	bool min = true;
	const int arraySize = 8;
	int array[arraySize];
	for (int i = 0; i < arraySize; i++)
	{
		array[arraySize] = 0; // set array randomly, look up how to do this in c++
	}
	printArray(arraySize, array);
	char z;
	std::cin >> z;
	return 0;
}

//print the array as a formatted heap
void printArray(int arraySize, int array[])
{
	int rows = ceil(log2((double)arraySize)) * 2 - 1;
	int cellSize = ceil(log((double)arraySize)) + 2;
	int cellsInBottom = pow(2, (rows / 2) - 1);

	for (int row = 0; row < rows; row++)
	{
		for (int cell = 0; cell < cellsInBottom; cell++)
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
		}
		std::cout << std::endl;
	}



}