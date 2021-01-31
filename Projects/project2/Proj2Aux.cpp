#ifndef Proj2AuxCPP
#define Proj2AuxCPP

// Imports
#include "AugmentedBinarySearchTree.h"
#include "Exceptions.h"
#include "Proj2Aux.h"
//------------------------------------------
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//-----------------------------------------

/*
** Prints the command to be performed and calls
** the print function on m_tree
*/
void Proj2Aux::DoPrintCommand(string command, int depth)
{
  cout << command << " " << depth << ": " << endl;
  m_tree.PrintLevels(depth);
  return;
}

/*
** Prints the command to be performed and calls
** the remove function on m_tree
*/
int Proj2Aux::DoRemoveCommand(string command, int element)
{
  cout << command << " " << element << ": ";
  return m_tree.remove(element);
}

/*
** Prints the command to be performed and calls
** the median function on m_tree
*/
int Proj2Aux::GetMedianCommand(string command)
{
  int median;
  try
  {
    median = m_tree.Median();

  }
  catch(exception &e) // Catches if the tree is null
  {
    cerr << endl << e.what() << endl;
    median = -1; // Median on an empty tree returns -1
  }
  cout << command << ": ";
  return median;
}

/*
** Prints the command to be performed and calls
** the NthElement on m_tree
*/
int Proj2Aux::GetNthElementCommand(string command, int nthElement)
{
  int nth;
  try
  {
    nth = m_tree.NthElement(nthElement);
  }
  catch(exception &e) // Catches if the tree is empty or if the nth value is out of range
  {
    cerr << endl << e.what() << endl;
    nth = -1; // Returns -1 is any errors are encountered
  }
  cout << command << " " << nthElement << ": ";
  return nth;
}

/*
** Prints the command to be performed and calls
** the rank function on m_tree
*/
int Proj2Aux::GetRankCommand(string command, int element)
{
  int r;
  try
  {
    r = m_tree.Rank(element);
  }
  catch(exception &e) // Catches is the tree is empty or if an item cannot be found
  {
    cerr << endl << e.what() << endl;
    r = -1; // Returns -1 if errors are encountered
  }
  cout << command << " " << element << ": ";
  return r;
}

/*
** Prints the command to be performed and calls
** the RemoveResidue function on m_tree
*/
int Proj2Aux::GetResidualsCommand(string command)
{
  cout << command << ": ";
  return m_tree.RemoveResidue();
}

/*
** Prints the command to be performed and calls
** the IsPerfect function on m_tree
*/
bool Proj2Aux::IsPerfect(string command)
{
  bool p;
  try
  {
    p = m_tree.IsPerfect();
  }
  catch(exception &e) // Catches if the tree is empty
  {
    cerr << endl << e.what() << endl;
    p = false; // Returns false if the tree is empty
  }
  cout << command << ": ";
  return p;
}

/*
** Iterates through the command file performs commands
** on m_tree
*/
int Proj2Aux::ReadFromCommandFile(char* commandFile)
{
  // Creates and open error file
  fstream errorFile;
  errorFile.open("errors.txt",ios::out);

  // Saves original location of cerr and errorFile for fuutre reference
  streambuf* stream_buffer_cerr = cerr.rdbuf();
  streambuf* stream_buffer_errorFile = errorFile.rdbuf();

  // Redirects cerr to errorFile
  cerr.rdbuf(stream_buffer_errorFile);

  // Opens command file
  inFile.open(commandFile);
  if(!inFile.is_open()) {return 0;}
  string line;

  // Loops through each line of command file
  while(getline(inFile,line))
  {
    stringstream ss(line);
    string command;
    int param;
    // Reads in first word of each command line
    while(ss >> command)
    {
      if(command.find("#")!=string::npos) // skips any line with command character '#'
        break;
      else if(command=="PRINT") // calls DoPrintCommand
      {
        ss >> param;
        DoPrintCommand(command,param);
        cout << endl;
      }
      else if(command=="RESIDUALS") // calls GetResidualsCommand
      {
        cout << GetResidualsCommand(command) << endl;
        cout << endl;
      }
      else if(command=="RANK") // calls GetRankCommand
      {
        ss >> param;
        cout << GetRankCommand(command,param) << endl << endl;
      }
      else if(command=="NTH") // Calls GetNthElementCommand
      {
        ss >> param;
        cout << GetNthElementCommand(command,param) << endl << endl;
      }
      else if(command=="MEDIAN") // Calls GetMedianCommand
      {
        cout << GetMedianCommand(command) << endl << endl;
      }
      else if(command=="REMOVE") // calls DoRemoveCommand
      {
        ss >> param;
        int removed = DoRemoveCommand(command,param);
        if(removed == 1) // Returns a one if removed successfully
          cout << "SUCCESS" << endl << endl;
        else // Returns 0 if it was not removed
          cout << "FAILED" << endl << endl;
      }
      else if(command=="PERFECT") // calls IsPerfect
      {
        bool isP = IsPerfect(command);
        if(isP) // Returns a 1 if is perfect
          cout << "YES" << endl << endl;
        else // Returns a 0 if not perfect
          cout << "NO" << endl << endl;
      }
      else if(command=="COMPLETE") // Have not implemented complete command
      {
        cerr << endl << "COMPLETE command has not been implemented" << endl;
        break;
      }
      else // Else command not recognized
      {
        try
        {
          throw CommandNotFound(command);
        }
        catch(exception &e) // Sends error to errorFile
        {
          cerr << endl << e.what() << endl;
          break;
        }
      }
    }
  }

  cerr.rdbuf(stream_buffer_cerr); // VERY IMPORTANT: redirect cerr back to original path

  // CLose files
  inFile.close();
  errorFile.close();

  return 1;
}

int Proj2Aux::ReadFromInputFile(char* inputFile)
{
  // Open input file
  inFile.open(inputFile);
  if(!inFile.is_open())
    return 0;
  string line;
  // Loops through each line (in the case where there are multiple lines)
  while(getline(inFile,line))
  {
    int num;
    stringstream ss(line);
    // Pushes in each number one at a time
    while(ss >> num)
    {
      m_tree.insert(num);
    }
  }

  // Closes file
  inFile.close();
  
  return 1;
}

#endif
