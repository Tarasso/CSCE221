/**************************************************************
 * File:    PinHit.h
 * Project: CSCE221 - Project 4
 * Author : Bryson Mrosko
 * Date   : 28-April-2020
 * Section: 221-518
 * E-mail:  kylemrosko@tamu.edu
 *
 * PinHit class
//
// CONSTRUCTION: with no parameters or two ints
//
// ******************PUBLIC OPERATIONS*********************
// void SetKey( x )             --> sets key to x
// int GetKey()                 --> returns key
// int GetValue()               --> returns value
// void IncrementHits()         --> increases hits by one
// int CompareTo( x )           --> return this hits - x hits
 *************************************************************/

#ifndef PINHIT_H_
#define PINHIT_H_

class PinHit {

	public:

		/**********************************************************************
     * Name: PinHit (Constructor)
     * PreCondition: None.  Non parameter constructor
     *
     * PostCondition:  Creates an default PinHit with pin -1 and freq 0
     *********************************************************************/
		PinHit();

		/**********************************************************************
     * Name: PinHit (Constructor)
     * PreCondition: two ints
     *
     * PostCondition:  Creates an default PinHit with pin int1 and freq int2
     *********************************************************************/
		PinHit(int key, int value);

		/**********************************************************************
     * Name: SetKey
     * PreCondition: int pin
     *
     * PostCondition:  sets m_pin to pin
     *********************************************************************/
		void SetKey(int pin);

		/**********************************************************************
     * Name: GetKey
     * PreCondition: none
     *
     * PostCondition:  returns the pin
     *********************************************************************/
		int GetKey() const;

		/**********************************************************************
     * Name: GetValue
     * PreCondition: none
     *
     * PostCondition:  returns the number of hits
     *********************************************************************/
		int GetValue() const;

		/**********************************************************************
     * Name: IncrementHits
     * PreCondition: none
     *
     * PostCondition:  increases hits by 1
     *********************************************************************/
		void IncrementHits();

		/**********************************************************************
     * Name: CompareTo
     * PreCondition: valid PinHit param
     *
     * PostCondition:  returns the differences between this hits and other hits
     *********************************************************************/
		int CompareTo(const PinHit& other) const;

		/**********************************************************************
     * Name: ==
     * PreCondition: valid PinHit param
     *
     * PostCondition:  checks if the two pins are the same 
     *********************************************************************/
		bool operator==(const PinHit& other);

	private:

		int m_pin, m_hits;
};

#endif /* PinHit_H_ */
