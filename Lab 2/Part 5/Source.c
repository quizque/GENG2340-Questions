// Name: -----	ID: -----

// ************************ PART 5 ************************

//Write a program that inputs three different integers from the keyboard, then prints the sum, the average, the product, the smallestand the largest of these numbers.Use only the single - selection form of the if statement.Try your program with 13, 27 and 14.The screen dialogue should appear as follows :
// 
// Input three different integers : 13 27 14
// Sum is 54
// Average is 18
// Product is 4914
// Smallest is 13
// Largest is 27



#include <stdio.h>


// Program entry function
int main(void)
{
	// Define x, y ,z
	int x, y, z;

	// Get 3 numbers and store them in x, y, z
	printf("Input three different integers: ");
	scanf_s("%d%d%d", &x, &y, &z);
	
	// Print sum
	printf("Sum is %d\n", x + y + z);

	// Print average
	// NOTE: Prof said not to use float??
	printf("Average is %d\n", (x + y + z) / 3);

	// Print product
	printf("Product is %d\n", x * y * z);

	// Calculation for smallest and largest
	int smallest = x, largest = x;

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

	// Print smallest
	printf("Smallest is %d\n", smallest);

	// Print largest
	printf("Largest is %d\n", largest);

} // End entry function