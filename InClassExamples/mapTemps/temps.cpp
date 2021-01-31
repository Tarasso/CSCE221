//============================================================================
// Name        : MapExercise.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const bool DEBUG = true;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	// 1. Look at data file for a pattern
	int value;
	map < int, vector<int> > temperature;

	// 2. open file for input
	ifstream infile;
	infile.open("data.txt", ios_base::in);

	// 3. Check to see if file opened
	if (infile.fail())
	{
		cout << "The File was not successfully open." << endl;
		exit(1); // ends ENTIRE program!!!
	}

	// 4. read in the data
	while (infile >> value) // this command is IMPORTANT!
	{
		//5.	Display gathered values for verification
		//cout << value << endl;

		int stem = floor(value/10);
    int leaf = value - (stem*10);

		if (temperature.find(stem) == temperature.end())
		{
			temperature.insert(pair<int, vector<int>>(stem, vector<int>()));
			temperature[stem].push_back(value%10);
		}
		else { temperature[stem].push_back(value%10); }

	}

	cout << "\tKEY\tELEMENT\n";
	map < int, vector<int> >::iterator itr;
	for (itr = temperature.begin(); itr != temperature.end(); ++itr)
	{
		cout << '\t' << itr->first << '\t';
		sort(itr->second.begin(),itr->second.end());
		for(unsigned int i = 0; i < itr->second.size(); i++)
		 	cout << itr->second.at(i) << " ";
		cout << endl;
	}
	cout << endl;

	// 5. close the file
	infile.close();

	return 0;
}
