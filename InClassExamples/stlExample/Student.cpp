#include <string>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

#include "Student.h"


const Student & Student::operator = (Student &source)
{
if(this == &source) // this is a self assignment checker
{ return *this; }	// returns the pointer to the current object
// otherwise copy

//new-instance now = source instance
Fname = source.Fname;
Lname = source.Lname;
score = source.score;

return *this; // returns previously empty instance
}
