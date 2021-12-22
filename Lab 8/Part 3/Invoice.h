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

