/*

// Name: -----	ID: -----

// ************************ PART 2 ************************

//  (Package  Inheritance  Hierarchy)  Package-delivery  services,  such  as  FedEx®,  DHL®  and  UPS®,  offer  a 
// number  of  different  shipping  options, each  with  specific  costs  associated.Create  an  inheritance  hierarchy  to
// represent various types of packages.Use class Package as the base class of the hierarchy, then include classes
// TwoDayPackageand OvernightPackage that  derive  from Package.Base  class  Package  should  include  data
// members representing the name, address, city, stateand ZIP code for both the senderand the recipient of the
// package, in addition to data members that store the weight(in ounces) and cost per ounce to ship the package.
// Package’s constructor should initialize these data members.Ensure that the weightand cost per ounce contain
// positive values.Package should provide a public member function calculateCost that returns a double indicating
// the  cost  associated  with  shipping  the  package.Package’s calculateCost  function  should  determine  the  cost  by
// multiplying the weight by the cost per ounce.Derived class  TwoDayPackage should inherit the functionality of
// base class Package, but also include a data member that represents a flat fee that the shipping company charges
// for two - day - delivery service.TwoDayPackage’s constructor should receive a value to initialize this data member.
// TwoDayPackage should redefine member function calculate - Cost so that it computes the shipping cost by adding
// the flat fee to the weight - based cost calculated by base class Package’s  calculateCost function.Class
// OvernightPackage should inherit directly from class Packageand contain an additional data member
// representing  an  additional  fee  per  ounce  charged  for  overnight - delivery  service.OvernightPackage  should
// redefine  member  function  calculateCost  so  that  it  adds  the  additional  fee  per  ounce  to  the  standard  cost  per
// ounce before calculating the shipping cost.Write a test program that creates objects of each type of Package and
// tests member function calculateCost.A sample output is shown in the following figure.


#include <iostream>

#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"


// Program entry function
int main(void)
{

	// Print the title of the project (optional)
	std::cout << "-----------====== Shipping Cost Calculator ======-----------" << std::endl;


	std::cout << "Defining package 1 (weight: 10, cpo: 0.87): " << std::endl;
	Package p1 = Package("Lisa Klein", "S Broadway", "Somerville", "MA", "33333", "Bob George", "21 Pine Rd", "Cambridge", "MA", "44444", 10.0, 0.87);

	std::cout << "\nSender: " << std::endl;
	p1.printSender();

	std::cout << "\nRecipient" << std::endl;
	p1.printRecipient();

	std::cout << "\nCost: " << p1.calculateCost() << std::endl;

	std::cout << "\n\nDefining package 2 - TwoDay (weight: 10, cpo: 0.87, flatfee: 5): " << std::endl;
	TwoDayPackage p2 = TwoDayPackage("Lisa Klein", "S Broadway", "Somerville", "MA", "33333", "Bob George", "21 Pine Rd", "Cambridge", "MA", "44444", 10.0, 0.87, 5);

	std::cout << "\nSender: " << std::endl;
	p2.printSender();

	std::cout << "\nRecipient" << std::endl;
	p2.printRecipient();

	std::cout << "\nCost: " << p2.calculateCost() << std::endl;

	std::cout << "\n\nDefining package 3 - Overnight (weight: 10, cpo: 0.87, additional: 1.2): " << std::endl;
	OvernightPackage p3 = OvernightPackage("Lisa Klein", "S Broadway", "Somerville", "MA", "33333", "Bob George", "21 Pine Rd", "Cambridge", "MA", "44444", 10.0, 0.87, 1.2);

	std::cout << "\nSender: " << std::endl;
	p3.printSender();

	std::cout << "\nRecipient" << std::endl;
	p3.printRecipient();

	std::cout << "\nCost: " << p3.calculateCost() << std::endl;


} // End entry function

*/