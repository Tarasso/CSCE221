// Bryson Mrosko
// UIN: 928003182
// CSCE 222-518
// 1-15-2020
// An Aggie does not lie, cheat or steal or tolerate those who do.


#include <iostream>
#include <string>

using namespace std;

#include "Lecturer.h"


int main()
{
  Lecturer Park("John", "Park", 112, 3000);
  cout << Park.getAge();
  return 0;
}
