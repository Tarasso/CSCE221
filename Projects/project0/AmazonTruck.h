// memory leak

//============================================================================
// Name        : Package.h
// Project     : Project 0
// Author      : Bryson Mrosko
// Date        : 1/22/2020
// UIN         : 928003182
// Section     : 518
// Email       : kylemrosko@gmail.com
// An Aggie does not lie, cheat, or steal nor tolerate those who do.
//
// Amazon Truck is the class with a vector of Packages to fill the Truck
// It has methods to add packages from a .csv file and also empty the truck
//
//============================================================================

#ifndef AMAZONTRUCK_H_
#define AMAZONTRUCK_H_

#include <iostream>
#include <vector>
#include <ostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#include "Package.h"
#include "Liquid.h"

class AmazonTruck {
public:
	AmazonTruck(short v) {volumn = v; }
	~AmazonTruck() {delete truck; }

	bool isFull();
	void makeEmpty();
	float totalVolumnSoFar();
	void fillFromFile(string filename);
	void displayLastItenInTruck();

	// overloaded cout <<
	friend ostream &operator << (ostream &os, const AmazonTruck &a)
	{
		os << "Amazon Truck Contents: " << endl;
		for(unsigned int i = 0; i < a.truck->size(); i++)
		{
			os << a.truck->at(i)->toString() << endl << endl;
		}
		return os;
	}

private:

	vector <Package*> *truck = new vector <Package*>;
	short volumn;

};

//---------------------------------------------------------------
// Name: displayLastItenInTruck
// Precondition: Non-empty truck
// Postcondition: Prints information regarding the last package
//                in the truck
//---------------------------------------------------------------
void AmazonTruck::displayLastItenInTruck()
{
	cout << "Last package:" << endl << truck->back()->toString() << endl;
}

//---------------------------------------------------------------
// Name: makeEmpty
// Precondition: Non-empty truck
// Postcondition: Deletes all memory on heap containing information
//                about the packages currently in the truck
//---------------------------------------------------------------
void AmazonTruck::makeEmpty()
{
	for(unsigned int i = 0; i < truck->size(); i++)
	{
		delete truck->at(i);
	}
	delete truck;
}

//---------------------------------------------------------------
// Name: totalVolumnSoFar
// Precondition: Non-empty truck
// Postcondition: Iterates through each item in the truck,
//                calculates the volume, and returns the total
//                volume being used in the truck
//---------------------------------------------------------------
float AmazonTruck::totalVolumnSoFar()
{
	float totalVol = 0.0;
	for(unsigned int i = 0; i < truck->size(); i++)
	{
		totalVol += truck->at(i)->getDimension().getHeight() * truck->at(i)->getDimension().getWidth() * truck->at(i)->getDimension().getDepth();
	}
	return totalVol;
}

//---------------------------------------------------------------
// Name: isFull
// Precondition: None
// Postcondition: return true or false if the truck is at max capacity
//---------------------------------------------------------------
bool AmazonTruck::isFull()
{
	if(totalVolumnSoFar() >= this->volumn)
	 	return true;
	else
		return false;
}

//---------------------------------------------------------------
// Name: fillFromFile
// Precondition: .csv file to read packages from
// Postcondition: fills truck with packages
//---------------------------------------------------------------
void AmazonTruck::fillFromFile(string filename)
{
	float currVolumn = 0.0;
	ifstream file;
	string line;

	// verifies .csv file open
  file.open(filename);
  if(!file.is_open()) cout << "Could not open file" << endl;

	// loops through each line of .csv
  while(getline(file,line))
  {
		vector<string> tempPackage;
		istringstream ss(line);
		string item;

		// loops through each comma separted value and adds it to an array
		while(getline(ss,item,','))
		{
			if(item[0]==' ')
				tempPackage.push_back(item.substr(1,item.length()));
			else
				tempPackage.push_back(item);
		}

		// truck must not be full and package must have non negative dimensions
		if(!isFull() && stoi(tempPackage[4])>-1 && stoi(tempPackage[5])>-1 && stoi(tempPackage[6])>-1)
		{
			Dimension tempDimension(stoi(tempPackage[4]),stoi(tempPackage[5]),stoi(tempPackage[6]));
			currVolumn = tempDimension.getHeight()*tempDimension.getDepth()*tempDimension.getWidth();

			// if adding the next package would cause the truck to overflow, stop adding packages to the truck
			if(totalVolumnSoFar()+currVolumn > this->volumn)
			{
				break;
			}

			Address tempAddress(tempPackage[0],tempPackage[1],tempPackage[2],stoi(tempPackage[3]));

			const unsigned short PACKAGESIZE = 9;
			const unsigned short LIQUIDSIZE = 11;

			// adds package or liquid to truck depending on how many arguments are passed
			if(tempPackage.size()==LIQUIDSIZE)
			{
				truck->push_back(new Liquid(tempAddress, tempDimension, tempPackage[7], stoi(tempPackage[8]), tempPackage[9], (bool)stoi(tempPackage[10])));
			}
			else if(tempPackage.size()==PACKAGESIZE)
			{
				truck->push_back(new Package(tempAddress, tempDimension, tempPackage[7], stoi(tempPackage[8])));
			}
		}
  }
}

#endif /* AMAZONTRUCK_H_ */
