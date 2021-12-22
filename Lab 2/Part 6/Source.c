// Name: -----	ID: -----

// ************************ PART 6 ************************

// Write a program that reads in five integers and then determines and prints the largest and the smallest integers in the group. Use only the single-selection form of the if statement. .


#include <stdio.h>


// Program entry function
int main(void)
{
	int smallest, largest;
	int x, y, z, i, j;

	printf("Enter 5 numbers: ");
	scanf_s("%d%d%d%d%d", &x, &y, &z, &i, &j);

	smallest = x;
	largest = x;

	// Check if y is largest or smallest
	if (y >= largest)
		largest = y;
	if (y <= smallest)
		smallest = y;

	// Check if z is largest or smallest
	if (z >= largest)
		largest = z;
	if (z <= smallest)
		smallest = z;

	// Check if i is largest or smallest
	if (i >= largest)
		largest = i;
	if (i <= smallest)
		smallest = i;

	// Check if j is largest or smallest
	if (j >= largest)
		largest = j;
	if (j <= smallest)
		smallest = j;

	// Print the largest and smallest number
	printf("The largest number is: %d\n", largest);
	printf("The smallest number is: %d\n", smallest);

} // End entry function