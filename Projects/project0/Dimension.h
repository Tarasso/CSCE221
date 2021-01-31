//============================================================================
 // Name        : Dimension.h
 // Project     : Project 0
 // Author      : Bryson Mrosko
 // Date        : 1/22/2020
 // UIN         : 928003182
 // Section     : 518
 // Email       : kylemrosko@gmail.com
 // An Aggie does not lie, cheat, or steal nor tolerate those who do.
 //
 // Dimension is a data type used to store height, width, and depth for
 // other packages.
 //
 //============================================================================


#ifndef DIMENSION_H_
#define DIMENSION_H_

class Dimension {
public:
	Dimension();
	Dimension(unsigned short int width, unsigned short int height, unsigned short int depth);

	unsigned short int getDepth() const { return depth; }
	void setDepth(unsigned short int depth) { this->depth = depth; }

	unsigned short int getHeight() const { return height; }
	void setHeight(unsigned short int height) { this->height = height; }

	unsigned short int getWidth() const { return width; }
	void setWidth(unsigned short int width) { this->width = width; }

	//---------------------------------------------------------------
	// Name: toString
	// Precondition: None
	// Postcondition: Return string containing dimension information
	//---------------------------------------------------------------
	string toString() const
	{
		string ret = to_string(getWidth()) + "x" + to_string(getHeight()) + "x" + to_string(getDepth());
		return ret;
	}

	// overloaded cout
	friend ostream &operator << (ostream &os, const Dimension &d)
	{
		os << d.getWidth() << "x" << d.getHeight() << "x" << d.getDepth();
		return os;
	}

	// overloaded equals
	const Dimension &operator = (const Dimension &source);


private:
	unsigned short int width;
	unsigned short int height;
	unsigned short int depth;

};

inline Dimension::Dimension() { }

inline Dimension::Dimension(unsigned short int w, unsigned short int h, unsigned short int d)
{
	this->width = w;
	this->height = h;
	this->depth = d;
}

// overloaded =
inline const Dimension & Dimension::operator = (const Dimension &source)
{
	if(this == &source) // this is a self assignment checker
	{ return *this; }	// returns the pointer to the current object
	// otherwise copy

	//new-instance now = source instance
	this->width = source.width;
	this->height = source.height;
	this->depth = source.depth;

	return *this; // returns previously empty instance
}

#endif /* DIMENSION_H_ */
