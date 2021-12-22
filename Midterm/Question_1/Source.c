// Name: -----	ID: -----

// ************************ PART 1 ************************

// Write a recursive program to visualize factorial. For each recursive call, display the outputs on a separate line and add a level of indentation as shown below.

// 0!= 1
// 1!= 1
// number = 2
// 2!= 2
// number = 3
// number = 2
// 3!= 6


#include <stdio.h>

// Define the function signiture
int factorialRecursive(int num);


// Program entry function
int main(void)
{
	///
	/// NOTE NOTE NOTE NOTE
	/// If the code doesn't work, PLEASE EMAIL ME
	/// Blackboard has a formatting error that I have no idea how to fix
	/// 

	// Print the title of the project (optional)
	puts("--========= Recursive Factorial Pretty Print =========--");

	// Pretty print the first 12 factorials
	for (int i = 0; i != 12; i++)
	{
		printf("%d! = %d\n\n", i, factorialRecursive(i));
	}

} // End entry function

int factorialRecursive(int num)
{
	// If the number is 2, we can quit
	if (num == 2)
	{
		// Print the digit first
		printf("\tnumber = %d\n", num);
		// Then return
		return 2;
	}

	// If its 0 or 1, just return, don't print
	if (num == 0 || num == 1)
	{
		return 1;
	}

	// Print the number we are currently dealing with
	printf("\tnumber = %d\n", num);

	// Return the number times a call to the factorial function 
	return num * factorialRecursive(num - 1);
}