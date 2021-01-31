 //============================================================================
 // Name        : Address.h
 // Project     : Project 0
 // Author      : Bryson Mrosko
 // Date        : 1/22/2020
 // UIN         : 928003182
 // Section     : 518
 // Email       : kylemrosko@gmail.com
 // An Aggie does not lie, cheat, or steal nor tolerate those who do.
 //
 // Address is a data type used by packages to store information
 // about a shipping address
 //
 //============================================================================


#ifndef ADDRESS_H_
#define ADDRESS_H_

#include <iostream>
using namespace std;

class Address {
public:
	Address();
	Address(string a1, string c, string st, int z);

	const string& getAddress1() const { return address1; }
	void setAddress1(const string& address1) { this->address1 = address1; }

	const string& getCity() const { return city; }
	void setCity(const string& city) { this->city = city; }

	const string& getState() const { return state; }
	void setState(const string& state) { this->state = state; }

	int getZip() const { return zip; }
	void setZip(int zip) { this->zip = zip; }

	//---------------------------------------------------------------
	// Name: toString
	// Precondition: None
	// Postcondition: Return string containing address information
	//---------------------------------------------------------------
	string toString() const
	{
		string ret = getAddress1() + ", " + getCity() + ", " + getState() + ", " + to_string(getZip());
		return ret;
	}

	// overloaded cout
	friend ostream &operator << (ostream &os, const Address &h)
	{
		os << h.getAddress1() << ", " << h.getCity() << ", " << h.getState() << ", " << h.getZip();
		return os;
	}

	// overloaded equal (filled out later)
	const Address &operator = (const Address &source);


private:
	string address1;
	string city;
	string state;
	int zip;


};

inline Address::Address(string a1, string c, string st, int z)
{
	this->address1 = a1;
	this->city = c;
	this->state = st;
	this->zip = z;

}

inline Address::Address() { }

inline const Address & Address::operator = (const Address &source)
{
	if(this == &source) // this is a self assignment checker
	{ return *this; }	// returns the pointer to the current object
	// otherwise copy

	//new-instance now = source instance
	this->address1 = source.address1;
	this->city = source.city;
	this->state = source.state;
	this->zip = source.zip;

	return *this; // returns previously empty instance
}


#endif /* ADDRESS_H_ */
