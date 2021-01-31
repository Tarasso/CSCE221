/*******************************************************************************
** File Name: CodingStandards.cpp
** Lab 2: Coding Standars
** Name: Bryson Mrosko
** Date: 1/22/2020
** Section: 518
** Email: kylemrosko@tamu.edu
**
** This file requires input of a user's first and last name
** and prints it out. This repeats until the user choses to stop.
**
*******************************************************************************/

// needed libraries for program
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

using namespace std;

int main()
  {
    // begining of the loop
    loopin:

      // the length of the the first and last name is 10 chars long
      const int NAMELENGTH = 10;
      // the length of the full name is 20 chars long
      const int FULLNAMELENGTH = 20;

      // create char arrays for the first and last name
      char firstName[NAMELENGTH];
      char lastName[NAMELENGTH];

      // accepts first and last name from user
      printf("enter your first name:");
      cin >> firstName;
      printf("enter your last surname:");
      cin >> lastName;

      // create array for full name
      char fullName[FULLNAMELENGTH];

      // loops to add first name to full name
      for (int i = 0; i < NAMELENGTH; i++)
      {
        fullName[i] = firstName[i];
      }
      // loops to add last name to full name
      for (int i = NAMELENGTH; i < FULLNAMELENGTH; i++)
      {
        fullName[i] = lastName[i-NAMELENGTH];
      }


      printf("your full name is ");
      // loops to print out each character for full name
      for (int i = 0; i < FULLNAMELENGTH; i++)
      {
        cout << fullName[i];
      }
      printf("\n");

      system("pause");

      // prompts user if they want to run the program again
      char ans;
      printf("do it again?");
      cin >> ans;

      // loops again if yes, ends program if no
      if (ans == 'y')
      {
        goto loopin;
      }
      else
      {
        goto endin;
      }

      // ends program
      endin:
        return 0;
}
