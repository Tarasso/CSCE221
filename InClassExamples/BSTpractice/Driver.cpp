#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

    // Test program
int main( )
{
    BinarySearchTree<int> *tree = new BinarySearchTree<int>();

    tree -> insert(8);
    tree -> insert(3);
    tree -> insert(10);
    tree -> insert(1);
    tree -> insert(6);
    tree -> insert(14);
    tree -> insert(4);
    tree -> insert(7);
    tree -> insert(13);

    cout << "max: " << tree -> findMax() << endl;

    tree -> printTree();

    /*BinarySearchTree<int> t;
    int NUMS = 400000;
    const int GAP  =   3711;
    int i;

    cout << "Checking... (no more output means success)" << endl;

    for( i = GAP; i != 0; i = ( i + GAP ) % NUMS )
        t.insert( i );

    for( i = 1; i < NUMS; i+= 2 )
        t.remove( i );


    for( i = 2; i < NUMS; i+=2 )
        if( !t.contains( i ) )
            cout << "Find error1!" << endl;

    cout << "Finished testing" << endl;*/

    return 0;
}
