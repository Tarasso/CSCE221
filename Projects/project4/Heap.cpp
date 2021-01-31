/**************************************************************
 * File:    Heap.cpp
 * Project: CSCE221 - Project 4
 * Author : Bryson Mrosko
 * Date   : 28-April-2020
 * Section: 221-518
 * E-mail:  kylemrosko@tamu.edu
 *************************************************************/

#ifndef HEAP_CPP_
#define HEAP_CPP_

#include "Heap.h"
#include <iostream>
#include "cmath"

	// Default constructor, create empty array and initial variables
	template<class T, int m_size>
	Heap<T, m_size>::Heap()
	{
		if(m_size <= 0)
		{
			std::cout << "Cannot construct heap" << std::endl;
		}
		m_array = new T[m_size+1];
		numPins = 0;
		currentMaxSize = m_size;
	}

	// Destructor, clear array and delete
	template<class T, int m_size>
	Heap<T, m_size>::~Heap()
	{
		clearHeap();
		delete m_array;
	}

	// Clears all items in the heap
	template<class T, int m_size>
	void Heap<T, m_size>::clearHeap()
	{
		while(numPins > 0)
			Remove();
	}

	// Copy constructor
	template<class T, int m_size>
	Heap<T, m_size>::Heap(const Heap<T, m_size>& origHeap)
	{
		m_array = new T[m_size+1];
		for(int i = 0; i < origHeap.numPins; i++)
		{
			m_array[i] = origHeap.m_array[i];
		}
		numPins = origHeap.numPins;
		currentMaxSize = origHeap.currentMaxSize;
	}

	// Checks if needle is currently in the heap
	template<class T, int m_size>
	bool Heap<T, m_size>::Contains(const T& needle) const
	{
		if(numPins == 0)
			return false;
		for(int i = 1; i < numPins; i++)
		{
			if(m_array[i] == needle)
				return true;
		}
		return false;
	}

	// Returns a pointer to the needle in the heap
	template<class T, int m_size>
	T* Heap<T, m_size>::Find(const T& needle) const
	{
		for(int i = 1; i < numPins; i++)
		{
			if(m_array[i] == needle)
			{
				T* ptr = &(m_array[i]);
				return ptr;
			}
		}
		return nullptr;
	}

	// Removes and returns a pointer to the item at the top of the heap
	// Replaces root with newest value
	template<class T, int m_size>
	T& Heap<T, m_size>::Remove()
	{
		if(numPins == 0)
		{
			std::cout << "Cannot remove empty heap" << std::endl;
		}

		T temp = m_array[1];
		m_array[1] = m_array[numPins];
		m_array[numPins] = m_array[0];
		numPins--;
		return temp;
	}

	// Adds new value to the bottom of the heap
	// If item is already in the heap, increment it's frequency
	template<class T, int m_size>
	void Heap<T, m_size>::Insert(T& insertable)
	{
		// If item is already in the heap
		if(Contains(insertable))
		{
			Find(insertable)->IncrementHits();
		}
		else
		{
			// Handles if the heap needs to be enlarged
			if(numPins == currentMaxSize-1)
			{
				resize(currentMaxSize * 2);
			}

			numPins++;
			m_array[numPins] = insertable;
		}
	}

	//Will be defined in min and max heap
	template<class T, int m_size>
	void Heap<T, m_size>::PercolateUp(int index)
	{
		return;
	}

	//Will be defined in min and max heap
	template<class T, int m_size>
	void Heap<T, m_size>::PercolateDown(int index)
	{
		return;
	}

	//Doubles the size of the array if it fills up
	template<class T, int m_size>
	void Heap<T, m_size>::resize(int newSize)
	{
		T* newArray = new T[newSize];
		for(unsigned int i = 1; i <= numPins; i++)
		{
			newArray[i] = m_array[i];
		}
		delete m_array;
		m_array = newArray;
		currentMaxSize *= 2;
	}

	//Testing function to print heap
	template<class T, int m_size>
	void Heap<T, m_size>::printHeap()
	{
		int counter = 0;
		for(unsigned int i = 0; i <= numPins; i++)
		{
			counter++;
			if(counter > 20)
				return;
			std::cout << m_array[i].GetKey() << ":" << m_array[i].GetValue() << ", ";
		}
		std::cout << std::endl;
	}


#endif /* HEAP_CPP_ */
