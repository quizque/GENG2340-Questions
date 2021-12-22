using namespace std;

///
///
/// Employee.h
/// 
/// 

// Fig. 12.9: Employee.h
// Employee abstract base class.
//#ifndef EMPLOYEE_H
//#define EMPLOYEE_H

#include <string> // C++ standard string class

class Employee
{
public:
    Employee(const std::string&, const std::string&,
        const std::string&);
    virtual ~Employee() { } // virtual destructor

    void setFirstName(const std::string&); // set first name
    std::string getFirstName() const; // return first name

    void setLastName(const std::string&); // set last name
    std::string getLastName() const; // return last name

    void setSocialSecurityNumber(const std::string&); // set SSN
    std::string getSocialSecurityNumber() const; // return SSN

    // pure virtual function makes Employee abstract base class
    virtual double earnings() const = 0; // pure virtual
    virtual void print() const; // virtual
private:
    std::string firstName;
    std::string lastName;
    std::string socialSecurityNumber;
}; // end class Employee

//#endif // EMPLOYEE_H

/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/


///
///
/// Employee.cpp
/// 
/// 

// Fig. 12.10: Employee.cpp
// Abstract-base-class Employee member-function definitions.
// Note: No definitions are given for pure virtual functions.
#include <iostream>
//#include "Employee.h" // Employee class definition
// using namespace std;

// constructor
Employee::Employee(const string& first, const string& last,
    const string& ssn)
    : firstName(first), lastName(last), socialSecurityNumber(ssn)
{
    // empty body 
} // end Employee constructor

// set first name
void Employee::setFirstName(const string& first)
{
    firstName = first;
} // end function setFirstName

// return first name
string Employee::getFirstName() const
{
    return firstName;
} // end function getFirstName

// set last name
void Employee::setLastName(const string& last)
{
    lastName = last;
} // end function setLastName

// return last name
string Employee::getLastName() const
{
    return lastName;
} // end function getLastName

// set social security number
void Employee::setSocialSecurityNumber(const string& ssn)
{
    socialSecurityNumber = ssn; // should validate
} // end function setSocialSecurityNumber

// return social security number
string Employee::getSocialSecurityNumber() const
{
    return socialSecurityNumber;
} // end function getSocialSecurityNumber

// print Employee's information (virtual, but not pure virtual)
void Employee::print() const
{
    cout << getFirstName() << ' ' << getLastName()
        << "\nsocial security number: " << getSocialSecurityNumber();
} // end function print

/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/


 ///
 ///
 /// CommissionEmployee.h
 /// 
 /// 

 // Fig. 12.13: CommissionEmployee.h
 // CommissionEmployee class derived from Employee.
 //#ifndef COMMISSION_H
 //#define COMMISSION_H

#include <string> // C++ standard string class
//#include "Employee.h" // Employee class definition

class CommissionEmployee : public Employee
{
public:
    CommissionEmployee(const std::string&, const std::string&,
        const std::string&, double = 0.0, double = 0.0);
    virtual ~CommissionEmployee() { } // virtual destructor

    void setCommissionRate(double); // set commission rate
    double getCommissionRate() const; // return commission rate

    void setGrossSales(double); // set gross sales amount
    double getGrossSales() const; // return gross sales amount

    // keyword virtual signals intent to override
    virtual double earnings() const override; // calculate earnings
    virtual void print() const override; // print object
private:
    double grossSales; // gross weekly sales
    double commissionRate; // commission percentage
}; // end class CommissionEmployee

//#endif // COMMISSION_H

/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/


 ///
 ///
 /// CommissionEmployee.cpp
 /// 
 /// 

 // Fig. 12.14: CommissionEmployee.cpp
 // CommissionEmployee class member-function definitions.
#include <iostream>
#include <stdexcept>
//#include "CommissionEmployee.h" // CommissionEmployee class definition
using namespace std;

// constructor
CommissionEmployee::CommissionEmployee(const string& first,
    const string& last, const string& ssn, double sales, double rate)
    : Employee(first, last, ssn)
{
    setGrossSales(sales);
    setCommissionRate(rate);
} // end CommissionEmployee constructor

// set gross sales amount
void CommissionEmployee::setGrossSales(double sales)
{
    if (sales >= 0.0)
        grossSales = sales;
    else
        throw invalid_argument("Gross sales must be >= 0.0");
} // end function setGrossSales

// return gross sales amount
double CommissionEmployee::getGrossSales() const
{
    return grossSales;
} // end function getGrossSales

// set commission rate
void CommissionEmployee::setCommissionRate(double rate)
{
    if (rate > 0.0 && rate < 1.0)
        commissionRate = rate;
    else
        throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
} // end function setCommissionRate

