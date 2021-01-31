/*****************************************
** File:    Proj2Aux.h
** Project: CSCE 221 Project 2
** Author:  Bryson Mrosko
** Date:    3/5/20
** Section: 518
** E-mail:  kylemrosko@tamu.edu
**
**  C++ file:
**	Header file for Proj2Aux which is an
**  object used to read input to create an
**  AugmentedBinarySearchTree and reads and
**  calls commands on tree
**
*******************************************/

using namespace std;

#ifndef PROJ2AUX
#define PROJ2AUX

/*---------------Imported Libraries---------------*/
#include <fstream>
#include <sstream>
#include <iostream>       // For NULL
/*----------------Includes---------------------*/
#include "Exceptions.h"
#include "AugmentedBinarySearchTree.h"


class Proj2Aux
{

public:
	void DoPrintCommand(string command, int depth);
  int DoRemoveCommand(string command, int element);
  int GetMedianCommand(string command);
  int GetNthElementCommand(string command, int NthElement);
  int GetRankCommand(string command, int element);
  int GetResidualsCommand(string command);
  bool IsPerfect(string command);
  int ReadFromCommandFile(char* commandFile);
  int ReadFromInputFile(char* inputFile);

private:

	/*------------------Members-----------------------------*/
  ifstream inFile;
  AugmentedBinarySearchTree<int> m_tree;

};


#endif // PROJ2AUX
