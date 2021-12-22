/*

#pragma once

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

*/