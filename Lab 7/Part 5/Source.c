// Name: -----	ID: -----

// ************************ PART 5 ************************

// Rewrite the program of Fig.6.22.pdf  to use a menu-driven interface. The program should offer the user four options as follows:


// Enter a choice :

// 0 Print the array of grades

// 1 Find the minimum grade

// 2 Find the maximum grade

// 3 Print the average on all tests for each student

// 4 End program

// One restriction on using arrays of pointers to functions is that all the pointers must have the same type.The pointers must be to functions of the same return type that receive arguments of the same type.For this reason, the functions in Fig. 6.22 must be modified so that they each return the same type and take the same parameters.Modify functions minimum and maximum to print the minimum or maximum value and return nothing.For option 3, modify function average of Fig. 6.22 to output the average for each student(not a specific student).Function average should return nothing and take the same parameters as printArray, minimumand maximum.Store the pointers to the four functions in array processGradesand use the choice made by the user as the subscript into the

// array for calling each function

#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

/* function prototypes */
int minimum(const int grades[][EXAMS], int pupils, int tests);
int maximum(const int grades[][EXAMS], int pupils, int tests);
double average(const int setOfGrades[], int tests);
void printArray(const int grades[][EXAMS], int pupils, int tests);

void printArrayOfGrades(const int studentGrades[STUDENTS][EXAMS]);
void getMinimumGrade(const int studentGrades[STUDENTS][EXAMS]);
void getMaximumGrade(const int studentGrades[STUDENTS][EXAMS]);
void getAverage(const int studentGrades[STUDENTS][EXAMS]);

int main(void)
{

		/* initialize student grades for three students (rows) */
	const int studentGrades[STUDENTS][EXAMS] = {
		{ 77, 68, 86, 73 },
		{ 96, 87, 89, 78 },
		{ 70, 90, 86, 81 }
	};

	// Store pointer for functions
	void (*processGrades[4])(void) = {
		printArrayOfGrades,
		getMinimumGrade,
		getMaximumGrade,
		getAverage
	};

	// Store the option the user wants
	int menuOption = 1;

	while (1)
	{
		// Print the menu
		puts("\n\n");
		puts("0 Print the array of grades");
		puts("1 Find the minimum grade");
		puts("2 Find the maximum grade");
		puts("3 Print the average on all tests for each student");
		puts("4 End program\n");

		// Get user input
		printf("Enter an option: ");
		scanf_s("%d", &menuOption);
		puts("\n");

		// If its 4, leave
		if (menuOption == 4)
		{
			return;
		}

		// Otherwise, call the pointer to the function
		(*processGrades[menuOption]) (studentGrades);
	}
	

	return 0; /* indicates successful termination */
} /* end main */

void getAverage(const int studentGrades[STUDENTS][EXAMS])
{
	/* calculate average grade for each student */
	for (int student = 0; student < STUDENTS; student++) {
		printf("The average grade for student %d is %.2f\n",
			student, average(studentGrades[student], EXAMS));

	} /* end for */
}

void getMaximumGrade(const int studentGrades[STUDENTS][EXAMS])
{
	printf("\nHighest grade: %d\n",
		maximum(studentGrades, STUDENTS, EXAMS));
}

void getMinimumGrade(const int studentGrades[STUDENTS][EXAMS])
{
	printf("\nLowest grade: %d\n",
		minimum(studentGrades, STUDENTS, EXAMS));
}

void printArrayOfGrades(const int studentGrades[STUDENTS][EXAMS])
{
	printf("The array is:\n");
	printArray(studentGrades, STUDENTS, EXAMS);
}


/* Find the minimum grade */
int minimum(const int grades[][EXAMS], int pupils, int tests)
{
	int i; /* student counter */
	int j; /* exam counter */
	int lowGrade = 100; /* initialize to highest possible grade */

		/* loop through rows of grades */
	for (i = 0; i < pupils; i++) {

		/* loop through columns of grades */
		for (j = 0; j < tests; j++) {

			if (grades[i][j] < lowGrade) {
				lowGrade = grades[i][j];

			} /* end if */

		} /* end inner for */

	} /* end outer for */

	return lowGrade; /* return minimum grade */
} /* end function minimum */

/* Determine the average grade for a particular student */
double average(const int setOfGrades[], int tests)
{
	int i; /* exam counter */
	int total = 0; /* sum of test grades */

	/* total all grades for one student */
	for (i = 0; i < tests; i++) {
		total += setOfGrades[i];
	} /* end for */

	return (double)total / tests; /* average */
} /* end function average */

/* Find the maximum grade */
int maximum(const int grades[][EXAMS], int pupils, int tests)
{
	int i; /* student counter */
	int j; /* exam counter */
	int highGrade = 0; /* initialize to lowest possible grade */

		/* loop through rows of grades */
	for (i = 0; i < pupils; i++) {

		/* loop through columns of grades */
		for (j = 0; j < tests; j++) {

			if (grades[i][j] > highGrade) {
				highGrade = grades[i][j];

			} /* end if */

		} /* end inner for */

	} /* end outer for */

	return highGrade; /* return maximum grade */
} /* end function maximum */


/* Print the array */
void printArray(const int grades[][EXAMS], int pupils, int tests)
{
	int i; /* student counter */
	int j; /* exam counter */

		/* output column heads */
	printf("                 [0]  [1]  [2]  [3]");

	/* output grades in tabular format */
	for (i = 0; i < pupils; i++) {

		/* output label for row */
		printf("\nstudentGrades[%d] ", i);
		/* output grades for one student */
		for (j = 0; j < tests; j++) {
			printf("%-5d", grades[i][j]);

		} /* end inner for */

	} /* end outer for */
} /* end function printArray */