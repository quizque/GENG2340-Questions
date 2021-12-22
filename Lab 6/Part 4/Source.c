// Name: -----	ID: -----

// ************************ PART 4 ************************

// // (Airline Reservations System) A small airline has just purchased a computer for its new automated reservations system.The president has asked you to program the new system.You’ll write a program to assign seats on each flight of the airline’s only plane(capacity: 10 seats).Your program should display the following menu of alternatives :

// Please type 1 for "first class"
// Please type 2 for "economy"

// If the person types 1, then your program should assign a seat in the first class section(seats 1– 5).If the person types 2, then your program should assign a seat in the economy section(seats 6– 10).Your program should then print a boarding pass indicating the person's seat number and whether it’s in the first class or economy section of the plane. Use a single-subscripted array to represent the seating chart of the plane. Initialize all the elements of the array to 0 to indicate that all seats are empty. As each seat is assigned, set the corresponding element of the array to 1 to indicate that the seat is no longer available. Your program should, of course, never assign a seat that has already been assigned. When the first class section is full, your program should ask the person if it’s acceptable to be placed in the economy section (and vice versa). If yes, then make the appropriate seat assignment. If no, then print the message "Next flight leaves in 3 hours."



#include <stdio.h>

void print_ticket(int seat_number);

// Program entry function
int main(void)
{
	// Define the seats
	int seating[10] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	int econs_counter = 0;
	int first_counter = 5;

	// Print the title of the project
	puts("--========= Airline Reservation System =========--");

	// Store if all the seats are taken or not
	int status = 1;

	// While status is not -1,
	while (status != -1 && !(econs_counter == 5 && first_counter == 10))
	{
		// Ask for user input
		puts("Please type 1 for \"first class\"");
		puts("Please type 2 for \"economy\"");

		int input;
		printf(": ");
		scanf_s("%d", &input);

		// If the user wants a first class ticket
		if (input == 1)
		{
			puts("\nChecking for the next available \"first class\" seat...\n");

			// If the seat is not taken and we have less then 5 seats
			if (!seating[first_counter] && first_counter < 10)
			{
				// Print we found a seat
				printf("We found a seat available at seat %d!\n", first_counter + 1);

				// Set the seats to 1 since we found a seat
				seating[first_counter] = 1;
				// print the ticket
				print_ticket(first_counter + 1);
				// increment the counter
				first_counter++;
			}
			else {
				// All the seats are taken, offer a seat in econ class
				printf("Sorry, all the \"first class\" seats are taken, would you like a economy seat instead? (1: Yes, 2: No)");

				printf(": ");
				scanf_s("%d", &input);

				// If they say yes
				if (input == 1) {

					// If there is a seat available and we havn't reached the max econs counter
					if (!seating[econs_counter] && econs_counter < 5)
					{
						// Print the seat is aviable
						printf("We found a seat available at seat %d!\n", econs_counter + 1);
						// Set the seats to 1 since we found a seat
						seating[econs_counter] = 1;
						// Print the ticket
						print_ticket(econs_counter + 1);
						// Increment the counter
						econs_counter++;
					}
					else {
						// Otherwise, tell them the flight is full
						printf("Sorry, the flight is full. Please book a later flight!\n");
						printf("Next flight leaves in 3 hours!\n");
						break;
					}
				}
				else {
					// Tell them the next flight leaves in 3 hours
					printf("Next flight leaves in 3 hours!\n");
				}
			}

		}
		// If the user wants a econ seat
		else {
			puts("\nChecking for the next available \"economy\" seat...\n");

			// If the seat is not taken and we have less then 5 seats
			if (!seating[econs_counter] && econs_counter < 5)
			{
				// Print the seat is aviable
				printf("We found a seat available at seat %d!\n", econs_counter + 1);
				// Set the seats to 1 since we found a seat
				seating[econs_counter] = 1;
				// Print the ticket
				print_ticket(econs_counter + 1);
				// Increment the counter
				econs_counter++;
			}
			else {
				// Otherwise, print that the seats are taken and offer a first class seat instead
				printf("Sorry, all the \"economy\" seats are taken, would you like a first class seat instead? (1: Yes, 2: No)");

				printf(": ");
				scanf_s("%d", &input);

				// If they accept
				if (input == 1) {

					// If the seat is not taken and we have less then 5 seats
					if (!seating[first_counter] && first_counter < 10)
					{
						// Print the seat is aviable
						printf("We found a seat available at seat %d!\n", first_counter + 1);
						// Set the seats to 1 since we found a seat
						seating[first_counter] = 1;
						// Print the ticket
						print_ticket(first_counter + 1);
						// Increment the counter
						first_counter++;
					}
					else {
						// Otherwise, the flight is full
						printf("Sorry, the flight is full. Please book a later flight!\n");
						printf("Next flight leaves in 3 hours!\n");
						break;
					}
				}
				else {
					// If they decline the offer for a seat in first class, tell them the next flight is in 3 hours
					printf("Next flight leaves in 3 hours!\n");
				}
			}
		}
	}

	// The seats are all taken, quit the program
	printf("\n\nAll seats have been taken! Time for take off!\n");
	printf("Quitting program...\n");
} // End entry function


void print_ticket(int seat_number)
{
	// Pretty print the ticket
	printf("Heres your plane ticket:\n");
	printf("/-----------------------------------------\\\n");
	printf("|    Seat Number:%3d                      |\n", seat_number);
	printf("|    Takeoff Time : 1 : 00PM              |\n");
	printf("\\-----------------------------------------/\n");
	printf("Have a great flight!\n\n");
}