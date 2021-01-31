// I did NOTHING for you!! So there.
#include "Lecturer.h"
using namespace std;
Lecturer::Lecturer(string fName, string lName, int age, int salary) {
	this->fName = fName;
	this->lName = lName;
	this->oldAge = age;
	this->littleSalary = salary;
}
string Lecturer::getFName() const{
	return fName;
}
string Lecturer::getLName() const{
	return lName;
}
int Lecturer::getAge() const{
	return oldAge;
}
int Lecturer::getSalary() const{
	return littleSalary;
}
void Lecturer::setFName(string name) {
	fName = name;
}
void Lecturer::setLName(string name) {
	lName = name;
}
void Lecturer::setAge(int age) {
	oldAge = age;
}
void Lecturer::setSalary(int salary) {
	littleSalary = salary;
}