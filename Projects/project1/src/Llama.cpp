//============================================================================
// Name        : Llama.cpp
// Project     : Project 1
// Author      : Bryson Mrosko
// Date        : 2/10/2020
// UIN         : 928003182
// Section     : 518
// Email       : kylemrosko@gmail.com
// An Aggie does not lie, cheat, or steal nor tolerate those who do.
//
// This file contains the definitions of the functions for the Llama class
// that were declared in the Llama.h file. Llama is the class for the linked
// list that contains instances of the LlamaNode class. This LlamaNode class
// is templated and can contain and array of any size and any data type.
//
//============================================================================

#ifndef _LLAMA_CPP_
#define _LLAMA_CPP_

#include "LlamaNode.h"
#include "Llama.h"
using namespace std;


//---------------------------------------------------------------
// Name: push
// Precondition: None
// Postcondition: Adds another element to the next spot in the
//                array of the most recent LlamaNode
//---------------------------------------------------------------
template <class T, int LN_SIZE>
void Llama<T, LN_SIZE>::push(const T& data)
{
  T dataCopy = data;

  // note that currIndex is the index of where the next value should be placed
  // a currIndex of -1 indicates that a LlamaNode is full and a new one needs to be created
  // note that elements in the stack are added to the array from back to front
  if(hasExtraNode)
  {
    // since the second LlamaNode is full and there is an extra node, pushes new
    // element to the extra node
    if(currIndex == -1)
    {
      currIndex = LN_SIZE - 1;
      frontPTR->arr[currIndex--]=dataCopy;
      hasExtraNode = false;
    }
    // skips the extra node and places the element in the partially filled LlamaNode
    else
    {
      frontPTR->m_next->arr[currIndex--]=dataCopy;
    }
  }
  else
  {
    // top LlamaNode full, so creates new LlamaNode and places new element in it
    if(currIndex == -1)
    {
      LlamaNode<T,LN_SIZE> *newNode = new LlamaNode<T,LN_SIZE>;
      newNode -> m_next = frontPTR;
      frontPTR = newNode;
      currIndex = LN_SIZE - 1;
    }
    frontPTR->arr[currIndex--]=dataCopy;
  }
  numElements++;
}

//---------------------------------------------------------------
// Name: dump
// Precondition: None
// Postcondition: Prints information regarding the stack like the
//                number of items, memory locations, and order of
//                elements in the stack
//---------------------------------------------------------------
template <class T, int LN_SIZE>
void Llama<T, LN_SIZE>::dump()
{
  cout << "dump" << endl;
  cout << "LN_SIZE = " << LN_SIZE << endl;
  cout << "# of items in the stack = " << size() << endl;

  // prints number of nodes created and nodesDestroyed
  frontPTR -> report();

  if(hasExtraNode)
  {
    cout << "\nThis stack has an extra node: " << frontPTR << ".\n" << endl;
  }
  else
  {
    cout << "\nThis stack does not have an extra node.\n" << endl;
  }

  cout << "Stack contents, top to bottom" << endl;

  // iterates through each LlamaNode
  for(cursorPTR = frontPTR; cursorPTR != NULL; cursorPTR = cursorPTR->m_next)
   {
     // Skip the first node if it is the "extra" node
     if(cursorPTR==frontPTR && hasExtraNode)
     {
       continue;
     }

     cout << "----- " << cursorPTR << " -----" << endl;

     // if the current LlamaNode is partially full, begin printing from the first
     // element to the end
     if(cursorPTR == frontPTR || (cursorPTR==frontPTR->m_next && hasExtraNode))
     {
       for(int i = currIndex+1; i < LN_SIZE; i++)
       {
         cout << cursorPTR -> arr[i] << endl;
       }
     }
     // prints the entire contents of the LlamaNode
     else
     {
       for(int i = 0; i < LN_SIZE; i++)
       {
         cout << cursorPTR -> arr[i] << endl;
       }
     }

   }

 cout << "----- bottom of stack -----" << endl;
}

//---------------------------------------------------------------
// Name: Peep
// Precondition: Non-empty Llama with at least one non-empty LlamaNode
// Postcondition: Returns the element that is offset positions removed
//                from the top element in the stack
//---------------------------------------------------------------
template <class T, int LN_SIZE>
T Llama<T, LN_SIZE>::peek(int offset) const
{
  // throws error if the Llama stack is empty or tries to call negative index
  if(offset > numElements || offset < 0)
  {
    throw LlamaUnderflow("Invalid index to retrieve");
  }

  int spot = 0;
  LlamaNode<T, LN_SIZE> *tempPtr = frontPTR;

  // Skip to first filled node if the first node is the "extra" node
  if(hasExtraNode)
  {
    tempPtr = frontPTR -> m_next;
  }

  // counts spots from top of stack until desired offset is reached
  // loops through each LlamaNode and each spot in each LlamaNode's array
  for(LlamaNode<T,LN_SIZE> *i = tempPtr; i != NULL; i = i -> m_next)
  {
    // begins counting from currIndex + 1 if the LlamaNode is not full
    if(i == frontPTR || (i==frontPTR->m_next && hasExtraNode))
    {
      for(int j = currIndex+1; j < LN_SIZE; j++)
      {
        if(spot++ == offset)
        {
          return i -> arr[j];
        }
      }
    }
    // begins counting from begning of array since LlamaNode is  full
    else
    {
      for(int j = 0; j < LN_SIZE; j++)
      {
        if(spot++ == offset)
        {
          return i -> arr[j];
        }
      }
    }
  }
  tempPtr = NULL;
  return NULL;
}

