// Name: -----    ID: -----

// ************************ PART 1 ************************

// (Parking Charges) A parking garage charges a $2.00 minimum fee to park for up to three hours and an
// additional  $0.50  per  hour  for  each  hour or part  thereof  over  three  hours.The  maximum  charge  for  any
// given  24 - hour  period  is  $10.00.Assume  that  no  car  parks  for  longer  than  24  hours  at  a  time.Write  a
// program that will calculate and print the parking charges for each of three customers who parked their cars
// in this garage yesterday.You should enter the hours parked for each customer.Your program should print
// the results in  a neat tabular format, and should calculateand print the total of yesterday's receipts. The
// program  should  use  the  function  calculateCharges  to  determine  the  charge  for  each  customer.Your
// outputs should appear in the following format :

// Car      Hours    Charge
// 1        1.5      2.00
// 2        4.0      2.50
// 3        24.0     10.00
// TOTAL    29.5     14.50


#include <stdio.h>

// Define the signiture of the calculateCharges function
float calculateCharges(float hours_parked);

// Program entry function
int main(void)
{
	// Define the hours and charge for each car
	float car_one_hours, car_two_hours, car_three_hours;
	float car_one_charge, car_two_charge, car_three_charge;

	// Print the title
	puts("--========= Parking Charges =========--");

	// Get the total hours for car 1 and calculate the charges
	printf("Enter hours for car 1: ");
	scanf_s("%f", &car_one_hours);
	car_one_charge = calculateCharges(car_one_hours);

	// Get the total hours for car 2 and calculate the charges
	printf("Enter hours for car 2: ");
	scanf_s("%f", &car_two_hours);
	car_two_charge = calculateCharges(car_two_hours);

	// Get the total hours for car 3 and calculate the charges
	printf("Enter hours for car 3: ");
	scanf_s("%f", &car_three_hours);
	car_three_charge = calculateCharges(car_three_hours);

	// Print the table of cars, hours, and charges
	printf("\nCar\tHours\tCharge\n");
	printf("1\t%.1f\t%.2f\n", car_one_hours, car_one_charge);
	printf("2\t%.1f\t%.2f\n", car_two_hours, car_two_charge);
	printf("2\t%.1f\t%.2f\n", car_three_hours, car_three_charge);

	// Calculate the totals
	float total_hours = car_one_hours + car_two_hours + car_three_hours;
	float total_charge = car_one_charge + car_two_charge + car_three_charge;

	// Print the toals
	printf("TOTAL\t%.1f\t%.2f\n", total_hours, total_charge);

} // End entry function


// Define the calculateCharges function
float calculateCharges(float hours_parked)
{
	// Start with a minimum of 2$
	float total = 2.0;

	// If they have parked for more then 3 hours,
	// add the amount of hours parked (minus 3 hours)
	// times 0.5$ to the total
	if (hours_parked > 3)
		total += (hours_parked - 3.0) * 0.5;

	// If total is greater then 10,
	// set it equal to 10
	if (total > 10.0)
		total = 10.0;

	// Return total
	return total;
}