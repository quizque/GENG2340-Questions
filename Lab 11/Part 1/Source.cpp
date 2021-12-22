/*

// Name: -----	ID: -----

// ************************ PART 1 ************************

// (Overloading the Parentheses Operator) One nice example of overloading the function call operator () is to 
// allow  another  form  of  double - array  subscripting  popular  in  some  programminglanguages.Instead  of  saying
// chessBoard[row][column]  for  an  array  of  objects, overload  the  function  call  operator to  allow  the  alternate
// form  chessBoard(row, column).Create  a  class  called  DoubleSubscriptedArray.At  construction  time, the  class
// should be able to create a DoubleSubscriptedArray of any number of rowsand columns.The class should supply
// operator()  to perform double - subscripting operations.For example, in a 3 - by - 5 DoubleSubscriptedArray  called
// chessBoard, the user could write chessBoard(1, 3) to access the element at row 1 and column 3. Remember that
// operator() can receive any number of arguments.The underlying representation of the DoubleSubscriptedArray
// could  be  a  one - dimensional  array  of  integers  with  rows * columns  number  of  elements.Function  operator()
// should perform the proper pointer arithmetic to access each element of the underlying array.There should be
// two versions of operator()—one that returns int& (so that an element of a DoubleSubscriptedArray can be used
// 	as an lvalue) and one that returns  int.The class should also provide the following operators : == , != , =, << (for
// 		outputting the DoubleSubscriptedArray in rowand column format)and >> (for inputting the entire
// 			DoubleSubscriptedArray contents)


#include <iostream>

#include "DoubleSubscriptedArray.h"


// Program entry function
int main(void)
{

	// Print the title of the project (optional)
	std::cout << "-----------====== DoubleSubscriptedArray Demo ======-----------" << std::endl;


	std::cout << "Enter size x: ";
	int x;
	std::cin >> x;
	std::cout << "Enter size y: ";
	int y;
	std::cin >> y;

	DoubleSubscriptedArray d1 = DoubleSubscriptedArray(x, y);

	std::cout << "Enter each value of array: " << std::endl;
	std::cin >> d1;

	std::cout << "\nPrinting array: " << std::endl;
	std::cout << d1;

	std::cout << "Copying array into d2" << std::endl;
	DoubleSubscriptedArray d2 = d1;
	std::cout << "Printing d2" << std::endl;
	std::cout << d2;

	std::cout << "\nChecking if d1 == d2: " << (d1 == d2) << std::endl;
	std::cout << "\nChecking if d1 != d2: " << (d1 != d2) << std::endl;

} // End entry function

*/