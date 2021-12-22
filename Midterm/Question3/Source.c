// Name: -----	ID: -----

// ************************ PART 3 ************************

// A right triangle can have sides that are all integers. The set of three integer values for the sides of a right triangle is called a Pythagorean triple. These three sides must satisfy the relationship that the sum of the squares of two of the sides is equal to the square of the hypotenuse. Assume that all sides are less than or equal to 500, write a program to find all Pythagorean triples for side1, side2, and the hypotenuse.


#include <stdio.h>

// Program entry function
int main(void)
{

	// Print the title of the project
	puts("--========= Pythagorean Triple From 1 -> 500  =========--");

	// Store the tripples we find
	int triplesFound = 0;

	// For all side a lengths 1 -> 500
	for (int a = 1; a <= 500; a++)
	{
		// For all side b lengths 1 -> 500
		for (int b = 1; b <= 500; b++)
		{
			// For all side c lengths 1 -> 500
			for (int c = 1; c <= 500; c++)
			{
				// Calculate a^2 + b^2
				int hypot = (float)(a * a) + (float)(b * b);

				// Check if a^2 + b^2 == c^2
				if (hypot == c * c)
				{
					// If they are equal, print the tripple
					printf("The sides %d %d %d are Pythagorean Triples!\n", a, b, c);
					// Increment the tripple count
					triplesFound++;
				}
			}
		}
	}

	// Print the total number of pythangorean triples
	printf("\nWe found %d Pythagorean Triples!", triplesFound);

} // End entry function