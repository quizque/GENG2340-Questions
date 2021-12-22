/*

#pragma once

#include <string>

#include "Employee.h"

using namespace std;

class HourlyWorker :
    public Employee
{
public:

    HourlyWorker(const string& first, const string& last,
        const string& ssn, const double wage, const double hours);

    double earnings() const override;

private:
    double m_wage;
    double m_hours;
};

*/