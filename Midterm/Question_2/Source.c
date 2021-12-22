// Name: -----	ID: -----

// ************************ PART 2 ************************

// Use a single-subscripted array to solve the following problem. Read the following 20 numbers from keyboard and as each number is read, print it only if it’s not a duplicate of a number already read. Use the smallest possible array to solve this problem.

// InputNumbers = 15, 16, 17, 18, 19, 20, 18, 12, 19, 22, 44, 88, 22, 65, 21, 21, 65, 78, 89, 12// 


#include <stdio.h>

// Define the function signiture
int linearSearchRecursion(int arr[], int size, int target, int index);


// Program entry function
int main(void)
{
	///
	/// NOTE: IF THE PROGRAM FAILS TO RUN PLEASE CONTACT
	/// BLACKBOARD HAS A WEIRD FORMATTING ERROR AND I HAVE
	/// NO IDEA HOW TO FIX IT
	///

	// Print the title of the project
	puts("--========= Anti Duplicate User Input =========--");

	// We define the array to be 20 long because we can take
	// up to 20 different inputs and all 20 COULD be different
	// The zeros are for telling which spot is currently being used
	// which is why the user input must be non-zero
	int numbers[20] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	// Promt the user to enter 20 non-zero numbers
	puts("Please enter 20 non-zero numbers: ");

	// For the 20 numbers the number wants to input
	for (int i = 0; i != 20; i++)
	{

		// Tell the user what number they are input and store it in input
		printf("Enter number %d: ", i + 1);
		int input = 0;
		scanf_s("%d", &input);

		// If the number was found in the array already
		if (linearSearchRecursion(numbers, 20, input, 0) != -1)
		{
			// Tell the user and skip this number
			printf("The number %d was already in the array! Try again...\n", input);
		}
		// Otherwise...
		else {
			// Tell the user we are adding the number to the array
			printf("New number was found! Adding %d to the array...\n", input);

			// For every number in the array...
			for (int i = 0; i != 20; i++)
			{
				// If the spot has a one in it
				if (numbers[i] == 0)
				{
					// Replace that slot with the number the user entered
					numbers[i] = input;
					// and then break
					break;
				}
			}

		}
	}

} // End entry function


int linearSearchRecursion(int arr[], int size, int target, int index)
{
	// If we have reached the end of the array
	if (index == size)
	{
	// Return -1, meaning we didn't find anything
	return -1;
	}
	// If the index we are currently looking at is equal to what we are looking for
	else if (arr[index] == target)
	{
		// return the index
		return index;
	}
	else {
		// Otherwise, return this function called with the index incramented
		return linearSearchRecursion(arr, size, target, index + 1);
	}
}