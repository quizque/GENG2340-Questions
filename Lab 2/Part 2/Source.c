// Name: -----	ID: -----

// ************************ PART 2 ************************

// Write a program that reads in the radius of a circle and prints the circle’s diameter, circumference and 
// area.Use  the  constant  value  3.14159  for pi.Perform  each  of  these  calculations  inside  the  printf
// statement(s) and use the conversion specifier% f.

#include <stdio.h>


// Program entry function
int main(void)
{
	// Define two doubles, radius and pi
	int radius;

	// Get radius from the user
	printf("Enter radius of circle: ");
	scanf_s("%d", &radius);

	// Calculate and print the diameter, circumference, and area
	printf("The diameter is: %f\n", 2.0 * radius);
	printf("The circumference is: %f\n", 3.14159 * 2 * radius);
	printf("The area is: %f\n", 3.14159 * radius * radius);

} // End entry function