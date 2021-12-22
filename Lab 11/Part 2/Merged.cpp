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

	double calculateCost();

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

	double calculateCost();

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
/// OvernightPackage.h
/// 
/// 

//#pragma once

//#include <string>
//#include "Package.h"

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

	double calculateCost();

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
/// Source.cpp
/// 
/// 

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


//#include <iostream>

//#include "Package.h"
//#include "TwoDayPackage.h"
//#include "OvernightPackage.h"


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