// return commission rate
double CommissionEmployee::getCommissionRate() const
{
    return commissionRate;
} // end function getCommissionRate

// calculate earnings; override pure virtual function earnings in Employee
double CommissionEmployee::earnings() const
{
    return getCommissionRate() * getGrossSales();
} // end function earnings

// print CommissionEmployee's information
void CommissionEmployee::print() const
{
    cout << "commission employee: ";
    Employee::print(); // code reuse
    cout << "\ngross sales: " << getGrossSales()
        << "; commission rate: " << getCommissionRate();
} // end function print

/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/


///
///
/// BasePlusCommissionEmployee.h
/// 
/// 

// Fig. 12.15: BasePlusCommissionEmployee.h
// BasePlusCommissionEmployee class derived from CommissionEmployee.
//#ifndef BASEPLUS_H
//#define BASEPLUS_H

#include <string> // C++ standard string class
//#include "CommissionEmployee.h" // CommissionEmployee class definition

class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
    BasePlusCommissionEmployee(const std::string&, const std::string&,
        const std::string&, double = 0.0, double = 0.0, double = 0.0);
    virtual ~BasePlusCommissionEmployee() { } // virtual destructor

    void setBaseSalary(double); // set base salary
    double getBaseSalary() const; // return base salary

    // keyword virtual signals intent to override
    virtual double earnings() const override; // calculate earnings
    virtual void print() const override; // print object
private:
    double baseSalary; // base salary per week
}; // end class BasePlusCommissionEmployee

//#endif // BASEPLUS_H

/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/


///
///
/// BasePlusCommissionEmployee.cpp
/// 
/// 

// Fig. 12.16: BasePlusCommissionEmployee.cpp
// BasePlusCommissionEmployee member-function definitions.
#include <iostream>
#include <stdexcept>
//#include "BasePlusCommissionEmployee.h"
//using namespace std;

// constructor 
BasePlusCommissionEmployee::BasePlusCommissionEmployee(
    const string& first, const string& last, const string& ssn,
    double sales, double rate, double salary)
    : CommissionEmployee(first, last, ssn, sales, rate)
{
    setBaseSalary(salary); // validate and store base salary
} // end BasePlusCommissionEmployee constructor

// set base salary
void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
    if (salary >= 0.0)
        baseSalary = salary;
    else
        throw invalid_argument("Salary must be >= 0.0");
} // end function setBaseSalary

// return base salary
double BasePlusCommissionEmployee::getBaseSalary() const
{
    return baseSalary;
} // end function getBaseSalary

// calculate earnings;
// override virtual function earnings in CommissionEmployee
double BasePlusCommissionEmployee::earnings() const
{
    return getBaseSalary() + CommissionEmployee::earnings();
} // end function earnings

// print BasePlusCommissionEmployee's information 
void BasePlusCommissionEmployee::print() const
{
    cout << "base-salaried ";
    CommissionEmployee::print(); // code reuse
    cout << "; base salary: " << getBaseSalary();
} // end function print

/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/

///
///
/// HourlyWorker.h
/// 
/// 

//#pragma once

#include <string>

//#include "Employee.h"

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

///
///
/// HourlyWorker.cpp
/// 
/// 

//#include "HourlyWorker.h"

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

///
///
/// PieceWorker.h
/// 
/// 

//#pragma once
//#include "Employee.h"

#include <string>

//using namespace std;

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

///
///
/// PieceWorker.cpp
/// 
/// 

//#include "PieceWorker.h"

PieceWorker::PieceWorker(const string& first, const string& last, const string& ssn, const double wage, const double pieces)
    : Employee(first, last, ssn),
    m_wage(wage),
    m_pieces(pieces)
{
}

double PieceWorker::earnings() const
{
    return m_wage * m_pieces;
}


///
///
/// SalariedEmployee.h
/// 
/// 

// Fig. 12.11: SalariedEmployee.h
// SalariedEmployee class derived from Employee.
//#ifndef SALARIED_H
//#define SALARIED_H

#include <string> // C++ standard string class
//#include "Employee.h" // Employee class definition

class SalariedEmployee : public Employee
{
public:
    SalariedEmployee(const std::string&, const std::string&,
        const std::string&, double = 0.0);
    virtual ~SalariedEmployee() { } // virtual destructor

    void setWeeklySalary(double); // set weekly salary
    double getWeeklySalary() const; // return weekly salary

    // keyword virtual signals intent to override
    virtual double earnings() const override; // calculate earnings
    virtual void print() const override; // print object
private:
    double weeklySalary; // salary per week
}; // end class SalariedEmployee

