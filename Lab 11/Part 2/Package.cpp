/*

#include "Package.h"

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

*/