//---------------------------------------------------------------
// Name: Llama constructor
// Precondition: None
// Postcondition: Initializes Llama object, sets pointers to NULL,
//                and creates an initial LlamaNode object
//---------------------------------------------------------------
template <class T, int LN_SIZE>
Llama<T, LN_SIZE>::Llama(): frontPTR(NULL), rearPTR(NULL), cursorPTR(NULL), prevPTR(NULL), hasExtraNode(false), numElements(0), currIndex(LN_SIZE-1)
{
  LlamaNode<T, LN_SIZE>* initialNode = new LlamaNode<T, LN_SIZE>;
  frontPTR = initialNode;
  rearPTR = initialNode;
  frontPTR -> m_next = NULL;
  rearPTR -> m_next = NULL;
}

//---------------------------------------------------------------
// Name: Clear
// Precondition: None
// Postcondition: Helper functions used by various functions and
//                the deconstructor to release memory stored on heap
//                by LlamaNode objects
//---------------------------------------------------------------
template <class T, int LN_SIZE>
void Llama<T, LN_SIZE>::clear()
{
  // Loops through linked list to delete each LlamaNode object
  while(frontPTR != NULL)
   {
     LlamaNode<T,LN_SIZE> *toDelete = frontPTR;
     frontPTR = frontPTR -> m_next;
     delete toDelete;
   }

   // Ensure that all pointers are set back to NULL
   cursorPTR = NULL;
   prevPTR = NULL;
   frontPTR = NULL;
   rearPTR = NULL;
}

//---------------------------------------------------------------
// Name: Llama deconstructor
// Precondition: None
// Postcondition: Calls the clear function to release memory on heap
//                when the Llama object is deleted
//---------------------------------------------------------------
template <class T, int LN_SIZE>
Llama<T, LN_SIZE>::~Llama()
{
  clear();
}

//---------------------------------------------------------------
// Name: size
// Precondition: None
// Postcondition: Returns the numbers of elements in the Llama stack
//---------------------------------------------------------------
template <class T, int LN_SIZE>
int Llama<T, LN_SIZE>::size()
{
  return numElements;
}

//---------------------------------------------------------------
// Name: pop
// Precondition: Non-empty Llama stack
// Postcondition: Returns the element on the top of the Llama stack
//                and removes it from the stack
//---------------------------------------------------------------
template <class T, int LN_SIZE>
T Llama<T, LN_SIZE>::pop()
{
  // throws error if there are no items to pop
  if(numElements == 0)
  {
    throw LlamaUnderflow("No elements to pop. Empty stack.");
  }

  T toRet;

  // stores copy of element to return
  if(hasExtraNode)
  {
    toRet = frontPTR -> m_next -> arr[currIndex+1];
  }
  else
  {
    toRet = frontPTR -> arr[currIndex+1];
  }

  currIndex++;

  // Detemrines if there is now an "extra" node adter popping item
  if(currIndex == LN_SIZE - 1)
  {
    currIndex = -1;
    hasExtraNode = true;
  }

  // Detemrines if the partially filled node is <= 50% filled. Is true, then delete extra node
  if((hasExtraNode && ((LN_SIZE - (currIndex + 1)) <= (LN_SIZE / 2))) || LN_SIZE == 1)
  {
    LlamaNode<T,LN_SIZE> *tempPtr = frontPTR;
    frontPTR = frontPTR -> m_next;
    delete tempPtr;
    hasExtraNode = false;
    //tempPtr = NULL;
  }

  numElements--;

  return toRet;
}

//---------------------------------------------------------------
// Name: dup
// Precondition: Non-empty Llama stack
// Postcondition: Adds another copy of the top element to the top
//                of the stack
//                (top) A B C D -> A A B C D
//---------------------------------------------------------------
template <class T, int LN_SIZE>
void Llama<T, LN_SIZE>::dup()
{
  // Throws error is there is no element to duplicate
  if(numElements == 0)
  {
    throw LlamaUnderflow("No elements to duplicate. Empty stack.");
  }
  else
  {
    push(peek(0));
  }
}

//---------------------------------------------------------------
// Name: swap
// Precondition: Llama stack with at least 2 elements
// Postcondition: Swaps the position of the top two elements in the
//                stack
//                (top) A B C D -> B A C D
//---------------------------------------------------------------
template <class T, int LN_SIZE>
void Llama<T, LN_SIZE>::swap()
{
  // Throws error if there are not at least two elements in the stack
  if(numElements < 2)
  {
    throw LlamaUnderflow("Not enough elements to swap.");
  }
  else
  {
    T A = pop();
    T B = pop();

    push(A);
    push(B);
  }
}

