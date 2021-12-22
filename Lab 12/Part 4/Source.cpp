/*

// Name: -----	ID: -----

// ************************ PART 4 ************************

// (CarbonFootprint Abstract Class: Polymorphism) Using an abstract class with only pure virtual functions, you can specify similar behaviors for possibly disparate classes. Governments and companies worldwide are becoming increasingly concerned with carbon footprints (annual releases of carbon dioxide into the atmosphere) from buildings burning various types of fuels for heat, vehicles burning fuels for power, and the like. Many scientists blame these greenhouse gases for the phenomenon called global warming. Create three small classes unrelated by inheritance—classes Building, Car and Bicycle. Give each class some unique appropriate attributes and behaviors that it does not have in common with other classes. Write an abstract class CarbonFootprint with only a pure virtual getCarbonFootprint method. Have each of your classes inherit from that abstract class and implement the getCarbonFootprint method to calculate an appropriate carbon footprint for that class (check out a few websites that explain how to calculate carbon footprints). Write an application that creates objects of each of the three classes, places pointers to those objects in a vector of CarbonFootprint pointers, then iterates through the vector, polymorphically invoking each object’s getCarbonFootprint method. For each object, print some identifying information and the object’s carbon footprint. A sample output is shown in Fig. 4.


#include <iostream>
#include <vector>

#include "Bicycle.h"
#include "Building.h"
#include "Car.h"
#include "CarbonFootprint.h"


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

*/