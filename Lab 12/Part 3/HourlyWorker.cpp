/*

#include "HourlyWorker.h"

HourlyWorker::HourlyWorker(const string& first, const string& last, const string& ssn, const double wage, const double hours)
	: Employee(first, last, ssn),
	  m_wage(wage),
	  m_hours(hours)
{
}

double HourlyWorker::earnings() const
{
	if (m_wage < 40)
	{
		return m_wage * m_hours;
	}
	else {
		double difference = m_wage - 40;
		return (m_wage - difference) * m_hours + difference * m_hours * 1.5;
	}
}


*/