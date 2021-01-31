/**************************************************************
 * File:    Heap.h
 * Project: CSCE221 - Project 4
 * Author : Bryson Mrosko
 * Date   : 28-April-2020
 * Section: 221-518
 * E-mail:  kylemrosko@tamu.edu
 *
 * SplayTree class
//
// CONSTRUCTION: with no parameters
//
// ******************PUBLIC OPERATIONS*********************
// void Insert( x )       --> Insert x
// T& Remove( x )         --> Remove x
// bool Contains( x )     --> Return true if x is present
// T* Find( )             --> Return top item
// void clearHeap( )      --> Removes all items in heap
// void printHeap( )      --> Print heap in order
// T* getM_Array()        --> Returns pointer to array
// int getNumPins()       --> Returns the number of pins
// int getCurrentMaxSize()--> Returns the currentMaxSize
 *************************************************************/


#ifndef HEAP_H_
#define HEAP_H_

template<class T, int m_size> class Heap{

	public:

		// required functions by UML

		/**********************************************************************
     * Name: Heap (Constructor)
     * PreCondition: None.  Non parameter constructor
     *
     * PostCondition:  Creates an empty Heap
     *********************************************************************/
		Heap();

		/**********************************************************************
     * Name: Heap (deconstructor)
     * PreCondition: None.  Non parameter constructor
     *
     * PostCondition:  Clears and deletes memory used by heap
     *********************************************************************/
		~Heap();

		/**********************************************************************
     * Name: clearHeap
     * PreCondition: None.  Non parameter constructor
     *
     * PostCondition:  Helper function to removes elements in heap
     *********************************************************************/
		void clearHeap();

		/**********************************************************************
     * Name: Heap ( Copy Constructor)
     * PreCondition: Valid heap to copy
     *
     * PostCondition:  Creates an deep copy of origHeap
     *********************************************************************/
		Heap(const Heap<T, m_size>& origHeap);

		/**********************************************************************
     * Name: Contains
     * PreCondition: T& needle to search for
     *
     * PostCondition:  return bool if found or not
     *********************************************************************/
		virtual bool Contains(const T& needle) const;

		/**********************************************************************
     * Name: Find
     * PreCondition: T& needle to search for
     *
     * PostCondition:  return T* of needle
     *********************************************************************/
		virtual T* Find(const T& needle) const;

		/**********************************************************************
     * Name: Remove
     * PreCondition: non empty heap
     *
     * PostCondition:  return T& of deleted element and replaces it with last element
     *********************************************************************/
		virtual T& Remove();

		/**********************************************************************
     * Name: Insert
     * PreCondition: T& item to insert
     *
     * PostCondition:  places item into end of heap
     *********************************************************************/
		virtual void Insert(T& insertable);

		/**********************************************************************
     * Name: PercolateUp
     * PreCondition: index to percolate on
     *
		 * Only implemented in min and max heap
		 *
     * PostCondition:  none
     *********************************************************************/
		virtual void PercolateUp(int index);

		/**********************************************************************
     * Name: PercolateDown
     * PreCondition: index to percolate on
     *
		 * Only implemented in min and max heap
		 *
     * PostCondition:  none
     *********************************************************************/
		virtual void PercolateDown(int index);

		// student-made functions below
		/**********************************************************************
     * Name: resize
     * PreCondition: a new (and larger) size
     *
     * PostCondition:  replaces array with a new array of size newSize
     *********************************************************************/
		void resize(int newSize);

		/**********************************************************************
     * Name: printHeap
     * PreCondition: none
     *
     * PostCondition:  prints heap in order
     *********************************************************************/
		void printHeap();

		// Getter functions
		T* getM_Array() {return m_array;}
		int getNumPins() {return numPins;}
		int getCurrentMaxSize() {return currentMaxSize;}


	protected:

		// UML-required member variables
		T* m_array;

		// student-made member variables
		int numPins;
		int currentMaxSize;


};

#include "Heap.cpp"
#endif /* HEAP_H_ */
