/*
 * LinkedList.h
 *
 *  Created on: Jan 30, 2019
 *      Author: slupoli
 */

// HEADER

#ifndef _LINKED_LINKED_H_
#define _LINKED_LINKED_H_

struct NODE
{
	string name;
	int test_grade;
	NODE * link;
};


class Linked_List
{
public:
	Linked_List();
	~Linked_List();
	void insert(string n, int score);
	void insertAtFront(string n, int score);
	void remove(string target);
	void print_list();
	NODE* getFront();
	NODE* getRear();


private:
	bool isEmpty();
	NODE *FRONT_ptr, *REAR_ptr, *CURSOR, *INSERT, *PREVIOUS_ptr;
};


#endif
