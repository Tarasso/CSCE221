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
// Liquid is a type of package that can be added to an Amazon Truck
//
//============================================================================

#ifndef LIQUID_H_
#define LIQUID_H_

#include <iostream>
#include <string>
using namespace std;

#include "Package.h"


class Liquid : public Package {
public:
	Liquid();

	// called a parameterized constructor
	Liquid(Address a, Dimension d, string id, float weight, string type, bool f) : Package(a, d, id, weight)
	{
		this->liquidType = type;
		this->flammable = f;
	}

	bool isFlammable() const { return flammable; }
	void setFlammable(bool flammable) { this->flammable = flammable; }

	const string& getLiquidType() const { return liquidType; }
	void setLiquidType(const string& liquidType) { this->liquidType = liquidType; }

	//---------------------------------------------------------------
	// Name: toString
	// Precondition: None
	// Postcondition: Return string containing liquid information
	//---------------------------------------------------------------
	string toString()
	{
		string ret = "Package ID: " + getId() + "\n" + getDimension().toString() + " " + to_string(getWeight()) + " lbs" + "\n" + getAddress().toString() + "\n" + getLiquidType() + " ";
		(isFlammable()==true)? ret += "Flammable" : ret += "Not Flammable";
		return ret;
	}

  // overloaded cout <<
	friend ostream &operator << (ostream &os, const Liquid &l)
	{
		os << "Package ID: " << l.getId() << endl << l.getDimension() << " " << l.getWeight() << " lbs" << endl << l.getAddress() << endl << l.getLiquidType() << " ";
		(l.isFlammable() == true)? cout << "Flammable" : cout << "Not Flammable";
		return os;
	}

// data members
private:
	string liquidType;
	bool flammable;
};



#endif /* LIQUID_H_ */
