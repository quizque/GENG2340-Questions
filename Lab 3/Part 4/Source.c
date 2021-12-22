// Name: -----	ID: -----

// ************************ PART 4 ************************

// (Roman  Numeral  Equivalent  of  Decimal  Values)  Write  a  program  that  prints  a  table  of  all  the  Roman  
// numeral equivalents of the decimal numbers in the range 1 to 100.


#include <stdio.h>


// Program entry function
int main(void)
{
	printf("---=== Decimal To Roman Numeral ===---\n");
	printf("Decimal | Roman Numerals\n");

	int count = 1;

	while (count <= 100)
	{

		printf("%d\t| ", count);

		int n = count;

		while (n != 0)
		{
			if (n >= 100)
			{
				printf("C");
				n -= 100;
			}

			else if (n >= 90)
			{
				printf("XC");
				n -= 90;
			}

			else if (n >= 50)
			{
				printf("L");
				n -= 50;
			}

			else if (n >= 40)
			{
				printf("XL");
				n -= 40;
			}

			else if (n >= 10)
			{
				printf("X");
				n -= 10;
			}

			else if (n >= 9)
			{
				printf("IX");
				n -= 9;
			}

			else if (n >= 5)
			{
				printf("V");
				n -= 5;
			}

			else if (n >= 4)
			{
				printf("IV");
				n -= 4;
			}

			else if (n >= 1)
			{
				printf("I");
				n -= 1;
			}
		}
		
		printf("\n");
		count++;
	}



} // End entry function