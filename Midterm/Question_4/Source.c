// Name: -----	ID: -----

// ************************ PART 4 ************************

// C uses integers internally to represent characters. Write a program that reads two letters and compares their integer equivalents. The program has to print the letters, their integer equivalents and the greater value.  For example, if the user types in A and b, the program should print: 

// The first character is Aand its integer equivalent is 65

// The second character is b and its integer equivalent is 98

// The integer equivalent of the second character b(98) is greater


#include <stdio.h>


// Program entry function
int main(void)
{
	// Print the title of the project
	puts("--========= Character Checker =========--");

	// Get the first character
	printf("Enter the first character: ");
	char first_char;
	scanf_s(" %c", &first_char);

	// Get the second character
	printf("Enter the second character: ");
	char second_char;
	scanf_s(" %c", &second_char);

	puts("");

	// Print the character and its int equivalent
	printf("The first chararacter is %c and its integer equivalent is %d\n", first_char, first_char);
	printf("The second chararacter is %c and its integer equivalent is %d\n", second_char, second_char);

	// If the first char is bigger then the second...
	if (first_char > second_char)
	{
		printf("The integer equivalent of the first character %c(%d) is greater!\n", first_char, first_char);
	}
	// If the second char is bigger then the first...
	else if (first_char < second_char)
	{
		printf("The integer equivalent of the second character %c(%d) is greater!\n", second_char, second_char);
	}
	// If they are equal
	else {
		printf("The integer equivalent of the characters are the same!\n");
	}

} // End entry function