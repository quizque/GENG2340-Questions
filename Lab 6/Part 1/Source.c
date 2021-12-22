// Name: -----	ID: -----

// ************************ PART 1 ************************

// (Bubble Sort) The bubble sort presented in Lecture_6 is inefficient for large arrays. Make the following simple modifications 
// to improve the performance of the bubble sort.

// After the first pass, the largest number is guaranteed to be in the highest - numbered element of the array; after the second pass,
// the two highest numbers are “in place, ”and so on.Instead of making nine comparisons on every pass, modify the bubble sort to
// make eight comparisons on the second pass, seven on the third passand so on.The data in the array may already be in the proper
// order or near - proper order, so why make nine passes if fewer will suffice ? Modify the sort to check at the end of each pass whether
// any swaps have been made.If none has been made, then the data must already be in the proper order, so the program should
// terminate.If swaps have been made, then at least one more pass is needed.


#include <stdio.h>

void bubble_sort(int arr[], int size);

// Program entry function
int main(void)
{
	int arr[10] = {
		2, 6, 4, 8, 10, 12, 89, 68, 45, 37
	};

	// Print the title of the project (optional)
	puts("--========= Modded Bubble Sort =========--");

	// Print the unsorted array
	puts("Unsorted array:");
	for (int i = 0; i != 10; i++)
		printf("%d ", arr[i]);

	// run bubble sort on the arr with size 10
	bubble_sort(arr, 10);

	// Print the sorted array
	puts("\nSorted array:");
	for (int i = 0; i != 10; i++)
		printf("%d ", arr[i]);

	puts("");


} // End entry function

void bubble_sort(int arr[], int size)
{
	// For make {size} passes on the arr
	for (int pass = 1; pass < size; ++pass) {

		// Store if we proformed a swap
		int performedSwap = 0;

		// Loop from 0 to {size} minus the amount of passes we have made already
		for (size_t i = 0; i < size - pass; ++i) {

			// If x is greater then x + 1, swap
			if (arr[i] > arr[i + 1]) {
				int hold = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = hold;

				// Set performed swap to 1 since we performed a swap
				performedSwap = 1;
			}
		}

		// If we didn't perform a swap, leave
		if (!performedSwap)
			return;
	}
}