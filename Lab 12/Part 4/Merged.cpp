///
///
/// CarbonFootprint.h
/// 
/// 

//#pragma once
class CarbonFootprint
{
public:
	virtual double getCarbonFootprint() = 0;
};

///
///
/// Car.h
/// 
/// 

//#pragma once

//#include "CarbonFootprint.h"

class Car : public CarbonFootprint
{
public:
	Car(double milage, double gas);

	void print() const;

	double getCarbonFootprint() override;

private:
	double m_milage;
	double m_gas;
};


///
///
/// Car.cpp
/// 
/// 

//#include "Car.h"

#include <iostream>

Car::Car(double milage, double gas)
	: m_milage(milage),
	m_gas(gas)
{
}

void Car::print() const
{
	std::cout << "The milage is: " << m_milage << std::endl;
	std::cout << "The gas is: " << m_gas << std::endl;
}

double Car::getCarbonFootprint()
{
	std::cout << "The carbon footprint for a car is: " << m_milage * m_gas << std::endl;
	return m_milage * m_gas;
}

///
///
/// Building.h
/// 
/// 

//#pragma once

//#include "CarbonFootprint.h"

class Building : public CarbonFootprint
{
public:
	Building(double height, double population);

	void printStats() const;

	double getCarbonFootprint() override;

private:
	double m_height;
	double m_population;
};


///
///
/// Building.cpp
/// 
/// 

//#include "Building.h"

//#include <iostream>

Building::Building(double height, double population)
	: m_height(height),
	m_population(population)
{
}

void Building::printStats() const
{
	std::cout << "The population is: " << m_population << std::endl;
	std::cout << "The height is: " << m_height << std::endl;
}

double Building::getCarbonFootprint()
{
	std::cout << "The carbon footprint for a building is: " << m_height * m_population << std::endl;
	return m_height * m_population;
}

///
///
/// Bicycle.h
/// 
/// 

//#pragma once

//#include "CarbonFootprint.h"

class Bicycle : public CarbonFootprint
{
public:
	Bicycle(double treads);

	void print() const;

	double getCarbonFootprint() override;

private:
	double m_treads;
};

///
///
/// Bicycle.cpp
/// 
/// 

//#include "Bicycle.h"

//#include <iostream>

Bicycle::Bicycle(double treads)
	: m_treads(treads)
{
}

void Bicycle::print() const
{
	std::cout << "The tread usage is: " << m_treads << std::endl;
}

double Bicycle::getCarbonFootprint()
{
	std::cout << "The carbon footprint for a bicycle is: " << m_treads * 0.25 << std::endl;
	return m_treads * 0.25;
}

///
///
/// Source.cpp
/// 
/// 


// Name: -----	ID: -----

// ************************ PART 4 ************************

// (CarbonFootprint Abstract Class: Polymorphism) Using an abstract class with only pure virtual functions, you can specify similar behaviors for possibly disparate classes. Governments and companies worldwide are becoming increasingly concerned with carbon footprints (annual releases of carbon dioxide into the atmosphere) from buildings burning various types of fuels for heat, vehicles burning fuels for power, and the like. Many scientists blame these greenhouse gases for the phenomenon called global warming. Create three small classes unrelated by inheritance—classes Building, Car and Bicycle. Give each class some unique appropriate attributes and behaviors that it does not have in common with other classes. Write an abstract class CarbonFootprint with only a pure virtual getCarbonFootprint method. Have each of your classes inherit from that abstract class and implement the getCarbonFootprint method to calculate an appropriate carbon footprint for that class (check out a few websites that explain how to calculate carbon footprints). Write an application that creates objects of each of the three classes, places pointers to those objects in a vector of CarbonFootprint pointers, then iterates through the vector, polymorphically invoking each object’s getCarbonFootprint method. For each object, print some identifying information and the object’s carbon footprint. A sample output is shown in Fig. 4.


#include <iostream>
#include <vector>

//#include "Bicycle.h"
//#include "Building.h"
//#include "Car.h"
//#include "CarbonFootprint.h"


// Program entry function
int main(void)
{

	// Print the title of the project (optional)
	std::cout << "-----------====== Carbon Footprint ======-----------" << std::endl;

	std::vector<CarbonFootprint*> carbonFootprints = {
		new Bicycle(0),
		new Building(30, 500),
		new Car(100, 8)
	};

	for (int i = 0; i != 3; i++)
	{
		carbonFootprints[i]->getCarbonFootprint();
	}


} // End entry function