// Bryson Mrosko
// UIN: 928003182
// CSCE 222-518
// 1-15-2020
// An Aggie does not lie, cheat or steal or tolerate those who do.


// I did NOTHING for you!! So there.

// what includes (if any) go here
#include "Lecturer.h"
#include <string>

using namespace std;

// I should ONLY see functions here!!!

// constructor

Lecturer::Lecturer(string fName, string lName, int oldAge, int littleSalary)
{
  first = fName;
  last = lName;
  age = oldAge;
  salary = littleSalary;
}

// getters/setters next

string Lecturer::getFirst()
{
  return first;
}

void Lecturer::setFirst(string f)
{
  first = f;
}

string Lecturer::getLast()
{
  return last;
}

void Lecturer::setLast(string l)
{
  last = l;
}

int Lecturer::getAge()
{
  return age;
}

void Lecturer::setAge(int a)
{
  age = a;
}

int Lecturer::getSalary()
{
  return salary;
}

void Lecturer::setSalary(int s)
{
  salary = s;
}
