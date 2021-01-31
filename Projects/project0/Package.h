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
// Package is the parent class of all package types. Liquid is a type
// of package. Packages can be added to an Amazon Truck
//
//============================================================================

#ifndef PACKAGE_H_
#define PACKAGE_H_

#include <iostream>
#include <string>
using namespace std;

#include "Address.h"
#include "Dimension.h"

class Package {
public:
	Package();

	Package(Address &a, Dimension &d, string id, float weight);

	const Address& getAddress() const { return address; }
	void setAddress(const Address& address) { this->address = address; }

	const Dimension& getDimension() const { return dimension; }
	void setDimension(const Dimension& dimension) { this->dimension = dimension; }

	const string& getId() const { return ID; }
	void setId(const string& id) { ID = id; }

	float getWeight() const { return weight; }
	void setWeight(float weight) { this->weight = weight; }

	// overloaded cout
	friend ostream &operator << (ostream &os, const Package &p)
	{
		os << "Package ID: " << p.getId() << endl << p.getDimension() << " " << p.getWeight() << " lbs" << endl << p.getAddress();
		return os;
	}

	//---------------------------------------------------------------
	// Name: toString
	// Precondition: None
	// Postcondition: Return string containing package information
	//---------------------------------------------------------------
	 virtual string toString()
	{
		string ret = "Package ID: " + getId() + "\n" + getDimension().toString() + " " + to_string(getWeight()) + " lbs" + "\n" + getAddress().toString();
		return ret;
	}

protected:
	string ID;
	float weight;
	Dimension dimension;
	Address address;

};

// default constructor
inline Package::Package()
{
	ID = "";
	weight = 0.0;
}

inline Package::Package(Address &a, Dimension &d, string id, float weight)
{
	this->address = a;
	this->dimension = d;
	this->ID = id;
	this->weight = weight;
}

#endif /* PACKAGE_H_ */
