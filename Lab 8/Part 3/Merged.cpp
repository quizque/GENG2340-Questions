/*
///
///
/// Invoice.h
/// 
/// 

#pragma once

#include <string>

class Invoice
{
public:
	explicit Invoice(std::string _partNumber, std::string _partDescription, int _quantity, int _pricePerItem);

	// Calculate invoice ammount
	int getInvoiceAmount() const;

	// Pretty print our private varibles
	void prettyPrint() const;

	//
	// Getters and Setters
	//

	std::string getPartNumber() const;
	void setPartNumber(std::string _partNumber);

	std::string getPartDescription() const;
	void setPartDescription(std::string _partDescription);

	int getQuantity() const;
	void setQuantity(int _quantity);

	int getPricePerItem() const;
	void setPricePerItem(int _pricePerItem);


private:
	std::string partNumber;
	std::string partDescription;
	int quantity;
	int pricePerItem;
};


///
///
/// Invoice.cpp
/// 
/// 

#include "Invoice.h"

#include <iostream>

Invoice::Invoice(std::string _partNumber, std::string _partDescription, int _quantity, int _pricePerItem)
	: partNumber(_partNumber),
	  partDescription(_partDescription)
{
	// Check if price per item is less then 0
	setPricePerItem(_pricePerItem);

	// Check if quanitity is less then 0
	setQuantity(_quantity);
}

int Invoice::getInvoiceAmount() const
{
	// Return price per item multiplied by quantity
	return pricePerItem * quantity;
}

void Invoice::prettyPrint() const
{
	// Pretty print
	std::cout << "\\-- Invoice" << std::endl;
	std::cout << "    +-- partNumber: " << getPartNumber() << std::endl;
	std::cout << "    +-- partDescription: " << getPartDescription() << std::endl;
	std::cout << "    +-- quantity: " << getQuantity() << std::endl;
	std::cout << "    \\-- pricePerItem: " << getPricePerItem() << std::endl;
}

std::string Invoice::getPartNumber() const
{
	return partNumber;
}

void Invoice::setPartNumber(std::string _partNumber)
{
	partNumber = _partNumber;
}

std::string Invoice::getPartDescription() const
{
	return partDescription;
}

void Invoice::setPartDescription(std::string _partDescription)
{
	partDescription = _partDescription;
}

int Invoice::getQuantity() const
{
	return quantity;
}

void Invoice::setQuantity(int _quantity)
{
	quantity = _quantity;

	// If the quanitity is less then 0
	if (quantity < 0)
	{
		// Set quantity to 0
		quantity = 0;
	}
}

int Invoice::getPricePerItem() const
{
	return pricePerItem;
}

void Invoice::setPricePerItem(int _pricePerItem)
{
	pricePerItem = _pricePerItem;

	// If the price per time is zero
	if (pricePerItem < 0)
	{
		// Set the price per item to be zero
		pricePerItem = 0;
	}
}

///
///
/// Source.cpp
/// 
/// 

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
*/