// Name: -----	ID: -----

// ************************ PART 3 ************************

// (Binary Search) Modify the  program of Lecture_6 to use a recursive function to perform the binary search of the 
// array.The function should receive an integer arrayand the starting subscriptand ending  subscript as arguments.If the search
// key is found, return the array subscript; otherwise, return –1.


#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int target, int low, int high);

int main(void) {

	int arr[15] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28 };

	puts("---====== Binary Search ======---");
	printf("Enter a number between 0 and 28: ");
	int target = 0;
	scanf_s("%d", &target);

	// ------------------- Print Headers -------------------

	printf("\nIndices: \n");
	for (int i = 0; i != 15; i++)
	{
		printf("%4d", i);
	}

	puts("");
	for (int i = 0; i != 60; i++)
	{
		printf("-");
	}
	puts("");

	int result = binarySearch(arr, target, 0, 15);
	
	if (result != -1) {
		printf("Found the value %d at index %d!\n", target, result);
	}
	else {
		printf("Couldn't find %d in the array!\n", target);
	}
}


int binarySearch(int arr[], int target, int low, int high)
{
	// Get the middle of the array
	int mid = (low + high) / 2;

	// ------------------- Print Table -------------------

	printf(" ");

	// Pretty print the value we are trying to find
	for (int i = 0; i < 15; ++i) {
		// While we are outside the range of number we are checking, put spaces
		if (i < low || i > high) {
			printf("%s", "    ");
		}
		// If we are checking the middle, skip it
		else if (i == mid) { 
			printf("%3d*", arr[i]); 
		}
		// Otherwise, print the number
		else { 
			printf("%3d ", arr[i]);
		}
	}

	puts("");

	// ------------------- Binary Search -------------------

	// if low is greater then high, we failed to find the value
	if (low > high) {
		return -1;
	}

	// If we found the value, return its index
	if (target == arr[mid]) {
		return mid;
	}
	// If the value we found was smaller, call this function with the upper bounds smaller
	else if (target < arr[mid]) {
		return binarySearch(arr, target, low, mid - 1);
	}
	// Otherwise, call this function with the lower bounds higher
	else {
		return binarySearch(arr, target, mid + 1, high);
	}
}