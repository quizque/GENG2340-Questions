///
///
/// Package.h
/// 
/// 

//#pragma once

#include <string>

class Package
{
public:

	explicit Package(
		std::string senderName,
		std::string senderAddress,
		std::string senderCity,
		std::string senderState,
		std::string senderZip,
		std::string recipientName,
		std::string recipientAddress,
		std::string recipientCity,
		std::string recipientState,
		std::string recipientZip,
		double weight,
		double costPerOunce
	);

	virtual double calculateCost();

	double getWeight();
	double getCostPerOunce();

	void printSender();
	void printRecipient();

private:

	std::string m_senderName;
	std::string m_senderAddress;
	std::string m_senderCity;
	std::string m_senderState;
	std::string m_senderZip;

	std::string m_recipientName;
	std::string m_recipientAddress;
	std::string m_recipientCity;
	std::string m_recipientState;
	std::string m_recipientZip;

	double m_weight;
	double m_costPerOunce;

};

///
///
/// Package.cpp
/// 
/// 

//#include "Package.h"

#include <iostream>

Package::Package(std::string senderName, std::string senderAddress, std::string senderCity, std::string senderState, std::string senderZip, std::string recipientName, std::string recipientAddress, std::string recipientCity, std::string recipientState, std::string recipientZip, double weight, double costPerOunce)
	: m_senderName(senderName),
	m_senderAddress(senderAddress),
	m_senderCity(senderCity),
	m_senderState(senderState),
	m_senderZip(senderZip),
	m_recipientName(recipientName),
	m_recipientAddress(recipientAddress),
	m_recipientCity(recipientCity),
	m_recipientState(recipientState),
	m_recipientZip(recipientZip),
	m_weight(weight),
	m_costPerOunce(costPerOunce)
{
	if (weight < 0)
	{
		std::cout << "Weight invalid, defaulting to 1..." << std::endl;
		m_weight = 1;
	}
	if (costPerOunce < 0)
	{
		std::cout << "Cost per ounce invalid, defaulting to 1..." << std::endl;
		costPerOunce = 1;
	}
}

double Package::calculateCost()
{
	return m_costPerOunce * m_weight;
}

double Package::getWeight()
{
	return m_weight;
}

double Package::getCostPerOunce()
{
	return m_costPerOunce;
}

void Package::printSender()
{
	std::cout << m_senderName << std::endl;
	std::cout << m_senderAddress << std::endl;
	std::cout << m_senderCity << ", ";
	std::cout << m_senderState << " ";
	std::cout << m_senderZip << std::endl;
}

void Package::printRecipient()
{
	std::cout << m_recipientName << std::endl;
	std::cout << m_recipientAddress << std::endl;
	std::cout << m_recipientCity << ", ";
	std::cout << m_recipientState << " ";
	std::cout << m_recipientZip << std::endl;
}

///
///
/// OvernightPackage.h
/// 
/// 

#pragma once

#include <string>
#include "Package.h"

class OvernightPackage : public Package
{
public:

	explicit OvernightPackage(
		std::string senderName,
		std::string senderAddress,
		std::string senderCity,
		std::string senderState,
		std::string senderZip,
		std::string recipientName,
		std::string recipientAddress,
		std::string recipientCity,
		std::string recipientState,
		std::string recipientZip,
		double weight,
		double costPerOunce,
		double feePerOunce
	);

	virtual double calculateCost() override;

private:

	double m_feePerOunce;
};

///
///
/// OvernightPackage.cpp
/// 
/// 

//#include "OvernightPackage.h"

OvernightPackage::OvernightPackage(std::string senderName, std::string senderAddress, std::string senderCity, std::string senderState, std::string senderZip, std::string recipientName, std::string recipientAddress, std::string recipientCity, std::string recipientState, std::string recipientZip, double weight, double costPerOunce, double feePerOunce)
	: m_feePerOunce(feePerOunce),
	Package(senderName, senderAddress, senderCity, senderState, senderZip, recipientName, recipientAddress, recipientCity, recipientState, recipientZip, weight, costPerOunce)
{
}

double OvernightPackage::calculateCost()
{
	return getCostPerOunce() * getWeight() + getWeight() * m_feePerOunce;
}

///
///
/// TwoDayPackage.h
/// 
/// 

//#pragma once

//#include "Package.h"

class TwoDayPackage : public Package
{
public:

	explicit TwoDayPackage(
		std::string senderName,
		std::string senderAddress,
		std::string senderCity,
		std::string senderState,
		std::string senderZip,
		std::string recipientName,
		std::string recipientAddress,
		std::string recipientCity,
		std::string recipientState,
		std::string recipientZip,
		double weight,
		double costPerOunce,
		double flatFee
	);

	virtual double calculateCost() override;

private:

	double m_flatFee;

};

///
///
/// TwoDayPackage.cpp
/// 
/// 

//#include "TwoDayPackage.h"

TwoDayPackage::TwoDayPackage(
	std::string senderName,
	std::string senderAddress,
	std::string senderCity,
	std::string senderState,
	std::string senderZip,
	std::string recipientName,
	std::string recipientAddress,
	std::string recipientCity,
	std::string recipientState,
	std::string recipientZip,
	double weight,
	double costPerOunce,
	double flatFee
)
	: m_flatFee(flatFee),
	Package(senderName, senderAddress, senderCity, senderState, senderZip, recipientName, recipientAddress, recipientCity, recipientState, recipientZip, weight, costPerOunce)
{
}

double TwoDayPackage::calculateCost()
{
	return getCostPerOunce() * getWeight() + m_flatFee;
}

///
///
/// Source.cpp
/// 
/// 


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

//#include "Package.h"
//#include "OvernightPackage.h"
//#include "TwoDayPackage.h"

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