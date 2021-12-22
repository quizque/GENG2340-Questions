#pragma once

#include <string>

class Employee
{
public:
	explicit Employee(std::string _first_name, std::string _last_name, int _monthly_salary);

	// Getters and Setters
	std::string getFirstName();
	void setFirstName(std::string _first_name);

	std::string getLastName();
	void setLastName(std::string _last_name);

	int getMonthlySalary();
	void setMonthlySalary(int _salary);

private:
	std::string first_name;
	std::string last_name;
	int monthly_salary;
};

