#ifndef STUDENT_H
#define STUDENT_H

class Student
{
public:

	string Fname;
	string Lname;
	size_t score;

	Student() { Fname = "null"; Lname = "null"; score = 0; }
	Student(string first, string last, int s) {Fname=first; Lname=last; score=s;}

	// mutators
	void setFname(string x) { Fname = x; } // use inline when possible, no source!
	void setLname(string x) { Lname = x; }
	void setScore(size_t x) { score = x; }

	// accessors
	string getFname() { return Fname; }
	string getLname() { return Lname; }
	size_t getScore() { return score; }

	// CUSTOM overloaded operators
	const Student &operator = (Student &source);
	bool operator != (const Student &source) { return !(score == source.score); }
	bool operator < (const Student &source) { return score < source.score; }
	friend bool compare(const Student &e1, const Student &e2) { return e1.score < e2.score; }
      // COMPARE has to be a friend

	// CUSTOM overloaded streams
	//friend ostream &operator << (ostream &out, Student &x); // code in source
	//friend istream &operator >> (istream &in, Student &x);

friend ostream &operator << (ostream &out, Student &x)
{
	// out << x.getFname() << endl; --> will not work
	out << x.Fname << endl;
	out << x.Lname << endl;
	out << x.score << endl;
	return out;
}

friend istream &operator >> (istream &in, Student &x)
{
	// temp variables
	string TempF = "", TempL = "";
	int TempScore;

	cout<< "Enter First Name:" << endl;
	in >> TempF;
	cout<< "Enter Last Name:" << endl;
	in >> TempL;
	cout<< "Enter a score for this student:" << endl;
	in >> TempScore;

	x.setFname(TempF);
	x.setLname(TempL);
	x.setScore(TempScore);
	return in;
}

};


#endif
