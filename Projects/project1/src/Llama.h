//============================================================================
// Name        : Llama.h
// Project     : Project 1
// Author      : Bryson Mrosko
// Date        : 2/10/2020
// UIN         : 928003182
// Section     : 518
// Email       : kylemrosko@gmail.com
// An Aggie does not lie, cheat, or steal nor tolerate those who do.
//
// This file contains the declarations of the functions for the Llama class
// that were defined in the Llama.cpp file. Llama is the class for the linked
// list that contains instances of the LlamaNode class. This LlamaNode class
// is templated and can contain and array of any size and any data type.
//
// This file also contains the defnition of the LlamaUnderflow error.
//
//============================================================================

#ifndef _LLAMA_H_
#define _LLAMA_H_

#include <stdexcept>
#include <string>
#include "LlamaNode.h"

using namespace std ;

// Defining the LlamaUnderflow error to be thrown when invalid calls to Llama are made
class LlamaUnderflow : public std::out_of_range {

   public:

   LlamaUnderflow(const string& what) : std::out_of_range(what) { }

} ;


template <class T, int LN_SIZE>
class Llama {

   public:
     void copy(const Llama<T, LN_SIZE> &toCopy);
   // Please find comments on functions in Llama.cpp

   Llama();
   Llama(const Llama<T,LN_SIZE>& other);
   ~Llama();

   int size();

   void dump();
   void push(const T& data);
   T pop();
   T peek(int offset) const;

   void dup() ;
   void swap() ;
   void rot() ;

   const Llama<T,LN_SIZE>& operator=(const Llama<T,LN_SIZE>& rhs) ;



   private:

   LlamaNode<T,LN_SIZE>* frontPTR;
   LlamaNode<T,LN_SIZE>* rearPTR;
   LlamaNode<T,LN_SIZE>* cursorPTR;
   LlamaNode<T,LN_SIZE>* prevPTR;

   bool hasExtraNode;
   int numElements;
   int currIndex;

   void clear();

} ;

#include "Llama.cpp"

#endif