//---------------------------------------------------------------
// Name: rot
// Precondition: Llama stack with at least 3 elements
// Postcondition: Rotates the position of the first three elements
//                in the stack
//                (top) A B C D -> C A B D
//---------------------------------------------------------------
template <class T, int LN_SIZE>
void Llama<T, LN_SIZE>::rot()
{
  // Throws error if there are not at least three elements in the stack
  if(numElements < 3)
  {
    throw LlamaUnderflow("Not enough elements to rotate.");
  }
  else
  {
    T A = pop();
    T B = pop();
    T C = pop();

    push(B);
    push(A);
    push(C);
  }
}

//---------------------------------------------------------------
// Name: Llama copy constructor
// Precondition: Two Llama objects must have same type and LN_SIZE
// Postcondition: Initializes new Llama node then creates a hard
//                 copy of the other Llama stack that is passed
//---------------------------------------------------------------
template <class T, int LN_SIZE>
Llama<T, LN_SIZE>::Llama(const Llama<T,LN_SIZE>& other)
{
  frontPTR = NULL;
  rearPTR = NULL;
  cursorPTR = NULL;
  prevPTR = NULL;
  hasExtraNode = false;
  numElements = 0;
  currIndex = LN_SIZE-1;

  LlamaNode<T, LN_SIZE>* initialNode = new LlamaNode<T, LN_SIZE>;
  frontPTR = initialNode;
  rearPTR = initialNode;
  frontPTR -> m_next = NULL;
  rearPTR -> m_next = NULL;

  copy(other);
}

//---------------------------------------------------------------
// Name: =
// Precondition: Two Llama objects must have same type and LN_SIZE
// Postcondition: Clear the Llama node to the left of the = then
//                creates a hard copy of the other Llama stack
//                that is assigned to the left hand side Llama
//---------------------------------------------------------------
template <class T, int LN_SIZE>
const Llama<T,LN_SIZE>& Llama<T, LN_SIZE>::operator=(const Llama<T,LN_SIZE>& rhs)
{
  if(this != &rhs)
  {
    clear();
    frontPTR = NULL;
    rearPTR = NULL;
    cursorPTR = NULL;
    prevPTR = NULL;
    hasExtraNode = false;
    numElements = 0;
    currIndex = LN_SIZE-1;

    LlamaNode<T, LN_SIZE>* initialNode = new LlamaNode<T, LN_SIZE>;
    frontPTR = initialNode;
    rearPTR = initialNode;
    frontPTR -> m_next = NULL;
    rearPTR -> m_next = NULL;
    copy(rhs);
  }
  return *this;
}

//---------------------------------------------------------------
// Name: copy
// Precondition: Two Llama objects must have same type and LN_SIZE
// Postcondition: worker function used by the = operator and the
//                copy constructor that creates a hard copy of
//                the elements in the Llama stack
//---------------------------------------------------------------
template <class T, int LN_SIZE>
void Llama<T, LN_SIZE>::copy(const Llama<T, LN_SIZE> &toCopy)
{
  // array to store elements in stack
  T elements[toCopy.numElements];
  int spot = 0;

  // iterates through each node in toCopy object
  for(LlamaNode<T, LN_SIZE> *otherCursorPtr = toCopy.frontPTR; otherCursorPtr != NULL; otherCursorPtr = otherCursorPtr -> m_next)
  {
    // skips the extra node, will be taken care of later
    if(otherCursorPtr == toCopy.frontPTR && toCopy.hasExtraNode)
    {
      continue;
    }

    // adds the elements in the partially filled LlamaNode to the array
    if(otherCursorPtr == toCopy.frontPTR || (otherCursorPtr == toCopy.frontPTR -> m_next && toCopy.hasExtraNode))
    {
      for(int i = toCopy.currIndex+1; i < LN_SIZE; i++)
      {
        elements[spot++] = otherCursorPtr -> arr[i];
      }
    }

    // adds the elements in the completly filled LlamaNode(s) to the array
    else
    {
      for(int i = 0; i < LN_SIZE; i++)
      {
        elements[spot++] = otherCursorPtr -> arr[i];
      }
    }
  }

  // pushes all elements into new Llama stack
  // iterates through the array in reverse so that the items are put in the stack correctly
  for(int i = toCopy.numElements-1; i >= 0; i--)
  {
    push(elements[i]);
  }

  // very last step is to add an extra node to begning of new Llama stack if there is one in the toCopy
  if(toCopy.hasExtraNode)
  {
    LlamaNode<T, LN_SIZE> *extraNode = new LlamaNode<T, LN_SIZE>;
    extraNode -> m_next = frontPTR;
    frontPTR = extraNode;
    hasExtraNode = true;
  }
}

#endif
