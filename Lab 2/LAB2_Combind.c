// Name: -----	ID: -----

// Write  a  program  that  asks  the  user  to  enter  two  integers, obtains  the  numbers  from  the  user, then  
// prints the larger number followed by the words “is larger”.If the numbers are equal, print the message
// “These  numbers  are  equal.”  Use  only  the  single - selection  form  of  the  if  statement  you  learned  in  this
// chapter.

// ************************ PART 1 ************************

#include <stdio.h>

// Program entry function
int main(void)
{
	// Define ints a, b
	int a, b;

	// Get integer a
	printf("Enter number a: ");
	scanf_s("%d", &a);

	// Get integer b
	printf("Enter number b: ");
	scanf_s("%d", &b);

	// If a is greater then b, print "[a] is larger"
	if (a > b)
	{
		printf("%d is larger.\n", a);
	}

	// If a is less then b, print "[b] is larger"
	if (a < b)
	{
		printf("%d is larger.\n", b);
	}

	// If a is equal to b, print "These numbers are equal"
	if (a == b)
	{
		printf("These numbers are equal.\n");
	}

} // End entry function












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










// Name: -----	ID: -----

// ************************ PART 3 ************************

// Write a program that reads an integer and determines and prints whether it is odd or even. 

#include <stdio.h>


// Program entry function
int main(void)
{
	// Define int a
	int a;

	// Ask user for integer a
	printf("Enter a number: ");
	scanf_s("%d", &a);

	// Use single-line/conditional if statement to check if the number is even/odd and print the result
	if (a % 2 == 1)
		printf("The number is odd\n");
	if (a % 2 == 0)
		printf("The number is even\n");

} // End entry function











// Name: -----	ID: -----

// ************************ PART 4 ************************

// Using only the techniques you learned in this course, write a program that calculates the squares and 
// cubes of the numbers from 0 to 10 and uses tabs to print the following table of values
//
// number  square  cubed
// 0       0       0
// ...     ...     ...
// 10      100     1000

#include <stdio.h>


// Program entry function
int main(void)
{
	// Print the header
	printf("number  square  cube\n");

	// ------- removed------
	// NOTE: While loop wasn't allowed by the prof???
	int i = 0;

	// Print i, i squared, i cubed
	printf("%d\t%d\t%d\n", i, i * i, i * i * i);
	// add one to i
	i = i + 1;

	// Print i, i squared, i cubed
	printf("%d\t%d\t%d\n", i, i * i, i * i * i);
	// add one to i
	i = i + 1;

	// Print i, i squared, i cubed
	printf("%d\t%d\t%d\n", i, i * i, i * i * i);
	// add one to i
	i = i + 1;

	// Print i, i squared, i cubed
	printf("%d\t%d\t%d\n", i, i * i, i * i * i);
	// add one to i
	i = i + 1;

	// Print i, i squared, i cubed
	printf("%d\t%d\t%d\n", i, i * i, i * i * i);
	// add one to i
	i = i + 1;

	// Print i, i squared, i cubed
	printf("%d\t%d\t%d\n", i, i * i, i * i * i);
	// add one to i
	i = i + 1;

	// Print i, i squared, i cubed
	printf("%d\t%d\t%d\n", i, i * i, i * i * i);
	// add one to i
	i = i + 1;

	// Print i, i squared, i cubed
	printf("%d\t%d\t%d\n", i, i * i, i * i * i);
	// add one to i
	i = i + 1;

	// Print i, i squared, i cubed
	printf("%d\t%d\t%d\n", i, i * i, i * i * i);
	// add one to i
	i = i + 1;

	// Print i, i squared, i cubed
	printf("%d\t%d\t%d\n", i, i * i, i * i * i);
	// add one to i
	i = i + 1;

	// Print i, i squared, i cubed
	printf("%d\t%d\t%d\n", i, i * i, i * i * i);
	// add one to i
	i = i + 1;
		
} // End entry function










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












// Name: -----	ID: -----

// ************************ PART 7 ************************

// Write a program that reads in two integers and determines and prints if the first is a multiple of the second. [Hint: Use the remainder operator]


#include <stdio.h>


// Program entry function
int main(void)
{
	int x, y;

	// Ask the user for two numbers
	printf("Enter two numbers: ");
	scanf_s("%d%d", &x, &y);

	// Check if the remainder is zero
	if (x % y == 0)
		printf("%d is a multiple of %d\n", x, y);

	// If the remainder is not zero
	if (x % y != 0)
		printf("%d is NOT a multiple of %d\n", x, y);


} // End entry function












// Name: -----	ID: -----

// ************************ PART 8 ************************

// Write a program that inputs one five-digit number, separates the number into its individual digits and prints the digits separated from one another by three spaces each. [Hint: Use combinations of integer division and the remainder operation.] For example, if the user types in 42139, the program should print  4   2   1   3   9


#include <stdio.h>


// Program entry function
int main(void)
{

	int number;

	// Ask user for a number
	printf("Enter a five digit number: ");
	scanf_s("%d", &number);

	// Get first number
	printf("The seperated digits are: %d   ", number / 10000);

	// Get second number
	number -= (number / 10000) * 10000;
	printf("%d   ", number / 1000);

	// Get third number
	number -= (number / 1000) * 1000;
	printf("%d   ", number / 100);

	// Get fourth number
	number -= (number / 100) * 100;
	printf("%d   ", number / 10);

	// Get fifth number
	number -= (number / 10) * 10;
	printf("%d\n", number);


} // End entry function