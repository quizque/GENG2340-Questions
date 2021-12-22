/*

#pragma once
#include "Employee.h"

#include <string>

using namespace std;

class PieceWorker :
    public Employee
{
public:

    PieceWorker(const string& first, const string& last,
        const string& ssn, const double wage, const double pieces);

    double earnings() const override;

private:
    double m_wage;
    double m_pieces;
};

*/