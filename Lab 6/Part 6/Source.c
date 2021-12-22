// Name: -----	ID: -----

// ************************ PART 6 ************************

// (Print a string backward) Write a recursive function stringReverse that takes a character array as an argument, prints it back to frontand returns nothing.The function should stop processingand return when the terminating null character of the string is encountered.



#include <stdio.h>

void printBackwards(char string[], int length);

// Program entry function
int main(void)
{

	// Print the title of the project
	puts("--========= String Backwards! =========--");

	// Set char array
	char str[] = "hello world!";
	int str_len = 13;

	puts("\nString forward: ");

	// Print string forward
	for (int i = 0; i != str_len; i++)
	{
		printf("%c", str[i]);
	}

	puts("\nString reversed:");

	// Print string backwards
	printBackwards(str, str_len);

	puts("");

} // End entry function

void printBackwards(char string[], int length)
{
	// If we reached a str length of 0, quit
	if (length == 0)
	{
		return;
	}
	// Otherwise, print the element at the index of the length - 1
	printf("%c", string[length - 1]);
	// and all the function with one less length
	printBackwards(string, length - 1);
}