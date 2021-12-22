// Name: -----	ID: -----
// ************************ PART 4.10 ************************

// .... check book



#include <stdio.h>


// Program entry function
int main(void)
{
	int counter[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	int userInput = 0;

	while (userInput != -1)
	{
		printf("Enter employee gross sales (-1 to end): ");
		scanf_s("%d", &userInput);

		if (userInput == -1)
		{
			break;
		}

		float calculatedCommission = 200.0 + 0.09 * (double)userInput;

		printf("Employee Commission is $%0.2f\n\n", calculatedCommission);

		if (200.0 <= calculatedCommission && calculatedCommission <= 299.0)
		{
			counter[0]++;
		}
		else if (300.0 <= calculatedCommission && calculatedCommission <= 399.0)
		{
			counter[1]++;
		}
		else if (400.0 <= calculatedCommission && calculatedCommission <= 499.0)
		{
			counter[2]++;
		}
		else if (500.0 <= calculatedCommission && calculatedCommission <= 599.0)
		{
			counter[3]++;
		}
		else if (600.0 <= calculatedCommission && calculatedCommission <= 699.0)
		{
			counter[4]++;
		}
		else if (700.0 <= calculatedCommission && calculatedCommission <= 799.0)
		{
			counter[5]++;
		}
		else if (800.0 <= calculatedCommission && calculatedCommission <= 899.0)
		{
			counter[6]++;
		}
		 else if (900.0 <= calculatedCommission && calculatedCommission <= 999.0)
		{
			counter[7]++;
		}
		else {
			counter[8]++;
		}
	}


	printf("\nEmployees in this range:\n");
	printf("$200-$299 : %d\n", counter[0]);
	printf("$300-$399 : %d\n", counter[1]);
	printf("$400-$499 : %d\n", counter[2]);
	printf("$500-$599 : %d\n", counter[3]);
	printf("$600-$699 : %d\n", counter[4]);
	printf("$700-$799 : %d\n", counter[5]);
	printf("$800-$899 : %d\n", counter[6]);
	printf("$900-$999 : %d\n", counter[7]);
	printf("Over $1000 : %d\n", counter[8]);


} // End entry function