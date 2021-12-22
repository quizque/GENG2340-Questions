// Name: -----	ID: -----

// ************************ PART 4 ************************

// (Employee Class) Create a class called Employee that includes three pieces of information as data members—a first name(type string), a last name(type string) and a monthly salary(type int).Your class should have a constructor that initializes the three data members.Provide a setand a get function for each data member.If the monthly salary is not positive, set it to 0. Write a test program that demonstrates class Employee’s capabilities.Create two Employee objects and display each object’s yearly salary.Then give each Employee a 10 percent raise and display each Employee’s yearly salary again.

#include <iostream>
#include "Employee.h"

// Program entry function
int main(void)
{

	// Print the title of the project (optional)
	std::cout << "-----------====== Employee Class Demo ======-----------" << std::endl;

	// Run the tests on the first account
	std::cout << "\nTesting employee1." << std::endl;
	std::cout << "Defining the first account with name '-----' and monthly salary 100000$." << std::endl;
	// Define employe1
	Employee employee1 = Employee("-----", "-----", 100000);

	std::cout << "Name of employee1: " << employee1.getFirstName() << " " << employee1.getLastName() << std::endl;
	std::cout << "Yearly salary of employee1: " << employee1.getMonthlySalary() * 12 << "$" << std::endl;

	// Run the tests on the second account
	std::cout << "\nTesting employee2." << std::endl;
	std::cout << "Defining the second account with name 'bill gates' and monthly salary -10000000$. (should give 0 as salary)" << std::endl;
	// Define employe1
	Employee employee2 = Employee("Bill", "Gates", -10000000);

	std::cout << "Name of employee2: " << employee2.getFirstName() << " " << employee2.getLastName() << std::endl;
	std::cout << "Yearly salary of employee2: " << employee2.getMonthlySalary() * 12 << "$" << std::endl;
	std::cout << "Setting salary of employee2 to 1000000$." << std::endl;
	employee2.setMonthlySalary(1000000);
	std::cout << "Yearly salary of employee2: " << employee2.getMonthlySalary() * 12 << "$" << std::endl;

	std::cout << std::endl << std::endl;

	std::cout << "Giving both employees a 10% raise..." << std::endl;
	employee1.setMonthlySalary((int)((float)employee1.getMonthlySalary() * 1.1));
	employee2.setMonthlySalary((int)((float)employee2.getMonthlySalary() * 1.1));
	std::cout << "Yearly salary of employee1: " << employee1.getMonthlySalary() * 12 << "$" << std::endl;
	std::cout << "Yearly salary of employee2: " << employee2.getMonthlySalary() * 12 << "$" << std::endl;

	std::cout << std::endl << std::endl;

	std::cout << "Changing names of employee1 to 'banana cake' and employee2 to 'ham sandwich'" << std::endl;
	employee1.setFirstName("Banana");
	employee1.setLastName("Cake");
	employee2.setFirstName("Ham");
	employee2.setLastName("Sandwich");
	std::cout << "Name of employee1: " << employee1.getFirstName() << " " << employee1.getLastName() << std::endl;
	std::cout << "Name of employee2: " << employee2.getFirstName() << " " << employee2.getLastName() << std::endl;
} // End entry function