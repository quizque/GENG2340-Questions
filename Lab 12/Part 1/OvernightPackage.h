/*

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

*/