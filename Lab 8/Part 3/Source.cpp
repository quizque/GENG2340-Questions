// Name: -----	ID: -----

// ************************ PART 3 ************************

//  (Invoice Class) Create a class called Invoice that a hardware store might use to represent an invoice fo 
// an item sold at the store.An Invoice should include four data members—a part number(type string), a part
// description(type string), a quantity of the item being purchased(type int) and a price per item(type int).
// Your class should have a constructor that initializes the four data members.Provide a setand a get function
// for each data member.In addition, provide a member function named getInvoiceAmount that calculates
// the invoice amount(i.e., multiplies the quantity by the price per item), then returns the amount as an int
// value.If the quantity is not positive, it should be set to 0. If the price per item is not positive, it  should be
// set to 0. Write a test program that demonstrates class Invoice’s capabilities.


#include <iostream>

#include "Invoice.h"


// Program entry function
int main(void)
{

	// Print the title of the project (optional)
	std::cout << "-----------====== Invoice Class Demo ======-----------" << std::endl;

	std::cout << "Defining invoice1..." << std::endl;

	// Define invoice1
	Invoice invoice1 = Invoice("S_1100389", "500 Staples", 20, 5);

	// Pretty print invoice1
	invoice1.prettyPrint();

	// Get the invoice amount
	std::cout << "The invoice amount is: " << invoice1.getInvoiceAmount() << std::endl;

	std::cout << "Writing negative values to the pricePerItem and quanitity values (should end up being 0)" << std::endl;

	// Change the price per item and quanitity to an invalid number
	invoice1.setPricePerItem(-300);
	invoice1.setQuantity(-2);

	// Print the invoice to show that it set the values to 0 instead of negative numbers
	invoice1.prettyPrint();

	std::cout << "Changing all values of invoice1..." << std::endl;

	// Change all the values of invoice 1
	invoice1.setPartNumber("G_44444444");
	invoice1.setPartDescription("A tub of bananas");
	invoice1.setPricePerItem(300);
	invoice1.setQuantity(20);

	// Print all the values of invoice1 to show that it changes
	invoice1.prettyPrint();

	// Print the new invoice amount
	std::cout << "The invoice amount is: " << invoice1.getInvoiceAmount() << std::endl;

} // End entry function