//#endif // SALARIED_H

/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/


///
///
/// SalariedEmployee.cpp
/// 
/// 

// Fig. 12.12: SalariedEmployee.cpp
// SalariedEmployee class member-function definitions.
#include <iostream>
#include <stdexcept>
//#include "SalariedEmployee.h" // SalariedEmployee class definition
//using namespace std;

// constructor 
SalariedEmployee::SalariedEmployee(const string& first,
    const string& last, const string& ssn, double salary)
    : Employee(first, last, ssn)
{
    setWeeklySalary(salary);
} // end SalariedEmployee constructor

// set salary
void SalariedEmployee::setWeeklySalary(double salary)
{
    if (salary >= 0.0)
        weeklySalary = salary;
    else
        throw invalid_argument("Weekly salary must be >= 0.0");
} // end function setWeeklySalary

// return salary
double SalariedEmployee::getWeeklySalary() const
{
    return weeklySalary;
} // end function getWeeklySalary

// calculate earnings; 
// override pure virtual function earnings in Employee
double SalariedEmployee::earnings() const
{
    return getWeeklySalary();
} // end function earnings

// print SalariedEmployee's information 
void SalariedEmployee::print() const
{
    cout << "salaried employee: ";
    Employee::print(); // reuse abstract base-class print function
    cout << "\nweekly salary: " << getWeeklySalary();
} // end function print

/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/

///
///
/// Source.cpp
/// 
/// 

// Fig. 12.17: fig12_17.cpp
// Processing Employee derived-class objects individually 
// and polymorphically using dynamic binding.
#include <iostream>
#include <iomanip>
#include <vector>
// #include "Employee.h"
// #include "SalariedEmployee.h" 
// #include "CommissionEmployee.h"  
// #include "BasePlusCommissionEmployee.h" 
// #include "PieceWorker.h"
// #include "HourlyWorker.h"
// using namespace std;

void virtualViaPointer(const Employee* const); // prototype
void virtualViaReference(const Employee&); // prototype

int main()
{
    // set floating-point output formatting
    cout << fixed << setprecision(2);

    // create derived-class objects
    SalariedEmployee salariedEmployee(
        "John", "Smith", "111-11-1111", 800);
    CommissionEmployee commissionEmployee(
        "Sue", "Jones", "333-33-3333", 10000, .06);
    BasePlusCommissionEmployee basePlusCommissionEmployee(
        "Bob", "Lewis", "444-44-4444", 5000, .04, 300);
    PieceWorker pieceWorker("Jan", "Jackson", "555-55-5555", 8.0, 20);
    HourlyWorker hourylyWorker("Chris", "Hanson",
        "666-66-6666", 13.50, 56);

    cout << "Employees processed individually using static binding:\n\n";

    // output each Employee’s information and earnings using static binding
    salariedEmployee.print();
    cout << "\nearned $" << salariedEmployee.earnings() << "\n\n";
    commissionEmployee.print();
    cout << "\nearned $" << commissionEmployee.earnings() << "\n\n";
    basePlusCommissionEmployee.print();
    cout << "\nearned $" << basePlusCommissionEmployee.earnings()
        << "\n\n";

    // create vector of three base-class pointers
    vector < Employee* > employees(5);

    // initialize vector with Employees
    employees[0] = &salariedEmployee;
    employees[1] = &commissionEmployee;
    employees[2] = &basePlusCommissionEmployee;
    employees[3] = &pieceWorker;
    employees[4] = &hourylyWorker;

    cout << "Employees processed polymorphically via dynamic binding:\n\n";

    // call virtualViaPointer to print each Employee's information
    // and earnings using dynamic binding
    cout << "Virtual function calls made off base-class pointers:\n\n";

    for (const Employee* employeePtr : employees)
        virtualViaPointer(employeePtr);

    // call virtualViaReference to print each Employee's information 
    // and earnings using dynamic binding
    cout << "Virtual function calls made off base-class references:\n\n";

    for (const Employee* employeePtr : employees)
        virtualViaReference(*employeePtr); // note dereferencing
} // end main

// call Employee virtual functions print and earnings off a 
// base-class pointer using dynamic binding
void virtualViaPointer(const Employee* const baseClassPtr)
{
    baseClassPtr->print();
    cout << "\nearned $" << baseClassPtr->earnings() << "\n\n";
} // end function virtualViaPointer

// call Employee virtual functions print and earnings off a 
// base-class reference using dynamic binding
void virtualViaReference(const Employee& baseClassRef)
{
    baseClassRef.print();
    cout << "\nearned $" << baseClassRef.earnings() << "\n\n";
} // end function virtualViaReference

/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/


