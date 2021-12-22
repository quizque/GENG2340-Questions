// Name: -----	ID: -----

// ************************ PART 6.32 ************************

// (Linear Search) Modify the program of Fig. 6.18 to use a recursive linearSearch function
// to perform the linear search of the array.The function should receive an integer array, the size of
// the arrayand the search key as arguments.If the search key is found, return the array index; otherwise, return –1.


#include <stdio.h>

int linearSearchRecursion(int arr[], int size, int target, int index);


// Program entry function
int main(void)
{

	// Print the title of the project (optional)
	puts("--========= Linear Search Recursion =========--");

	int numbers[10] = {
		1, 8, 2, 3, 6, 5, 4, 9, 0, 7,
	};

	int target = 4;

	printf("The number %d was found at index %d!\n", target, linearSearchRecursion(numbers, 10, target, 0));


} // End entry function

int linearSearchRecursion(int arr[], int size, int target, int index)
{
	if (arr[index] == target)
	{
		return index;
	}
	else if (index == size) 
	{
		return -1;
	}
	else {
		return linearSearchRecursion(arr, 10, target, index + 1);
	}
}