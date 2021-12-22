/*

#include "OvernightPackage.h"

OvernightPackage::OvernightPackage(std::string senderName, std::string senderAddress, std::string senderCity, std::string senderState, std::string senderZip, std::string recipientName, std::string recipientAddress, std::string recipientCity, std::string recipientState, std::string recipientZip, double weight, double costPerOunce, double feePerOunce)
	: m_feePerOunce(feePerOunce),
	  Package(senderName, senderAddress, senderCity, senderState, senderZip, recipientName, recipientAddress, recipientCity, recipientState, recipientZip, weight, costPerOunce)
{
}

double OvernightPackage::calculateCost()
{
	return getCostPerOunce() * getWeight() + getWeight() * m_feePerOunce;
}

*/