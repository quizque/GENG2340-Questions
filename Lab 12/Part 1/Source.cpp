/*

// Name: -----	ID: -----

// ************************ PART 1 ************************

// (Package Inheritance Hierarchy) Use  the  Package inheritance  hierarchy  you  created  for  Lab_11  
// question_2 to create a program that displays the address informationand calculates the shipping costs
// for  several  Packages.The  program  should  contain  a  vector of  Package pointers  to  objects  of  classes
// TwoDayPackageand OvernightPackage.Loop through the vector  to process the Packages
// polymorphically.For  each  Package, invoke  get functions  to  obtain  the  address  information  of  the
// senderand the recipient, then print the two addresses as they would appear on mailing labels.Also,
// call each Package’s calculate Cost member functionand print the result.Keep track of the total shipping
// cost for all Packages in the vector, and display this total when the loop terminates.A sample output is
// shown in Fig. 1.


#include <iostream>
#include <vector>

#include "Package.h"
#include "OvernightPackage.h"
#include "TwoDayPackage.h"

// Program entry function
int main(void)
{

	// Print the title of the project (optional)
	std::cout << "-----------====== Polymorphism Packages ======-----------" << std::endl;

	std::vector<Package*> packages = {
		new Package("Lisa Klein", "S Broadway", "Somerville", "MA", "33333", "Bob George", "21 Pine Rd", "Cambridge", "MA", "44444", 10.0, 0.87),
		new TwoDayPackage("Justin Cool", "S Broadway", "Somerville", "MA", "33333", "Cameron Ashbook", "21 Pine Rd", "Ontario", "MA", "44444", 10.0, 0.87, 5),
		new OvernightPackage("Robert Follow", "S Broadway", "Somerville", "MA", "33333", "Bob Smallstone", "2000 Pine Rd", "Cambridge", "MA", "44444", 10.0, 0.87, 1.2)
	};

	double total_cost = 0;

	for (int i = 0; i != packages.size(); i++)
	{
		std::cout << "\nPackage " << i + 1 << std::endl;
		std::cout << "Sender: " << std::endl;
		packages[i]->printSender();
		std::cout << "\nReciver: " << std::endl;
		packages[i]->printRecipient();
		total_cost += packages[i]->calculateCost();
		std::cout << "\nCost: " << packages[i]->calculateCost() << std::endl;
	}

	std::cout << "Total cost: " << total_cost << std::endl;

} // End entry function

*/