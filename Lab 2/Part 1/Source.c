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