/**************************************************************
 * File:    Driver.cpp
 * Project: CSCE221 - Project 4
 * Author : Bryson Mrosko
 * Date   : 28-April-2020
 * Section: 221-518
 * E-mail:  kylemrosko@tamu.edu
 *************************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

#include "PinHit.h"
#include "Heap.h"
#include "MinHeap.h"
#include "MaxHeap.h"

// global variable for type of heap
std::string heapType = "--max";

//forward declare so I can define it below main
void printGreeting();

std::vector<PinHit> ReadPins(char* fileName, int* totalHits);

template<class T, int m_size>
Heap<T, m_size>* BuildHeap(std::vector<T> PinHits, int slots);

// provided
template<class T, int m_size>
int Hack(Heap<T, m_size>* heap, std::vector<T> PinHits, int totalHits);

int main(int argc, char* argv[])
{
	printGreeting();

	//Read in the pins
	// Keeps track of total pin entries
	int totalHits = 0;
	int* totalHitsPtr = &totalHits;

	//Fill vector with all the pins
	std::vector<PinHit> pins = ReadPins(argv[1], totalHitsPtr);

	//Build an unordered heap to store pins
	Heap<PinHit, 10000>* heap3 = BuildHeap<PinHit,10000>(pins,10000);

	//Set the heap type (--max or --min)
	heapType = argv[2];

	//Run the hack function and print how many hacked pins were found
	//This function turns the generic heap into a min or max heap
	std::cout << "Number of successfull hacks: " << Hack(heap3,pins,totalHits) << std::endl;

	//Free memory
	//delete heap3;
	//delete totalHitsPtr;
	return EXIT_SUCCESS;
}

// prints your name and section
void printGreeting()
{
	std::cout << "Bryson Mrosko, Section 518" << std::endl;
}

// from a file, read in and store pin numbers and in a vector of PinHits
std::vector<PinHit> ReadPins(char* fileName, int* totalHits)
{
	// Open and ensure that file exists
	std::fstream inFile;
	inFile.open(fileName);
	if(!inFile.is_open())
	{
		std::cout << "Could not open file" << std::endl;
		exit(1);
	}

	std::string line;
	std::vector<PinHit> pins;

	//Loop through each line
	while(getline(inFile,line))
	{
		// Verify valid pin
		bool badInput = false;
		if(line.size() != 4) // Make sure each pin has 4 characters
			badInput = true;
		for(unsigned int i = 0; i < line.size(); i++) // Make sure each character is a digit
		{
			if(!isdigit(line[i]))
				badInput = true;
		}
		//Skips bad input
		if(badInput)
			continue;

		// Increase number of pins
		(*totalHits)++;

		// Create temporary pin
		int pinNum = std::stoi(line);
		PinHit tempPin(pinNum,1);
		bool found = false;

		//Checks if pin exists, if so IncrementHits
		for(unsigned int i = 0; i < pins.size(); i++)
		{
			if(pins[i]==tempPin)
			{
				pins[i].IncrementHits();
				found = true;
				break;
			}
		}

		// If new pin, add it to vector
		if(!found)
		{
			pins.push_back(tempPin);
		}
	}

	inFile.close();
	return pins;
}

// Create heap by iterativly inserting PinHits into a heap
template<class T, int m_size>
Heap<T, m_size>* BuildHeap(std::vector<T> PinHits, int slots)
{
	Heap<T, m_size>* newHeap = new Heap<T, m_size>();
	for(unsigned int i = 0; i < PinHits.size(); i++)
	{
		newHeap->Insert(PinHits[i]);
	}
	return newHeap;
}

//provided
template<class T, int m_size>
int Hack(Heap<T, m_size>* heap, std::vector<T> PinHits, int totalHits)
{

	int UPPER_BOUND = totalHits; // used for failsafes

	/*
	* His fictional bank with fictional cards and
	* "normal pins" will allow you to incorrectly attempt
	* to access his card 3 times per hour. You have from
	* the start of the assignment to the end to hack as
	* many accounts as possible (14 days * 24 hr/day * 3
	* attempts/hr = 1008 attempts per card)
	*/
	int MAX_ATTEMPTS = 1008;

	int hackAttemptsLeft = MAX_ATTEMPTS;
	int successfulHacks = 0;

  	srand (time(NULL)); // seeds our random generator with the current time
	int randomNumHits = rand() % totalHits; // generates a random hit between 0 and total hits
	//randomNumHits = 0; // change this if you want to hardcode in your hits for a specific pin
	int curHits = 0; // our variable for crawling
	int randomIndex = -1; // the index where our new random pinhit lives
	int newHits = 0; // number of hits in new "random" pin
	int failSafe = 0; // always good to have one of these in what could be an infinite loop

	/*
	* Linearly searches through PinHits until
	* we've accrued enough hits to reach our random hits
	* which will then determine the next pin to try to hack.
	* We use newHits to make sure we don't pick a random pin
	* that's not in our heap.
	*/
	PinHit curPinHit;
	while (newHits == 0 && failSafe < UPPER_BOUND) {

		for (unsigned int i = 0; i < PinHits.size() && curHits <= randomNumHits; i++) {
			curHits += PinHits[i].GetValue();
			randomIndex = i;
		}
		// should have found the random pin by now
		curPinHit = PinHits[randomIndex];
		newHits = curPinHit.GetValue(); // make sure it's actually in our heap
		std::cout << "Random Pin: [" << curPinHit.GetKey() << ", " << curPinHit.GetValue() << "] found!" << std::endl;
		failSafe++;
	}

	// let's make a copy of the heap so we don't modify the original.
	Heap<T, m_size>* heapCopy;

	if (heapType == "--min") {
		heapCopy = new MinHeap<T, m_size>(*heap);
	} else if (heapType == "--max") {
		heapCopy = new MaxHeap<T, m_size>(*heap);
	} else {
		heapCopy = new Heap<T, m_size>(*heap);
	}

	failSafe = 0;

	PinHit defaultPin;

	// exit once hacking 10000 accounts, either a hacking prodigy or something is wrong
	int MAX_NUM_HACKS = 10000;

	while (0 < hackAttemptsLeft && successfulHacks < MAX_NUM_HACKS) {

		// grabs our root
		PinHit topOfHeap = heapCopy->Remove();
		if (topOfHeap == defaultPin)
			break;

		std::cout << std::setfill('0') << std::setw(4) << topOfHeap.GetKey() << ", " << topOfHeap.GetValue() << " another attempt" << std::endl;

		if (hackAttemptsLeft == 1)
		std::cout << std::setfill('0') << std::setw(4) << topOfHeap.GetKey() << ", " << topOfHeap.GetValue() << " our last attempt" << std::endl;

		hackAttemptsLeft--;

		// account was hacked!
		if (topOfHeap == curPinHit) {
			std::cout << "We got them!" << std::endl;
			successfulHacks++;

			// reset our heap
			if (heapType == "--min") {
				heapCopy = new MinHeap<T, m_size>(*heap);
			} else if (heapType == "--max") {
				heapCopy = new MaxHeap<T, m_size>(*heap);
			} else {
				heapCopy = new Heap<T, m_size>(*heap);
			}

			// reset
			hackAttemptsLeft = MAX_ATTEMPTS;
			randomNumHits = rand() % totalHits;
			curHits = 0;
			randomIndex = -1;
			newHits = 0;
			failSafe = 0;
			while (newHits == 0 && failSafe < UPPER_BOUND) {

				for (unsigned int i = 0; i < PinHits.size() && curHits <= randomNumHits; i++) {
					curHits += PinHits[i].GetValue();
					randomIndex = i;
				}
				// should have found the random pin by now
				curPinHit = PinHits[randomIndex];
				newHits = curPinHit.GetValue(); // make sure it's actually in our heap
				std::cout << "Random Pin: [" << std::setfill('0') << std::setw(4) << curPinHit.GetKey() << ", " << curPinHit.GetValue() << "] found!" << std::endl;
				failSafe++;
			}

			std::cout << "Valid Random Pin: " << std::setfill('0') << std::setw(4) << curPinHit.GetKey() << " found!" << std::endl;
		}
	}
	//delete heapCopy;
	return successfulHacks;

}
