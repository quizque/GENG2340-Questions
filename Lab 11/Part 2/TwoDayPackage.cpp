/*

#include "TwoDayPackage.h"

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

*/