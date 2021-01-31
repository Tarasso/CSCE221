#include <string>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

#include "Student.h"

template <class T>
void displayStack(stack <T> *x)
{
	cout << "Displaying Stack" << endl;
	while(!x->empty())
	{
		cout << x->top() << endl;
		cout << "----" << endl;
		x->pop();
	}
}

void displayQueue(queue <Student> *x)
{
	cout << "Displaying queue" << endl;
	while(!x->empty())
	{
		cout << x->front() << endl;
		x->pop();
		cout << "----" << endl;
	}
}

int main()
{

	queue <int> demo; // notice stack is NOT in blue
	queue <Student> demo2; // custom datatype
	queue <Student> *CMSC341 = new queue <Student>; // Heap stack

	Student temp; // need a temp, can reuse over and over AFTER we push it in
	temp.Fname = "Mr";
	temp.Lname = "Lupoli";
	temp.score = 99;

	demo.push(17);
	demo2.push(Student(temp));
	CMSC341->push(Student(temp));

	Student *test = new Student("Kyle","Mrosko",100);
	CMSC341->push(*test);

	test = new Student("Blair","Lupoli",101);
	CMSC341->push(*test);

	if(demo.empty()){ cout<<"No elements"<< endl; }
	else { cout<<"The stack contains elements"<< endl; displayQueue(CMSC341);}

	/*cout<< "The size of demo is: "<< demo.size() << endl;

	cout << demo.top() << " what is at the top of the stack" << endl; // shows 17

	Student example; // need a temp, can reuse over and over
	cout << demo2.top(); // overloaded cout for Student
	example = demo2.top(); // using overloaded assignment operator for Student

	demo.pop();
	demo2.pop(); // Pop that guy!!
	CMSC341->pop();*/

	delete(CMSC341);

	return 0;

}
