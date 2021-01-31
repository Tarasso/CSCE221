/**************************************************************
 * File:    PinHit.cpp
 * Project: CSCE221 - Project 4
 * Author : Bryson Mrosko
 * Date   : 28-April-2020
 * Section: 221-518
 * E-mail:  kylemrosko@tamu.edu
 *************************************************************/

#include "PinHit.h"

//Default Constructor
PinHit::PinHit()
{
  m_pin = -1;
  m_hits = 0;
}

//Contructor with given pin and frequency
PinHit::PinHit(int key, int value)
{
  m_pin = key;
  m_hits = value;
}

//Set key to new pin
void PinHit::SetKey(int pin)
{
  m_pin = pin;
}

//Return pin
int PinHit::GetKey() const
{
  return m_pin;
}

//Return hits
int PinHit::GetValue() const
{
  return m_hits;
}

//Increase hits by one
void PinHit::IncrementHits()
{
  m_hits++;
}

// Returns a postive, negative, or zero number compare hits between this and other
int PinHit::CompareTo(const PinHit& other) const
{
  int diff = GetValue() - other.GetValue();
  if (diff < 0)
    return -1;
  else if (diff > 0)
    return 1;
  else
    return 0;
}

//Checks if two pin numbers are the same
bool PinHit::operator==(const PinHit& other)
{
  if(GetKey() == other.GetKey())
    return true;
  else
    return false;
}
