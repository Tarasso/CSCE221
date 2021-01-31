//============================================================================
// Name        : Driver.cpp
// Project     : Project 0
// Author      : Bryson Mrosko
// Date        : 1/22/2020
// UIN         : 928003182
// Section     : 518
// Email       : kylemrosko@gmail.com
// An Aggie does not lie, cheat, or steal nor tolerate those who do.
//
// Driver contains the main method for this program. It creates a new AmazonTruck
// and fills it with packages from datafile.csv. After it is filled, the Last
// package in the truck is displayed. Finally, makeEmpty is called to delete
// the package memory that is stored on the heap.
//
//============================================================================

#include <iostream>
using namespace std;

#include "AmazonTruck.h"
#include "Liquid.h"
#include "Address.h"
#include "Dimension.h"

int main()
{
	AmazonTruck* fromCollegeStation = new AmazonTruck( (short int) 1664);
	fromCollegeStation->fillFromFile("datafile.csv");
	fromCollegeStation->displayLastItenInTruck();
	fromCollegeStation->makeEmpty();
	return 0;
}
