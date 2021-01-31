#ifndef LECTURER_H
#define LECTURER_H
#include <string>
class Lecturer
{
 private:
  // set up data members for first, last, age and salary
 std::string fName;
 std::string lName;
 int oldAge;
 int littleSalary;

 public:
  Lecturer(std::string fName, std::string lName, int oldAge, int littleSalary);

  // set up getter(s) prototypes here
  std::string getFName()const;
  std::string getLName()const;
  int getAge()const;
  int getSalary()const;
  // set up setter(s) prototypes here
  void setFName(std::string name);
  void setLName(std::string name);
  void setAge(int age);
  void setSalary(int salary);
};

#endif
