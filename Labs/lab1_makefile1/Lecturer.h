// Bryson Mrosko
// UIN: 928003182
// CSCE 222-518
// 1-15-2020
// An Aggie does not lie, cheat or steal or tolerate those who do.


#ifndef LECTURER_H
#define LECTURER_H

#include <string>

using namespace std;

class Lecturer
{
 private:
   string first;
   string last;
   int age;
   int salary;


 public:
  Lecturer(string fName, string lName, int oldAge, int littleSalary);

  // set up getter(s) prototypes here
  string getFirst();
  void setFirst(string f);

  string getLast();
  void setLast(string l);

  int getAge();
  void setAge(int a);

  int getSalary();
  void setSalary(int s);
  // set up setter(s) prototypes here

};

#endif
