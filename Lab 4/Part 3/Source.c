// Name: -----	ID: -----

// ************************ PART 3 ************************

// (Temperature Conversions) Implement the following integer functions: 
// a) Function celsius returns the Celsius equivalent of a Fahrenheit temperature.
// b) Function fahrenheit returns the Fahrenheit equivalent of a Celsius temperature.
// c) Use these functions to write a program that prints charts showing the Fahrenheit equivalents of all Celsius
// temperatures from 0 to 100 degrees, and the Celsius equivalents of all Fahrenheit temperatures from 32
// to  212 degrees.Print the  outputs in  a  neat  tabular  format  that  minimizes  the  number  of  lines  of  output
// while remaining readable.


#include <stdio.h>

// Define the function signitures
float celsius(float fahrenheit);
float fahrenheit(float celsius);


// Program entry function
int main(void)
{
	// Print the title and table header
	puts("-----------========= Temperature Conversion Table =========----------");
	puts("    Fahrenheit    |    Celsuis   ||    Celsuis    |    Fahrenheit    ");

	// From 32 -> 212
	for (int i = 32; i <= 212; i++)
	{
		// Print the left side of the table (fahrenheit -> celsuis)
		printf("    %10d    |    %7.2f   ||", i, celsius(i));

		// If we passed 132, stop printing celsuis -> fahrenheit
		if (i > 132)
		{
			puts("");
			continue;
		}

		// Print the left side of the table (fahrenheit -> celsuis)
		// with an offset of 32
		printf("    %7d    |    %10.2f    \n", i-32, fahrenheit(i-32));
	}


} // End entry function

// Define function to convert from celsuis to fahrenheit
float celsius(float fahrenheit)
{
	return (fahrenheit - 32.0) * (5.0 / 9.0);
}

// Define function to convert from fahrenheit to celsuis
float fahrenheit(float celsius) 
{
	return (celsius * (9.0 / 5.0) ) + 32.0;
}