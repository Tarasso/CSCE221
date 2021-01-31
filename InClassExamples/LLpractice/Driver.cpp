/*
 * Driver.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: slupoli
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "LinkedList.h"

int main()
{
	Linked_List one;

	one.insert("Angela", 261);
	one.insert("Jack", 20);
	one.insert("Peter", 120);
	one.insert("Chris", 270);

	one.print_list();
	one.remove("Jack");
	one.print_list();
	one.remove("Angela");
	one.print_list();
	one.remove("Chris");
	one.print_list();
	one.insert("Kyle", 222);
	one.remove("Peter");
	one.insertAtFront("Lupoli", 221);
	one.print_list();

	cout << "got here" << endl;

	cout << "Front: " << one.getFront() -> name << endl;
	cout << "Rear: " << one.getRear() -> name << endl;

	one.remove("Kyle");
	one.remove("Lupoli");
	one.getFront();
	cout << "got here" << endl;

	return 0;
}
