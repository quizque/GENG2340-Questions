// Name: -----	ID: -----

// ************************ PART 6 ************************

// (Polling) The Internet and the web are enabling more people to network, join a cause, voice opinions, and so on. The U.S. presidential candidates in 2008 used the Internet intensively to get out their messages and raise money for their campaigns. In this exercise, you’ll write a simple polling program that allows users to rate five social-consciousness issues from 1 (least important) to 10 (most important). Pick five causes that are important to you (e.g., political issues, global environmental issues). Use a one-dimensional array topics (of type char *) to store the five causes. To summarize the survey responses, use a 5-row, 10-column two-dimensional array responses (of type int), each row corresponding to an element in the topics array. When the program runs, it should ask the user to rate each issue. Have your friends and family respond to the survey. Then have the program display a summary of the results, including:


// a) A tabular report with the five topics down the left sideand the 10 ratings across the top,

// listing in each column the number of ratings received for each topic.

// b) To the right of each row, show the average of the ratings for that issue.

// c) Which issue received the highest point total ? Display both the issue and the point total.

// d) Which issue received the lowest point total ? Display both the issue and the point total// 


#include <stdio.h>


// Program entry function
int main(void)
{

	// Print the title of the project (optional)
	puts("-----------========= Polling =========-----------");
	puts("10 people will be asked 5 different questions");

	// Define the issues array
	char* issues[5] = {
		"Supporting free tuition",
		"Taxing the rich",
		"Universal basic income",
		"Lowering military funding",
		"Promoting STEM to kids",
	};

	// Store user responces
	int responces[5][10] = { 0 };

	// For every person,
	for (int person = 0; person != 10; person++)
	{
		// Print what you will be doing
		printf("Asking person %d...\n", person + 1);
		printf("You will be asked 5 different questions, please enter a number\n");
		printf("from 1 (least important) - 10 (most important) for each question.\n");

		// Ask each question
		for (int question = 0; question != 5; question++)
		{
			printf("\nOn the following topic:\n\t%s\nWhat is its importants from 1 - 10 for you: ", issues[question]);

			// Store their answer in a responce array
			scanf_s("%d", &responces[question][person]);
		}

		// Formatting
		puts("\n\n\n");
	}

	// Formatting
	puts("\n\n\n");

	// Print table header
	puts("The results of the survey are below:\n");
	printf("%18cPerson |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  10 | average |\n", ' ');

	// Define the highest scoring issue 
	int highestScoring = 0;
	int highestPoints = -1;

	// Define the lowest scoring issue
	int lowestScoring = 0;
	int lowestPoints = 1000;

	// FOr every problem
	for (int question = 0; question != 5; question++)
	{
		// Print the question
		printf("%25s|", issues[question]);

		// Store the average
		int average = 0;

		// Print all the respones for 10 people
		for (int person = 0; person != 10; person++)
		{
			printf(" %3d |", responces[question][person]);
			average += responces[question][person];
		}

		// Print the average
		printf("%6.2f   |", (float)average / 10.0);

		// Update the lowest points issue if a new one is found
		if (lowestPoints > average)
		{
			lowestPoints = average;
			lowestScoring = question;
		}

		// Update the highest points issue if an ew one is found
		if (highestPoints < average)
		{
			highestPoints = average;
			highestScoring = question;
		}

		// Spacing
		puts("");
	}

	// Print the lowest and highest scoring issues with their scores
	printf("\nThe lowest scoring issue was '%s' with %d score\n", issues[lowestScoring], lowestPoints);
	printf("\nThe highst scoring issue was '%s' with %d score\n", issues[highestScoring], highestPoints);
} // End entry function