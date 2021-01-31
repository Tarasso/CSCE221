//============================================================================
// Name        : Driver.cpp
// Project     : Project 1
// Author      : Bryson Mrosko
// Date        : 2/10/2020
// UIN         : 928003182
// Section     : 518
// Email       : kylemrosko@gmail.com
// An Aggie does not lie, cheat, or steal nor tolerate those who do.
//
// This file contains the main method for this program. It creates a new Llama
// object and tests the major functions like pop, push, peek, dumb, and more.
//
//============================================================================

#include <iostream>
#include <string>
using namespace std ;

#include "Llama.h"

int main() {
   Llama<string,3> S;

   // Push a bunch of strings
   S.push("seven") ;
   S.push("six") ;
   S.push("five") ;
   S.push("four") ;
   S.push("three") ;

   S.push("two") ;
   S.push("one") ;
   S.dump() ;

   cout << "\n***************************" << endl;

   cerr << "\n***** Dump using peek *****" ;
   int size = S.size() ;
   cerr << "\nsize = " << size << endl ;

   for (int i=0 ; i < S.size() ; i++) {
      cerr << i << ": " << S.peek(i) << endl ;
   }

   // Pop some strings off
   string s1 ;

   cerr << "\n***** Pop Test *****\n" ;
   s1 = S.pop() ;
   cerr << "popped " << s1 << endl ;
   s1 = S.pop() ;
   cerr << "popped " << s1 << endl ;
   s1 = S.pop() ;
   cerr << "popped " << s1 << endl ;

   S.dump() ;  // should have "extra" nod

   cout << "\n***************************" << endl;


   // copy constructor
   Llama<string,3> W(S);

   cout << "W copied from S" << endl;

   W.dump();

   Llama<string,3> X;

   // test = operator
   X = W;

   cout << "\n***************************" << endl;

   cout << "X = W" << endl;



   X.dump();

   // test dup
   X.dup();
   cout << "X dup" << endl;
   X.dump();

   // test rot
   X.rot();
   cout << "X rot" << endl;
   X.dump();

   // test swap
   X.swap();
   cout << "X swap" << endl;
   X.dump();


   return 0 ;
}
