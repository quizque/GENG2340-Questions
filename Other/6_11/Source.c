// Name: -----	ID: -----

// ************************ PART 6.11 ************************

// (Selection Sort) A selection sort algorithm for a one-dimensional array has the following steps:
// a) The smallest value in the array is found.
// b) It is swapped with the value in the first position of the array.
// c) The above steps are repeated for the rest of the array starting at the second positionand
// advancing each time.
// Eventually the entire array is divided into two parts : the sub - array of items already sorted
// which is built up from left to right and is found at the beginning, and the sub - array of
// items remaining to be sorted, occupying the remainder of the array.Write a program
// that sorts an array of 10 integers using this algorithm// 


#include <stdio.h>

void selectionSort(int arr[], int size);
void swapArrIndex(int arr[], int index_one, int index_two);

// Program entry function
int main(void)
{

	// Print the title of the project (optional)
	puts("--========= Selection Sort =========--");

	int numbers[] = { 4, 1, 5, 3, 7, 2, 6, 9, 8, 0 };

	selectionSort(numbers, 10, 0);

	for (int i = 0; i != 10; i++)
	{
		printf("%2d", numbers[i]);
	}

	puts("");

} // End entry function

void selectionSort(int arr[], int size, int start_index)
{
	if (size == start_index)
	{
		return;
	}

	int smallestVal = arr[start_index];
	int smallestIndex = start_index;

	for (int i = start_index; i != size; i++)
	{
		if (arr[i] < smallestVal)
		{
			smallestVal = arr[i];
			smallestIndex = i;
		}
	}

	swapArrIndex(arr, start_index, smallestIndex);
	selectionSort(arr, size, start_index + 1);
}

void swapArrIndex(int arr[], int index_one, int index_two)
{
	int tmp = arr[index_one];
	arr[index_one] = arr[index_two];
	arr[index_two] = tmp;
}