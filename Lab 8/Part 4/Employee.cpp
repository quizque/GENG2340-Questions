#include "Employee.h"

Employee::Employee(std::string _first_name, std::string _last_name, int _monthly_salary)
	: first_name(_first_name),
	  last_name(_last_name)
{
	setMonthlySalary(_monthly_salary);
}

std::string Employee::getFirstName()
{
	return first_name;
}

void Employee::setFirstName(std::string _first_name)
{
	first_name = _first_name;
}

std::string Employee::getLastName()
{
	return last_name;
}

void Employee::setLastName(std::string _last_name)
{
	last_name = _last_name;
}

int Employee::getMonthlySalary()
{
	return monthly_salary;
}

void Employee::setMonthlySalary(int _monthly_salary)
{
	monthly_salary = _monthly_salary;
	if (monthly_salary < 0)
	{
		monthly_salary = 0;
	}
}
