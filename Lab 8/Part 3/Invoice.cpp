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
